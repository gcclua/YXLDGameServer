// **********************************************************************
// This file was generated by a TAF parser!
// TAF version 4.6.0 by WSRD Tencent.
// Generated from `DbAccess.jce'
// **********************************************************************

#include "DbAccess.h"
#include "jce/wup.h"
#include "servant/BaseF.h"

using namespace wup;

namespace ServerEngine
{

    taf::Int32 DbAccessProxy::delString(const std::string &strKey, const map<string, string> &context)
    {
        taf::JceOutputStream<taf::BufferWriter> _os;
        _os.write(strKey, 1);
        taf::ResponsePacket rep;
        std::map<string, string> status;
        taf_invoke(taf::JCENORMAL,"delString", _os.getByteBuffer(), context, status, rep);
        taf::JceInputStream<taf::BufferReader> _is;
        _is.setBuffer(rep.sBuffer);
        taf::Int32 _ret;
        _is.read(_ret, 0, true);
        return _ret;
    }

    void DbAccess::async_response_delString(taf::JceCurrentPtr current, taf::Int32 _ret)
    {
        if (current->getRequestVersion() == WUPVERSION || current->getRequestVersion() == WUPVERSION2)
        {
            UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
            tafAttr.setVersion(current->getRequestVersion());
            tafAttr.put("", _ret);

            vector<char> sWupResponseBuffer;
            tafAttr.encode(sWupResponseBuffer);
            current->sendResponse(taf::JCESERVERSUCCESS, sWupResponseBuffer);
        }
        else
        {
            taf::JceOutputStream<taf::BufferWriter> _os;
            _os.write(_ret, 0);

            current->sendResponse(taf::JCESERVERSUCCESS, _os.getByteBuffer());
        }
    }

    void DbAccessProxy::async_delString(DbAccessPrxCallbackPtr callback,const std::string &strKey,const map<string, string>& context)
    {
        taf::JceOutputStream<taf::BufferWriter> _os;
        _os.write(strKey, 1);
        std::map<string, string> status;
        taf_invoke_async(taf::JCENORMAL,"delString", _os.getByteBuffer(), context, status, callback);
    }

    taf::Int32 DbAccessProxy::getString(const std::string &strKey, std::string &strValue, const map<string, string> &context)
    {
        taf::JceOutputStream<taf::BufferWriter> _os;
        _os.write(strKey, 1);
        _os.write(strValue, 2);
        taf::ResponsePacket rep;
        std::map<string, string> status;
        taf_invoke(taf::JCENORMAL,"getString", _os.getByteBuffer(), context, status, rep);
        taf::JceInputStream<taf::BufferReader> _is;
        _is.setBuffer(rep.sBuffer);
        taf::Int32 _ret;
        _is.read(_ret, 0, true);
        _is.read(strValue, 2, true);
        return _ret;
    }

    void DbAccess::async_response_getString(taf::JceCurrentPtr current, taf::Int32 _ret, const std::string &strValue)
    {
        if (current->getRequestVersion() == WUPVERSION || current->getRequestVersion() == WUPVERSION2)
        {
            UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
            tafAttr.setVersion(current->getRequestVersion());
            tafAttr.put("", _ret);
            tafAttr.put("strValue", strValue);

            vector<char> sWupResponseBuffer;
            tafAttr.encode(sWupResponseBuffer);
            current->sendResponse(taf::JCESERVERSUCCESS, sWupResponseBuffer);
        }
        else
        {
            taf::JceOutputStream<taf::BufferWriter> _os;
            _os.write(_ret, 0);

            _os.write(strValue, 2);

            current->sendResponse(taf::JCESERVERSUCCESS, _os.getByteBuffer());
        }
    }

    void DbAccessProxy::async_getString(DbAccessPrxCallbackPtr callback,const std::string &strKey,const map<string, string>& context)
    {
        taf::JceOutputStream<taf::BufferWriter> _os;
        _os.write(strKey, 1);
        std::map<string, string> status;
        taf_invoke_async(taf::JCENORMAL,"getString", _os.getByteBuffer(), context, status, callback);
    }

