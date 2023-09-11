#include "GoodsTarsImp.h"
#include "servant/Application.h"
#include "plugin/lua/api.h"
#include "plugin/lua/func.h"

using namespace std;

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

    cout << result << endl;

    return result;
}

tars::Int32 GoodsTarsImp::doCommon(const GoodsApp::CommonReq &req, GoodsApp::CommonRsp &rsp, tars::TarsCurrentPtr current)
{
    ApiProtocol protocol;

    // 初始化协议
    if (!protocol.init(Get_Goods_Info))
    {
        cout << "init failed..." << endl;
        
        rsp.errCode = "-1";
        rsp.errMsg = "初始化协议失败";
        rsp.seqId = req.seqId;

        return -1;
    }

    // 获取协议内请求分组
    vector<string> groups;
    protocol.getGroups(groups);

    cout << "group size: " << groups.size() << endl;

    // 根据分组，分别组装请求入参并打包
    for (size_t i = 0; i < groups.size(); i++)
    {
        string grp_name = groups[i];
        cout << "main: " << i << "," << grp_name << endl;

        vector<string> requests;
        // 获取请求
        protocol.getRequests(grp_name, requests);

        // 将模拟数据转换为lua表数据格式
        string clientRequest = testPackGetGoodsInfo();

        for (size_t j = 0; j < requests.size(); j++)
        {
            // 模拟结果集
            map<string, string> dataset;
            dataset["goods_id"] = "G001";
            dataset["goods_label"] = "食品";

            cout << "main: " << i << "," << requests[j] << endl;
            // 打包请求
            string grpReq = protocol.packRequest(requests[j], clientRequest, dataset);
            cout << "request: " << grpReq << endl;

            // 发送请求
        }
    }

    rsp.errCode = "0";
    rsp.errMsg = "OK";
    rsp.seqId = req.seqId;

    return 0;
}