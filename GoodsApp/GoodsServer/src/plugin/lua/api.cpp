#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "func.h"
#include "servant/Application.h"
#include "util/tc_json.h"
#include "util/tc_encoder.h"
#include "util/tc_common.h"

#include "api.h"
#include "json/json.h"
#include "json/json_parser.h"

using namespace std;
using namespace tars;

ApiProtocol::ApiProtocol()
{
    m_state = nullptr;
}

ApiProtocol::~ApiProtocol()
{
    release();
}

bool ApiProtocol::init(int funcNo)
{
    m_state = luaL_newstate();
    if (m_state == nullptr)
    {
        return false;
    }

    if (!findModule(getModuleName(funcNo)))
    {
        TLOG_DEBUG("findModule failed" << endl;);
        return false;
    }

    if (!findLoadProtocol())
    {
        TLOG_DEBUG("findLoadProtocol failed" << endl;);
        return false;
    }

    if (!findGetGroups())
    {
        TLOG_DEBUG("findGetGroups failed" << endl;);
        return false;
    }

    if (!findGetRequests())
    {
        TLOG_DEBUG("findGetRequests failed" << endl;);
        return false;
    }

    if (!findPackRequest())
    {
        TLOG_DEBUG("findPackRequest failed" << endl;);
        return false;
    }

    if (!loadProtocol())
    {
        TLOG_DEBUG("loadProtocol failed" << endl;);
        return false;
    }

    return true;
}

void ApiProtocol::release()
{
    if (m_state != nullptr)
    {
        lua_close(m_state);
        m_state = nullptr;
    }
}

string ApiProtocol::getModuleName(int funcNo)
{
    //TLOG_DEBUG("exe path: " << TC_File::extractFilePath(TC_File::getExePath()) << endl;);
    string luaPath = TC_File::extractFilePath(TC_File::getExePath());
    return luaPath + string("protocol_") + to_string(funcNo) + string(".lua");
}

bool ApiProtocol::findModule(const string &name)
{
    TLOG_DEBUG("module: " << name << endl;);

    luaL_openlibs(m_state);

    int ret = luaL_dofile(m_state, name.c_str());
    if (ret != LUA_OK)
    {
        std::string error = lua_tostring(m_state, -1);
        TLOG_DEBUG( error << endl;);

        TLOG_DEBUG("luaL_dofile failed" << endl;);

        return false;
    }

    return true;
}

bool ApiProtocol::findLoadProtocol()
{
    return true;
}

bool ApiProtocol::findGetGroups()
{
    return true;
}

bool ApiProtocol::findGetRequests()
{
    return true;
}

bool ApiProtocol::findPackRequest()
{
    return true;
}

bool ApiProtocol::loadProtocol()
{
    lua_getglobal(m_state, "load_protocol");
            
    int ret = lua_pcall(m_state, 0, 1, 0);
    if (ret != LUA_OK)
    {
        std::string error = lua_tostring(m_state, -1);
        TLOG_DEBUG( ret << "|" << error << endl;);

        return false;
    }

    bool result = true;

    if (lua_isboolean(m_state, -1))
    {
        result = lua_toboolean(m_state, -1);
    }

    return result;
}

bool ApiProtocol::getGroups(string &data)
{
    lua_getglobal(m_state, "get_groups");

    int ret = lua_pcall(m_state, 0, 1, 0);
    if (ret != LUA_OK)
    {
        std::string error = lua_tostring(m_state, -1);
        TLOG_DEBUG( error << endl;);

        return false;
    }

    if (lua_isstring(m_state, -1))
    {
        data = lua_tostring(m_state, -1);
    }

    return !data.empty();
}

bool ApiProtocol::getGroups(vector<string> &groups)
{
    string data = "";
    if (!getGroups(data))
    {
        return false;
    }
    
    TLOG_DEBUG("getGroups: " << data << endl;);

    JsonParser parser(data);
    parser.getValue("Groups", groups);

    TLOG_DEBUG("getGroups: " << TC_Common::tostr(groups) << endl;);

    return (groups.size() > 0);
}

