#include "GoodsServer.h"
#include "GoodsTarsImp.h"

using namespace std;

GoodsServer g_app;

/////////////////////////////////////////////////////////////////
void
GoodsServer::initialize()
{
    //initialize application here:
    //...

    addServant<GoodsTarsImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".GoodsTarsObj");
}
/////////////////////////////////////////////////////////////////
void
GoodsServer::destroyApp()
{
    //destroy application here:
    //...
}
/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////
