#include "json.h"

Json::Json()
{
    m_jsonValueObj = new JsonValueObj();
}

Json::~Json()
{
}

bool Json::addValue(const string &key, int value)
{
    m_jsonValueObj->value.insert(make_pair(key, JsonOutput::writeJson(value)));

    return true;
}

bool Json::addValue(const string &key, double value)
{
    m_jsonValueObj->value.insert(make_pair(key, JsonOutput::writeJson(value)));

    return true;
}

bool Json::addValue(const string &key, const string &value)
{
    m_jsonValueObj->value.insert(make_pair(key, JsonOutput::writeJson(value)));

    return true;
}

bool Json::addValue(const string &key, const map<string, string> &value)
{
    m_jsonValueObj->value.insert(make_pair(key, JsonOutput::writeJson(value)));

    return true;
}

bool Json::addValue(const string &key, const vector<map<string, string>> &value)
{
    m_jsonValueObj->value.insert(make_pair(key, JsonOutput::writeJson(value)));

    return true;
}

bool Json::writeToString(string &result)
{
    TC_Json::writeValue(m_jsonValueObj, result);

    return true;
}

string Json::writeToString()
{
    return TC_Json::writeValue(m_jsonValueObj);
}