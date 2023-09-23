#include "DataServer.h"
#include "DataTarsImp.h"

using namespace std;

DataServer g_app;

/////////////////////////////////////////////////////////////////
void
DataServer::initialize()
{
    //initialize application here:
    //...

    addServant<DataTarsImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".DataTarsObj");
}
/////////////////////////////////////////////////////////////////
void
DataServer::destroyApp()
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