bool ApiProtocol::getRequests(const string &grp_name, string &data)
{
    lua_getglobal(m_state, "get_requests");
    lua_pushstring(m_state, grp_name.c_str());

    int ret = lua_pcall(m_state, 1, 1, 0);
    if (ret != LUA_OK)
    {
        std::string error = lua_tostring(m_state, -1);
        TLOG_DEBUG( error << endl;);

        return false;
    }

    if (lua_isstring(m_state, -1))
    {
        data = lua_tostring(m_state, -1);
    }

    return !data.empty();
}

bool ApiProtocol::getRequests(const string &grp_name, vector<string> &requests)
{
    string data = "";
    if (!getRequests(grp_name, data))
    {
        return false;
    }

    TLOG_DEBUG("getRequests: " << grp_name << ":" << data << endl;);

    JsonParser parser(data);
    parser.getValue(grp_name, requests);

    TLOG_DEBUG("getRequests: " << grp_name << "|" << TC_Common::tostr(requests) << endl;);

    return (requests.size() > 0);
}

string ApiProtocol::packRequest(const string &reqName, const string &clientReq, map<string, string> &dataset)
{
    lua_getglobal(m_state, "pack_request");
    lua_pushstring(m_state, reqName.c_str());
    lua_pushstring(m_state, clientReq.c_str());

    lua_newtable(m_state);
    for (auto item : dataset)
    {
        lua_pushstring(m_state, item.first.c_str());
        lua_pushstring(m_state, item.second.c_str());
        lua_settable(m_state, -3);
    }

    int ret = lua_pcall(m_state, 3, 1, 0);
    if (ret != LUA_OK)
    {
        std::string error = lua_tostring(m_state, -1);
        TLOG_DEBUG( error << endl;);

        return "";
    }

    string data = "";

    if (lua_isstring(m_state, -1))
    {
        data = lua_tostring(m_state, -1);
    }

    TLOG_DEBUG("packRequest: " << TC_Encoder::utf82gbk(data) << endl;);

    return data;
}

// string packGetGoodsInfo()
// {
//     map<string, string> req;
//     req["IoSectionId"] = "G0001";
//     req["IoGoodsName"] = "面包";
//     req["IoGoodsId"] = "";

//     size_t index = 0;
//     string result = "{";
//     for (auto item : req)
//     {
//         result += "[\"";
//         result += item.first;
//         result += "\"]";

//         result += "=";

//         result += "\"";
//         result += item.second;
//         result += "\"";

//         if (index != req.size() - 1)
//         {
//             result += ",";
//         }

//         index++;
//     }

//     result += "}";

//     TLOG_DEBUG( result << endl;);

//     return result;
// }

// int main()
// {
//     {
//         ApiProtocol protocol;

//         if (!protocol.init(Get_Goods_Info))
//         {
//             TLOG_DEBUG("init failed..." << endl;);
//             return 0;
//         }

//         vector<string> groups;
//         protocol.getGroups(groups);

//         map<string, string> dataset;
//         dataset["goods_id"] = "G001";
//         dataset["goods_label"] = "食品";

//         TLOG_DEBUG("group size: " << groups.size() << endl;);

//         for (size_t i = 0; i < groups.size(); i++)
//         {
//             string grp_name = groups[i];
//             TLOG_DEBUG("main: " << i << "," << grp_name << endl;);

//             vector<string> requests;
//             protocol.getRequests(grp_name, requests);

//             string clientRequest = packGetGoodsInfo();
//             TLOG_DEBUG("req: " << clientRequest << endl;);

//             for (size_t j = 0; j < requests.size(); j++)
//             {
//                 TLOG_DEBUG("main: " << i << "," << requests[j] << endl;);
//                 protocol.packRequest(requests[j], clientRequest, dataset);
//             }
//         }
//     }

//     getchar();

//     return 0;
// }