    taf::Int32 DbAccessProxy::setString(const std::string &strKey, const std::string &strValue, const map<string, string> &context)
    {
        taf::JceOutputStream<taf::BufferWriter> _os;
        _os.write(strKey, 1);
        _os.write(strValue, 2);
        taf::ResponsePacket rep;
        std::map<string, string> status;
        taf_invoke(taf::JCENORMAL,"setString", _os.getByteBuffer(), context, status, rep);
        taf::JceInputStream<taf::BufferReader> _is;
        _is.setBuffer(rep.sBuffer);
        taf::Int32 _ret;
        _is.read(_ret, 0, true);
        return _ret;
    }

    void DbAccess::async_response_setString(taf::JceCurrentPtr current, taf::Int32 _ret)
    {
        if (current->getRequestVersion() == WUPVERSION || current->getRequestVersion() == WUPVERSION2)
        {
            UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
            tafAttr.setVersion(current->getRequestVersion());
            tafAttr.put("", _ret);

            vector<char> sWupResponseBuffer;
            tafAttr.encode(sWupResponseBuffer);
            current->sendResponse(taf::JCESERVERSUCCESS, sWupResponseBuffer);
        }
        else
        {
            taf::JceOutputStream<taf::BufferWriter> _os;
            _os.write(_ret, 0);

            current->sendResponse(taf::JCESERVERSUCCESS, _os.getByteBuffer());
        }
    }

    void DbAccessProxy::async_setString(DbAccessPrxCallbackPtr callback,const std::string &strKey,const std::string &strValue,const map<string, string>& context)
    {
        taf::JceOutputStream<taf::BufferWriter> _os;
        _os.write(strKey, 1);
        _os.write(strValue, 2);
        std::map<string, string> status;
        taf_invoke_async(taf::JCENORMAL,"setString", _os.getByteBuffer(), context, status, callback);
    }

    DbAccessProxy* DbAccessProxy::taf_hash(int64_t key)
    {
        return (DbAccessProxy*)ServantProxy::taf_hash(key);
    }

    static ::std::string __ServerEngine__DbAccess_all[]=
    {
        "delString",
        "getString",
        "setString"
    };

    int DbAccessPrxCallback::onDispatch(taf::ReqMessagePtr msg)
    {
        pair<string*, string*> r = equal_range(__ServerEngine__DbAccess_all, __ServerEngine__DbAccess_all+3, msg->request.sFuncName);
        if(r.first == r.second) return taf::JCESERVERNOFUNCERR;
        switch(r.first - __ServerEngine__DbAccess_all)
        {
            case 0:
            {
                if (msg->response.iRet != taf::JCESERVERSUCCESS)
                {
                    callback_delString_exception(msg->response.iRet);

                    return msg->response.iRet;
                }
                taf::JceInputStream<taf::BufferReader> _is;

                _is.setBuffer(msg->response.sBuffer);
                taf::Int32 _ret;
                _is.read(_ret, 0, true);

                callback_delString(_ret);
                return taf::JCESERVERSUCCESS;

            }
            case 1:
            {
                if (msg->response.iRet != taf::JCESERVERSUCCESS)
                {
                    callback_getString_exception(msg->response.iRet);

                    return msg->response.iRet;
                }
                taf::JceInputStream<taf::BufferReader> _is;

                _is.setBuffer(msg->response.sBuffer);
                taf::Int32 _ret;
                _is.read(_ret, 0, true);

                std::string strValue;
                _is.read(strValue, 2, true);
                callback_getString(_ret, strValue);
                return taf::JCESERVERSUCCESS;

            }
            case 2:
            {
                if (msg->response.iRet != taf::JCESERVERSUCCESS)
                {
                    callback_setString_exception(msg->response.iRet);

                    return msg->response.iRet;
                }
                taf::JceInputStream<taf::BufferReader> _is;

                _is.setBuffer(msg->response.sBuffer);
                taf::Int32 _ret;
                _is.read(_ret, 0, true);

                callback_setString(_ret);
                return taf::JCESERVERSUCCESS;

            }
        }
        return taf::JCESERVERNOFUNCERR;
    }

