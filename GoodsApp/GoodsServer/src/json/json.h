#ifndef __JSON_H
#define __JSON_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "util/tc_json.h"
#include "util/tc_common.h"
#include "tup/TarsJson.h"

using namespace std;
using namespace tars;

class Json
{
public:
    Json();
    ~Json();
public:
    bool addValue(const string &key, int value);
    bool addValue(const string &key, double value);
    bool addValue(const string &key, const string &value);
    bool addValue(const string &key, const map<string, string> &value);
    bool addValue(const string &key, const vector<map<string, string>> &value);
    
    bool writeToString(string &result);
    string writeToString();
private:
    JsonValueObjPtr m_jsonValueObj;
};

#endif