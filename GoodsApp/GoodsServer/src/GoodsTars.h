// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 3.0.15.
// **********************************************************************

#ifndef __GOODSTARS_H_
#define __GOODSTARS_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"
#include "promise/promise.h"
#include "servant/Application.h"


namespace GoodsApp
{
    struct CommonReq : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "GoodsApp.CommonReq";
        }
        static string MD5()
        {
            return "909fa710c0682c1e7c40db3da603f61d";
        }
        CommonReq()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            seqId = "";
            cmd = "";
            data.clear();
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            if (seqId != "")
            {
                _os.write(seqId, 1);
            }
            if (cmd != "")
            {
                _os.write(cmd, 2);
            }
            if (data.size() > 0)
            {
                _os.write(data, 3);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(seqId, 1, false);
            _is.read(cmd, 2, false);
            _is.read(data, 3, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["seqId"] = tars::JsonOutput::writeJson(seqId);
            p->value["cmd"] = tars::JsonOutput::writeJson(cmd);
            p->value["data"] = tars::JsonOutput::writeJson(data);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(seqId,pObj->value["seqId"], false);
            tars::JsonInput::readJson(cmd,pObj->value["cmd"], false);
            tars::JsonInput::readJson(data,pObj->value["data"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(seqId,"seqId");
            _ds.display(cmd,"cmd");
            _ds.display(data,"data");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(seqId, true);
            _ds.displaySimple(cmd, true);
            _ds.displaySimple(data, false);
            return _os;
        }
    public:
        std::string seqId;
        std::string cmd;
        vector<tars::Char> data;
    };
    inline bool operator==(const CommonReq&l, const CommonReq&r)
    {
        return l.seqId == r.seqId && l.cmd == r.cmd && l.data == r.data;
    }
    inline bool operator!=(const CommonReq&l, const CommonReq&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const CommonReq&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,CommonReq&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct CommonRsp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "GoodsApp.CommonRsp";
        }
        static string MD5()
        {
            return "89cc1c18e3ca1ff27a650fe29ef5788f";
        }
        CommonRsp()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            errCode = "";
            errMsg = "";
            seqId = "";
            count = 0;
            data.clear();
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            if (errCode != "")
            {
                _os.write(errCode, 1);
            }
            if (errMsg != "")
            {
                _os.write(errMsg, 2);
            }
            if (seqId != "")
            {
                _os.write(seqId, 3);
            }
            if (count != 0)
            {
                _os.write(count, 4);
            }
            if (data.size() > 0)
            {
                _os.write(data, 5);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(errCode, 1, false);
            _is.read(errMsg, 2, false);
            _is.read(seqId, 3, false);
            _is.read(count, 4, false);
            _is.read(data, 5, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["errCode"] = tars::JsonOutput::writeJson(errCode);
            p->value["errMsg"] = tars::JsonOutput::writeJson(errMsg);
            p->value["seqId"] = tars::JsonOutput::writeJson(seqId);
            p->value["count"] = tars::JsonOutput::writeJson(count);
            p->value["data"] = tars::JsonOutput::writeJson(data);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(errCode,pObj->value["errCode"], false);
            tars::JsonInput::readJson(errMsg,pObj->value["errMsg"], false);
            tars::JsonInput::readJson(seqId,pObj->value["seqId"], false);
            tars::JsonInput::readJson(count,pObj->value["count"], false);
            tars::JsonInput::readJson(data,pObj->value["data"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(errCode,"errCode");
            _ds.display(errMsg,"errMsg");
            _ds.display(seqId,"seqId");
            _ds.display(count,"count");
            _ds.display(data,"data");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(errCode, true);
            _ds.displaySimple(errMsg, true);
            _ds.displaySimple(seqId, true);
            _ds.displaySimple(count, true);
            _ds.displaySimple(data, false);
            return _os;
        }
    public:
        std::string errCode;
        std::string errMsg;
        std::string seqId;
        tars::Int32 count;
        vector<tars::Char> data;
    };
    inline bool operator==(const CommonRsp&l, const CommonRsp&r)
    {
        return l.errCode == r.errCode && l.errMsg == r.errMsg && l.seqId == r.seqId && l.count == r.count && l.data == r.data;
    }
    inline bool operator!=(const CommonRsp&l, const CommonRsp&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const CommonRsp&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,CommonRsp&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }


    /* callback of async proxy for client */
    class apiPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~apiPrxCallback(){}
        virtual void callback_doCommon(tars::Int32 ret,  const GoodsApp::CommonRsp& rsp)
        { throw std::runtime_error("callback_doCommon() override incorrect."); }
        virtual void callback_doCommon_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_doCommon_exception() override incorrect."); }
        virtual void callback_doCommon(tars::Int32 ret, GoodsApp::CommonRsp&&  rsp)
        { callback_doCommon(ret, rsp); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __api_all[]=
            {
                "doCommon"
            };
            auto it = _msg_->response->status.find("TARS_FUNC");
            pair<string*, string*> r = equal_range(__api_all, __api_all+1, (it==_msg_->response->status.end())?_msg_->request.sFuncName:it->second);
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __api_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_doCommon_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    GoodsApp::CommonRsp rsp;
                    _is.read(rsp, 2, true);
                    ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
                    if (_pSptd_ && _pSptd_->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                            _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "doCommon", 0, _trace_param_, "");
                    }

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(_msg_->response->context);

                    callback_doCommon(_ret, std::move(rsp));

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<apiPrxCallback> apiPrxCallbackPtr;

    //callback of promise async proxy for client
    class apiPrxCallbackPromise: public tars::ServantProxyCallback
    {
    public:
        virtual ~apiPrxCallbackPromise(){}
    public:
        struct PromisedoCommon: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            GoodsApp::CommonRsp rsp;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< apiPrxCallbackPromise::PromisedoCommon > PromisedoCommonPtr;

        apiPrxCallbackPromise(const tars::Promise< apiPrxCallbackPromise::PromisedoCommonPtr > &promise)
        : _promise_doCommon(promise)
        {}
        
        virtual void callback_doCommon(const apiPrxCallbackPromise::PromisedoCommonPtr &ptr)
        {
            _promise_doCommon.setValue(ptr);
        }
        virtual void callback_doCommon_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:doCommon_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_doCommon.setException(tars::copyException(str, ret));
        }

    protected:
        tars::Promise< apiPrxCallbackPromise::PromisedoCommonPtr > _promise_doCommon;

    public:
        virtual int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __api_all[]=
            {
                "doCommon"
            };

            pair<string*, string*> r = equal_range(__api_all, __api_all+1, string(_msg_->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __api_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_doCommon_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);

                    apiPrxCallbackPromise::PromisedoCommonPtr ptr = new apiPrxCallbackPromise::PromisedoCommon();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                        _is.read(ptr->rsp, 2, true);
                    }
                    catch(std::exception &ex)
                    {
                        callback_doCommon_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_doCommon_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = _msg_->response->context;

                    callback_doCommon(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<apiPrxCallbackPromise> apiPrxCallbackPromisePtr;

    /* callback of coroutine async proxy for client */
    class apiCoroPrxCallback: public apiPrxCallback
    {
    public:
        virtual ~apiCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr _msg_)
        {
            static ::std::string __api_all[]=
            {
                "doCommon"
            };

            pair<string*, string*> r = equal_range(__api_all, __api_all+1, string(_msg_->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __api_all)
            {
                case 0:
                {
                    if (_msg_->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_doCommon_exception(_msg_->response->iRet);

                        return _msg_->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(_msg_->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        GoodsApp::CommonRsp rsp;
                        _is.read(rsp, 2, true);
                        setResponseContext(_msg_->response->context);

                        callback_doCommon(_ret, std::move(rsp));

                    }
                    catch(std::exception &ex)
                    {
                        callback_doCommon_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_doCommon_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<apiCoroPrxCallback> apiCoroPrxCallbackPtr;

    /* proxy for client */
    class apiProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 doCommon(const GoodsApp::CommonReq & req,GoodsApp::CommonRsp &rsp,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            _os.write(rsp, 2);
            ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                _pSptd_->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value["req"] = tars::JsonOutput::writeJson(req);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "doCommon", 0, _trace_param_, "");
            }

            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"doCommon", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(rsp, 2, true);
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CR, _is.size());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CR), TRACE_ANNOTATION_CR, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "doCommon", 0, _trace_param_, "");
            }

            return _ret;
        }

        void async_doCommon(apiPrxCallbackPtr callback,const GoodsApp::CommonReq &req,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
            if (_pSptd_ && _pSptd_->_traceCall)
            {
                _pSptd_->newSpan();
                string _trace_param_;
                int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_CS, _os.getLength());
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value["req"] = tars::JsonOutput::writeJson(req);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_CS), TRACE_ANNOTATION_CS, ServerConfig::Application + "." + ServerConfig::ServerName, tars_name(), "doCommon", 0, _trace_param_, "");
            }
            tars_invoke_async(tars::TARSNORMAL,"doCommon", _os, context, _mStatus, callback);
        }
        
        tars::Future< apiPrxCallbackPromise::PromisedoCommonPtr > promise_async_doCommon(const GoodsApp::CommonReq &req,const map<string, string>& context)
        {
            tars::Promise< apiPrxCallbackPromise::PromisedoCommonPtr > promise;
            apiPrxCallbackPromisePtr callback = new apiPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"doCommon", _os, context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_doCommon(apiCoroPrxCallbackPtr callback,const GoodsApp::CommonReq &req,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"doCommon", _os, context, _mStatus, callback, true);
        }

        apiProxy* tars_hash(uint32_t key)
        {
            return (apiProxy*)ServantProxy::tars_hash(key);
        }

        apiProxy* tars_consistent_hash(uint32_t key)
        {
            return (apiProxy*)ServantProxy::tars_consistent_hash(key);
        }

        apiProxy* tars_open_trace(bool traceParam = false)
        {
            return (apiProxy*)ServantProxy::tars_open_trace(traceParam);
        }

        apiProxy* tars_set_timeout(int msecond)
        {
            return (apiProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "apiProxy"; }
    };
    typedef tars::TC_AutoPtr<apiProxy> apiPrx;

    /* servant for server */
    class api : public tars::Servant
    {
    public:
        virtual ~api(){}
        virtual tars::Int32 doCommon(const GoodsApp::CommonReq & req,GoodsApp::CommonRsp &rsp,tars::TarsCurrentPtr _current_) = 0;
        virtual tars::Int32 doCommon(GoodsApp::CommonReq && req,GoodsApp::CommonRsp &rsp,tars::TarsCurrentPtr _current_) 
        { return doCommon(req, rsp, _current_); }
        static void async_response_doCommon(tars::TarsCurrentPtr _current_, tars::Int32 _ret, const GoodsApp::CommonRsp &rsp)
        {
            size_t _rsp_len_ = 0;
            if (_current_->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                _tarsAttr_.setVersion(_current_->getRequestVersion());
                _tarsAttr_.put("", _ret);
                _tarsAttr_.put("tars_ret", _ret);
                _tarsAttr_.put("rsp", rsp);

                vector<char> sTupResponseBuffer;
                _tarsAttr_.encode(sTupResponseBuffer);
                _current_->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
                _rsp_len_ = sTupResponseBuffer.size();
            }
            else if (_current_->getRequestVersion() == JSONVERSION)
            {
                tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                _p->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                vector<char> sJsonResponseBuffer;
                tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
                _current_->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
                _rsp_len_ = sJsonResponseBuffer.size();
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(rsp, 2);

                _rsp_len_ = _os.getLength();
                _current_->sendResponse(tars::TARSSERVERSUCCESS, _os);
            }
            if (_current_->isTraced())
            {
                string _trace_param_;
                int _trace_param_flag_ = ServantProxyThreadData::needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, _current_->getTraceKey(), _rsp_len_);
                if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                {
                    tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                    _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                    _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                    _trace_param_ = tars::TC_Json::writeValue(_p_);
                }
                else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                {
                    _trace_param_ = "{\"trace_param_over_max_len\":true}";
                }
                TARS_TRACE(_current_->getTraceKey(), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "doCommon", 0, _trace_param_, "");
            }

        }
        static void async_response_push_doCommon(tars::CurrentPtr _current_, tars::Int32 _ret, const GoodsApp::CommonRsp &rsp, const map<string, string> &_context = tars::Current::TARS_STATUS())
        {
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(rsp, 2);

                _current_->sendPushResponse( tars::TARSSERVERSUCCESS ,"doCommon", _os, _context);
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __GoodsApp__api_all[]=
            {
                "doCommon"
            };

            pair<string*, string*> r = equal_range(__GoodsApp__api_all, __GoodsApp__api_all+1, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __GoodsApp__api_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    GoodsApp::CommonReq req;
                    GoodsApp::CommonRsp rsp;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                        _tarsAttr_.setVersion(_current->getRequestVersion());
                        _tarsAttr_.decode(_current->getRequestBuffer());
                        _tarsAttr_.get("req", req);
                        _tarsAttr_.getByDefault("rsp", rsp, rsp);
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                        tars::JsonInput::readJson(req, _jsonPtr->value["req"], true);
                        tars::JsonInput::readJson(rsp, _jsonPtr->value["rsp"], false);
                    }
                    else
                    {
                        _is.read(req, 1, true);
                        _is.read(rsp, 2, false);
                    }
                    ServantProxyThreadData *_pSptd_ = ServantProxyThreadData::getData();
                    if (_pSptd_ && _pSptd_->_traceCall)
                    {
                        string _trace_param_;
                        int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_SR, _is.size());
                        if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                        {
                            tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                            _p_->value["req"] = tars::JsonOutput::writeJson(req);
                            _trace_param_ = tars::TC_Json::writeValue(_p_);
                        }
                        else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                        {
                            _trace_param_ = "{\"trace_param_over_max_len\":true}";
                        }
                        TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SR), TRACE_ANNOTATION_SR, "", ServerConfig::Application + "." + ServerConfig::ServerName, "doCommon", 0, _trace_param_, "");
                    }

                    tars::Int32 _ret = doCommon(std::move(req),rsp, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION)
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  _tarsAttr_;
                            _tarsAttr_.setVersion(_current->getRequestVersion());
                            _tarsAttr_.put("", _ret);
                            _tarsAttr_.put("tars_ret", _ret);
                            _tarsAttr_.put("rsp", rsp);
                            _tarsAttr_.encode(_sResponseBuffer);
                        }
                        else if (_current->getRequestVersion() == JSONVERSION)
                        {
                            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                            _p->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                            tars::TC_Json::writeValue(_p, _sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.write(rsp, 2);
                            _os.swap(_sResponseBuffer);
                        }
                        if (_pSptd_ && _pSptd_->_traceCall)
                        {
                            string _trace_param_;
                            int _trace_param_flag_ = _pSptd_->needTraceParam(ServantProxyThreadData::TraceContext::EST_SS, _sResponseBuffer.size());
                            if (ServantProxyThreadData::TraceContext::ENP_NORMAL == _trace_param_flag_)
                            {
                                tars::JsonValueObjPtr _p_ = new tars::JsonValueObj();
                                _p_->value[""] = tars::JsonOutput::writeJson(_ret);
                                _p_->value["rsp"] = tars::JsonOutput::writeJson(rsp);
                                _trace_param_ = tars::TC_Json::writeValue(_p_);
                            }
                            else if(ServantProxyThreadData::TraceContext::ENP_OVERMAXLEN == _trace_param_flag_)
                            {
                                _trace_param_ = "{\"trace_param_over_max_len\":true}";
                            }
                            TARS_TRACE(_pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS), TRACE_ANNOTATION_SS, "", ServerConfig::Application + "." + ServerConfig::ServerName, "doCommon", 0, _trace_param_, "");
                        }

                    }
                    else if(_pSptd_ && _pSptd_->_traceCall)
                    {
                        _current->setTrace(_pSptd_->_traceCall, _pSptd_->getTraceKey(ServantProxyThreadData::TraceContext::EST_SS));
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
