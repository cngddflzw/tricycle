/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef GenericService_H
#define GenericService_H

#include <thrift/TDispatchProcessor.h>
#include "generic_service_types.h"

namespace tricycle {

class GenericServiceIf {
 public:
  virtual ~GenericServiceIf() {}
  virtual void Invoke(std::string& _return, const Request& request) = 0;
};

class GenericServiceIfFactory {
 public:
  typedef GenericServiceIf Handler;

  virtual ~GenericServiceIfFactory() {}

  virtual GenericServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(GenericServiceIf* /* handler */) = 0;
};

class GenericServiceIfSingletonFactory : virtual public GenericServiceIfFactory {
 public:
  GenericServiceIfSingletonFactory(const boost::shared_ptr<GenericServiceIf>& iface) : iface_(iface) {}
  virtual ~GenericServiceIfSingletonFactory() {}

  virtual GenericServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(GenericServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<GenericServiceIf> iface_;
};

class GenericServiceNull : virtual public GenericServiceIf {
 public:
  virtual ~GenericServiceNull() {}
  void Invoke(std::string& /* _return */, const Request& /* request */) {
    return;
  }
};

typedef struct _GenericService_Invoke_args__isset {
  _GenericService_Invoke_args__isset() : request(false) {}
  bool request;
} _GenericService_Invoke_args__isset;

class GenericService_Invoke_args {
 public:

  GenericService_Invoke_args() {
  }

  virtual ~GenericService_Invoke_args() throw() {}

  Request request;

  _GenericService_Invoke_args__isset __isset;

  void __set_request(const Request& val) {
    request = val;
  }

  bool operator == (const GenericService_Invoke_args & rhs) const
  {
    if (!(request == rhs.request))
      return false;
    return true;
  }
  bool operator != (const GenericService_Invoke_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GenericService_Invoke_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class GenericService_Invoke_pargs {
 public:


  virtual ~GenericService_Invoke_pargs() throw() {}

  const Request* request;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _GenericService_Invoke_result__isset {
  _GenericService_Invoke_result__isset() : success(false) {}
  bool success;
} _GenericService_Invoke_result__isset;

class GenericService_Invoke_result {
 public:

  GenericService_Invoke_result() : success() {
  }

  virtual ~GenericService_Invoke_result() throw() {}

  std::string success;

  _GenericService_Invoke_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const GenericService_Invoke_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const GenericService_Invoke_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GenericService_Invoke_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _GenericService_Invoke_presult__isset {
  _GenericService_Invoke_presult__isset() : success(false) {}
  bool success;
} _GenericService_Invoke_presult__isset;

class GenericService_Invoke_presult {
 public:


  virtual ~GenericService_Invoke_presult() throw() {}

  std::string* success;

  _GenericService_Invoke_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class GenericServiceClient : virtual public GenericServiceIf {
 public:
  GenericServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  GenericServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void Invoke(std::string& _return, const Request& request);
  void send_Invoke(const Request& request);
  void recv_Invoke(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class GenericServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<GenericServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (GenericServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_Invoke(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  GenericServiceProcessor(boost::shared_ptr<GenericServiceIf> iface) :
    iface_(iface) {
    processMap_["Invoke"] = &GenericServiceProcessor::process_Invoke;
  }

  virtual ~GenericServiceProcessor() {}
};

class GenericServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  GenericServiceProcessorFactory(const ::boost::shared_ptr< GenericServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< GenericServiceIfFactory > handlerFactory_;
};

class GenericServiceMultiface : virtual public GenericServiceIf {
 public:
  GenericServiceMultiface(std::vector<boost::shared_ptr<GenericServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~GenericServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<GenericServiceIf> > ifaces_;
  GenericServiceMultiface() {}
  void add(boost::shared_ptr<GenericServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void Invoke(std::string& _return, const Request& request) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Invoke(_return, request);
    }
    ifaces_[i]->Invoke(_return, request);
    return;
  }

};

} // namespace

#endif