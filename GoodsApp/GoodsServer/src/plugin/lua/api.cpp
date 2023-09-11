#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <windows.h>
#include "func.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filewritestream.h"

#include "api.h"

using namespace std;
using namespace rapidjson;


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
        cout << "findModule failed" << endl;
        return false;
    }

    if (!findLoadProtocol())
    {
        cout << "findLoadProtocol failed" << endl;
        return false;
    }

    if (!findGetGroups())
    {
        cout << "findGetGroups failed" << endl;
        return false;
    }

    if (!findGetRequests())
    {
        cout << "findGetRequests failed" << endl;
        return false;
    }

    if (!findPackRequest())
    {
        cout << "findPackRequest failed" << endl;
        return false;
    }

    if (!loadProtocol())
    {
        cout << "loadProtocol failed" << endl;
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
    return string("protocol_") + to_string(funcNo) + string(".lua");
}

bool ApiProtocol::findModule(const string &name)
{
    cout << "module: " << name << endl;

    int ret = luaL_loadfile(m_state, name.c_str());
    if (ret != LUA_OK)
    {
        std::string error = lua_tostring(m_state, -1);
        cout << error << endl;

        cout << "luaL_loadfile failed" << endl;

        return false;
    }

    luaL_openlibs(m_state);

    ret = lua_pcall(m_state, 0, 0, 0);
    if (ret != LUA_OK)
    {
        std::string error = lua_tostring(m_state, -1);
        cout << error << endl;

        cout << "lua_pcall failed" << endl;

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
        cout << ret << "|" << error << endl;

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
        cout << error << endl;

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
    
    cout << "groups: " << data << endl;

    Document doc;

    doc.Parse(data.c_str());

    if (!doc.IsArray())
    {
        return false;
    }

    Value &array = doc.GetArray();
    for (int i = 0; i < array.Size(); i++)
    {
        groups.push_back(array[i].GetString());
    }

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
        cout << error << endl;

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

    cout << "getRequests: " << grp_name << ":" << data << endl;

    Document doc;

    doc.Parse(data.c_str());

    if (!doc.IsArray())
    {
        return false;
    }

    Value &array = doc.GetArray();
    for (int i = 0; i < array.Size(); i++)
    {
        requests.push_back(array[i].GetString());
    }

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
        cout << error << endl;

        return "";
    }

    string data = "";

    if (lua_isstring(m_state, -1))
    {
        data = lua_tostring(m_state, -1);
    }

    cout << "packRequest: " << data << endl;

    return data;
}

string packGetGoodsInfo()
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

int main()
{
    {
        ApiProtocol protocol;

        if (!protocol.init(Get_Goods_Info))
        {
            cout << "init failed..." << endl;
            return 0;
        }

        vector<string> groups;
        protocol.getGroups(groups);

        map<string, string> dataset;
        dataset["goods_id"] = "G001";
        dataset["goods_label"] = "食品";

        cout << "group size: " << groups.size() << endl;

        for (size_t i = 0; i < groups.size(); i++)
        {
            string grp_name = groups[i];
            cout << "main: " << i << "," << grp_name << endl;

            vector<string> requests;
            protocol.getRequests(grp_name, requests);

            string clientRequest = packGetGoodsInfo();

            for (size_t j = 0; j < requests.size(); j++)
            {
                cout << "main: " << i << "," << requests[j] << endl;
                protocol.packRequest(requests[j], clientRequest, dataset);
            }
        }
    }

    getchar();

    return 0;
}