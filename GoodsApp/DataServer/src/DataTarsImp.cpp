#include "DataTarsImp.h"
#include "servant/Application.h"

using namespace std;

//////////////////////////////////////////////////////
void DataTarsImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void DataTarsImp::destroy()
{
    //destroy servant here:
    //...
}

tars::Int32 DataTarsImp::doData(const GoodsApp::DataReq & req, GoodsApp::DataRsp &rsp, tars::TarsCurrentPtr current)
{
    TLOG_DEBUG("request: " << req.writeToJsonString() << endl;);
    
    string goodsName = "";
    auto &reqFields = req.data;

    if (reqFields.find("goods_name") != reqFields.end())
    {
        goodsName = reqFields.at("goods_name");
    }

    if (req.cmd == "100000")
    {
        rsp.errCode = "0";
        rsp.data["goods_id"] = "G001";
        rsp.data["goods_label"] = "Food";
    }
    else if (req.cmd == "100001")
    {
        rsp.errCode = "0";
        rsp.data["section_id"] = "S001";
        rsp.data["goods_name"] = goodsName;
        rsp.data["goods_price"] = "11.23";
        rsp.data["goods_amount"] = "1000";
    }
    else
    {
        rsp.errCode = "-1";
        rsp.errMsg = "Invalid command";
    }

    rsp.seqId = req.seqId;

    return 0;
}