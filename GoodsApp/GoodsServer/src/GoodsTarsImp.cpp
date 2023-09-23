#include "GoodsTarsImp.h"
#include "servant/Application.h"
#include "plugin/lua/api.h"
#include "plugin/lua/func.h"
#include "DataTars.h"
#include "json/json.h"
#include "json/json_parser.h"

using namespace std;
using namespace tars;
using namespace GoodsApp;

//////////////////////////////////////////////////////
void GoodsTarsImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void GoodsTarsImp::destroy()
{
    //destroy servant here:
    //...
}

static string testPackGetGoodsInfo()
{
    map<string, string> req;
    req["IoSectionId"] = "G0001";
    req["IoGoodsName"] = "面包";
    req["IoGoodsId"] = "";

    size_t index = 0;
    string result = "{";
    for (auto item : req)
    {
        result += "[\"";
        result += item.first;
        result += "\"]";

        result += "=";

        result += "\"";
        result += item.second;
        result += "\"";

        if (index != req.size() - 1)
        {
            result += ",";
        }

        index++;
    }

    result += "}";

    TLOG_DEBUG(result << endl;);

    return result;
}

tars::Int32 GoodsTarsImp::doCommon(const GoodsApp::CommonReq &req, GoodsApp::CommonRsp &rsp, tars::TarsCurrentPtr current)
{
    TLOG_DEBUG("request: " << req.writeToJsonString() << endl;);

    ApiProtocol protocol;

    // 初始化协议
    if (!protocol.init(Get_Goods_Info))
    {
        TLOG_DEBUG("init failed..." << endl;);
        
        rsp.errCode = "-1";
        rsp.errMsg = "初始化协议失败";
        rsp.seqId = req.seqId;

        return -1;
    }

    string obj = "GoodsApp.DataServer.DataTarsObj";
    GoodsApp::DataTarsPrx prx = Application::getCommunicator()->stringToProxy<GoodsApp::DataTarsPrx>(obj);

    // 获取协议内请求分组
    vector<string> groups;
    protocol.getGroups(groups);

    TLOG_DEBUG("group size: " << groups.size() << endl;);

    // 根据分组，分别组装请求入参并打包
    for (size_t i = 0; i < groups.size(); i++)
    {
        string grp_name = groups[i];
        TLOG_DEBUG("main: " << i << "," << grp_name << endl;);

        vector<string> requests;
        // 获取请求
        protocol.getRequests(grp_name, requests);

        // 将模拟数据转换为lua表数据格式
        string clientRequest = testPackGetGoodsInfo();

        map<string, string> dataset;
        dataset["goods_id"] = "G001";
        dataset["goods_label"] = "食品";
        dataset["goods_id"] = "";

        for (size_t j = 0; j < requests.size(); j++)
        {
            TLOG_DEBUG("main: " << i << "," << requests[j] << endl;);
            // 打包请求
            string grpReq = protocol.packRequest(requests[j], clientRequest, dataset);
            TLOG_DEBUG("request: " << grpReq << endl;);

            JsonValueObjPtr jsonData = JsonValueObjPtr::dynamicCast(TC_Json::getValue(grpReq));

            map<string, string> reqData;
            for (auto item : jsonData->value)
            {
                reqData[item.first] = item.second;
            }

            // 发送请求
            DataReq dataReq;
            DataRsp dataRsp;

            int funcNo = 0;

            JsonInput::readJson(funcNo, jsonData->get("func_no"), false);

            dataReq.data = reqData;
            dataReq.cmd = to_string(funcNo);
            dataReq.seqId = dataReq.cmd + to_string(j + 1);
            
            prx->doData(dataReq, dataRsp);

            TLOG_DEBUG("request: " << dataReq.writeToJsonString() << endl;);
            TLOG_DEBUG("response: " << dataRsp.writeToJsonString() << endl;);

            if (dataRsp.errCode == "0")
            {
                dataset = dataRsp.data;
            }
        }
    }

    rsp.errCode = "0";
    rsp.errMsg = "OK";
    rsp.seqId = req.seqId;

    string rspData = "{\"IoSectionId\":\"G0001\",\"IoGoodsName\":\"Bread\",\"IoSectionId\":\"G0001\"}";
    rsp.data.assign(rspData.begin(), rspData.end());

    return 0;
}