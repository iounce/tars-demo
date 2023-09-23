#include <iostream>
#include "GoodsTars.h"

using namespace std;
using namespace GoodsApp;

typedef tars::TC_AutoPtr<Communicator> CommunicatorPtr;

int main(int argc, char *argv[])
{
	CommonReq req;
	CommonRsp rsp;
	
	req.seqId = "1";
	req.cmd = "100";
	std::string data = "{\"IoSectionId\":\"G0001\",\"IoGoodsName\":\"Bread\"}";
	req.data.assign(data.begin(), data.end());

	CommunicatorPtr comm = new Communicator();
	
	GoodsTarsPrx prx = comm->stringToProxy<GoodsTarsPrx>("GoodsApp.GoodsServer.GoodsTarsObj@tcp -h 172.25.0.3 -t 60000 -p 24249 -e 0");
	prx->doCommon(req, rsp);

	std::string reqData = "";
	reqData.assign(req.data.begin(), req.data.end());

	std::string rspData = "";
	rspData.assign(rsp.data.begin(), rsp.data.end());
	
	cout << "req: " << reqData << endl;
	cout << "rsp: " << rspData << endl;
	
	getchar();

	return 0;
}