    int DbAccess::onDispatch(taf::JceCurrentPtr _current, vector<char> &_sResponseBuffer)
    {
        pair<string*, string*> r = equal_range(__ServerEngine__DbAccess_all, __ServerEngine__DbAccess_all+3, _current->getFuncName());
        if(r.first == r.second) return taf::JCESERVERNOFUNCERR;
        switch(r.first - __ServerEngine__DbAccess_all)
        {
            case 0:
            {
                taf::JceInputStream<taf::BufferReader> _is;
                _is.setBuffer(_current->getRequestBuffer());
                std::string strKey;
                if (_current->getRequestVersion() == WUPVERSION || _current->getRequestVersion() == WUPVERSION2)
                {
                    UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
                    tafAttr.setVersion(_current->getRequestVersion());
                    tafAttr.decode(_current->getRequestBuffer());
                    tafAttr.get("strKey", strKey);
                }
                else
                {
                    _is.read(strKey, 1, true);
                }
                taf::Int32 _ret = delString(strKey, _current);
                if(_current->isResponse())
                {
                    if (_current->getRequestVersion() == WUPVERSION || _current->getRequestVersion() == WUPVERSION2)
                    {
                        UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
                        tafAttr.setVersion(_current->getRequestVersion());
                        tafAttr.put("", _ret);
                        tafAttr.encode(_sResponseBuffer);
                    }
                    else
                    {
                        taf::JceOutputStream<taf::BufferWriter> _os;
                        _os.write(_ret, 0);
                        _os.swap(_sResponseBuffer);
                    }
                }
                return taf::JCESERVERSUCCESS;

            }
            case 1:
            {
                taf::JceInputStream<taf::BufferReader> _is;
                _is.setBuffer(_current->getRequestBuffer());
                std::string strKey;
                std::string strValue;
                if (_current->getRequestVersion() == WUPVERSION || _current->getRequestVersion() == WUPVERSION2)
                {
                    UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
                    tafAttr.setVersion(_current->getRequestVersion());
                    tafAttr.decode(_current->getRequestBuffer());
                    tafAttr.get("strKey", strKey);
                    tafAttr.getByDefault("strValue", strValue, strValue);
                }
                else
                {
                    _is.read(strKey, 1, true);
                    _is.read(strValue, 2, false);
                }
                taf::Int32 _ret = getString(strKey,strValue, _current);
                if(_current->isResponse())
                {
                    if (_current->getRequestVersion() == WUPVERSION || _current->getRequestVersion() == WUPVERSION2)
                    {
                        UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
                        tafAttr.setVersion(_current->getRequestVersion());
                        tafAttr.put("", _ret);
                        tafAttr.put("strValue", strValue);
                        tafAttr.encode(_sResponseBuffer);
                    }
                    else
                    {
                        taf::JceOutputStream<taf::BufferWriter> _os;
                        _os.write(_ret, 0);
                        _os.write(strValue, 2);
                        _os.swap(_sResponseBuffer);
                    }
                }
                return taf::JCESERVERSUCCESS;

            }
            case 2:
            {
                taf::JceInputStream<taf::BufferReader> _is;
                _is.setBuffer(_current->getRequestBuffer());
                std::string strKey;
                std::string strValue;
                if (_current->getRequestVersion() == WUPVERSION || _current->getRequestVersion() == WUPVERSION2)
                {
                    UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
                    tafAttr.setVersion(_current->getRequestVersion());
                    tafAttr.decode(_current->getRequestBuffer());
                    tafAttr.get("strKey", strKey);
                    tafAttr.get("strValue", strValue);
                }
                else
                {
                    _is.read(strKey, 1, true);
                    _is.read(strValue, 2, true);
                }
                taf::Int32 _ret = setString(strKey,strValue, _current);
                if(_current->isResponse())
                {
                    if (_current->getRequestVersion() == WUPVERSION || _current->getRequestVersion() == WUPVERSION2)
                    {
                        UniAttribute<taf::BufferWriter, taf::BufferReader>  tafAttr;
                        tafAttr.setVersion(_current->getRequestVersion());
                        tafAttr.put("", _ret);
                        tafAttr.encode(_sResponseBuffer);
                    }
                    else
                    {
                        taf::JceOutputStream<taf::BufferWriter> _os;
                        _os.write(_ret, 0);
                        _os.swap(_sResponseBuffer);
                    }
                }
                return taf::JCESERVERSUCCESS;

            }
        }
        return taf::JCESERVERNOFUNCERR;
    }


}

int main(){
    return 0;
}