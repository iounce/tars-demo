#ifndef __JSON_PARSER_H
#define __JSON_PARSER_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "util/tc_json.h"
#include "util/tc_common.h"
#include "tup/TarsJson.h"

using namespace std;
using namespace tars;

class JsonParser
{
public:
    JsonParser(const string &data);
    ~JsonParser();
public:
    bool parse();

    bool getValue(const string &key, int &value);
    bool getValue(const string &key, double &value);
    bool getValue(const string &key, char &value);
    bool getValue(const string &key, string &value);
    bool getValue(const string &key, vector<string> &value);
    bool getValue(const string &key, map<string, string> &value);
    bool getValue(const string &key, vector<map<string, string>> &value);
private:
    bool m_valid;
    string m_data;
    JsonValuePtr m_jsonValue;
    JsonValueObjPtr m_jsonValueObj;
    JsonValueArrayPtr m_jsonValueArray;
};

#endif