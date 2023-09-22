#include "json_parser.h"

JsonParser::JsonParser(const string &data)
{
    m_valid = false;
    m_data = data;

    parse();
}

JsonParser::~JsonParser()
{
}

bool JsonParser::parse()
{
    bool result = true;

    try
    {
        m_jsonValue = TC_Json::getValue(m_data);
    }
    catch (...)
    {
        result = false;
    }

    if (!result)
    {
        m_valid = false;
        return false;
    }

    m_jsonValueObj = JsonValueObjPtr::dynamicCast(m_jsonValue);

    m_valid = true;

    return result;
}

bool JsonParser::getValue(const string &key, int &value)
{
    if (!m_valid)
    {
        return false;
    }

    JsonInput::readJson(value, m_jsonValueObj->value[key], false);

    return true;
}

bool JsonParser::getValue(const string &key, double &value)
{
    if (!m_valid)
    {
        return false;
    }

    JsonInput::readJson(value, m_jsonValueObj->value[key], false);

    return true;
}

bool JsonParser::getValue(const string &key, char &value)
{
    if (!m_valid)
    {
        return false;
    }

    JsonInput::readJson(value, m_jsonValueObj->value[key], false);

    return true;
}

bool JsonParser::getValue(const string &key, string &value)
{
    if (!m_valid)
    {
        return false;
    }

    JsonInput::readJson(value, m_jsonValueObj->value[key], false);

    return true;
}

bool JsonParser::getValue(const string &key, map<string, string> &value)
{
    if (!m_valid)
    {
        return false;
    }

    JsonInput::readJson(value, m_jsonValueObj->value[key], false);

    return true;
}

bool JsonParser::getValue(const string &key, vector<map<string, string>> &value)
{
    if (!m_valid)
    {
        return false;
    }

    JsonInput::readJson(value, m_jsonValueObj->value[key], false);

    return true;
}