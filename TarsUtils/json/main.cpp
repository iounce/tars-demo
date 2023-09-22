#include "json.h"
#include "json_parser.h"

int main()
{
    if (1)
    {
        Json json;

        json.addValue("id", "123123");
        json.addValue("price", 111.22);
        json.addValue("qty", 200);

        vector<map<string, string>> result;

        map<string, string> errmsg;
        errmsg["code"] = "0";
        errmsg["msg"] = "OK";
        
        result.push_back(errmsg);

        json.addValue("data", result);

        cout << json.writeToString() << endl;
    }

    if (0)
    {
        string reqData = "{\"result\":[{\"code\":\"0\",\"msg\":\"\"}],\"data\":[{\"id\":\"0001\",\"name\":\"Jack\"},{\"id\":\"0002\",\"name\":\"Anna\"}]}";

        JsonParser parser(reqData);

        vector<map<string, string>> result;
        parser.getValue("result", result);
        cout << "result:" << TC_Common::tostr(result) << endl;

        vector<map<string, string>> data;
        parser.getValue("data", data);
        cout << "data:" << TC_Common::tostr(data) << endl;
    }

    if (0)
    {
        string reqData = "{\"id\":\"60001\",\"qty\": 100,\"price\": 11.23,\"flag\": 1}";
        JsonParser parser(reqData);

        string clientId = "";
        char flag;

        parser.getValue("id", clientId);
        parser.getValue("flag", flag);

        cout << "flag: " << flag << ", id: " << clientId << endl;

        double price = 0.0;
        int qty = 0;

        parser.getValue("price", price);
        parser.getValue("qty", qty);

        cout << "price: " << price << ", qty: " << qty << endl;
    }

    getchar();

    return 0;
}