#ifndef __API_H
#define __API_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "func.h"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

using namespace std;

class ApiProtocol
{
public:
    ApiProtocol();
    ~ApiProtocol();
public:
    bool init(int funcNo);
    void release();
public:
    string getModuleName(int funcNo);
    bool findModule(const string &name);
    bool findLoadProtocol();
    bool findGetGroups();
    bool findGetRequests();
    bool findPackRequest();

    bool loadProtocol();

    bool getGroups(string &data);
    bool getGroups(vector<string> &groups);

    bool getRequests(const string &grp_name, string &data);
    bool getRequests(const string &grp_name, vector<string> &requests);

    string packRequest(const string &reqName, const string &clientReq, map<string, string> &dataset);
private:
    lua_State *m_state;
};

#endif // __API_H