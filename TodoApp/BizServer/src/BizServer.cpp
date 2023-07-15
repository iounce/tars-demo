#include "BizServer.h"
#include "TodoTarsObjImp.h"

using namespace std;

BizServer g_app;

/////////////////////////////////////////////////////////////////
void
BizServer::initialize()
{
    //initialize application here:
    //...

    addServant<TodoTarsObjImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".TodoTarsObjObj");
}
/////////////////////////////////////////////////////////////////
void
BizServer::destroyApp()
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
