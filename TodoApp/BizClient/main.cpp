#include <iostream>
#include "servant/Communicator.h"
#include "TodoTarsObj.h"

using namespace std;
using namespace TodoApp;
using namespace tars;

int main(int argc,char ** argv)
{
    Communicator comm;

    try
    {
        apiPrx prx;
        comm.stringToProxy("TodoApp.BizServer.TodoTarsObjObj@tcp -h 172.25.0.5 -t 60000 -p 14295 -e 0", prx);

        try
        {
            TodoReq req;
            req.seqId = "1";
            req.userId = "15900010001";

            Todo todo;
            todo.title = "打篮球";
            todo.content = "明天晚上19:00去体育馆打篮球";
            req.todoList.push_back(todo);

            TodoRsp rsp;

            int iRet = prx->addTodo(req, rsp);

            cout << "iRet: " << iRet << " req: " << req.writeToJsonString() << " rsp: "<< rsp.writeToJsonString() << endl;

        }
        catch(exception &ex)
        {
            cerr << "ex:" << ex.what() << endl;
        }
        catch(...)
        {
            cerr << "unknown exception." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << endl;
    }

    return 0;
}