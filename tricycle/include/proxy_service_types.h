/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef proxy_service_TYPES_H
#define proxy_service_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>



namespace tricycle {

typedef struct _Request__isset {
  _Request__isset() : group(false), version(false), class_name(false), func_name(false), param(false) {}
  bool group;
  bool version;
  bool class_name;
  bool func_name;
  bool param;
} _Request__isset;

class Request {
 public:

  static const char* ascii_fingerprint; // = "BFF0E21728CB005F9AA5774A41542B8D";
  static const uint8_t binary_fingerprint[16]; // = {0xBF,0xF0,0xE2,0x17,0x28,0xCB,0x00,0x5F,0x9A,0xA5,0x77,0x4A,0x41,0x54,0x2B,0x8D};

  Request() : group(), version(), class_name(), func_name(), param() {
  }

  virtual ~Request() throw() {}

  std::string group;
  std::string version;
  std::string class_name;
  std::string func_name;
  std::string param;

  _Request__isset __isset;

  void __set_group(const std::string& val) {
    group = val;
  }

  void __set_version(const std::string& val) {
    version = val;
  }

  void __set_class_name(const std::string& val) {
    class_name = val;
  }

  void __set_func_name(const std::string& val) {
    func_name = val;
  }

  void __set_param(const std::string& val) {
    param = val;
  }

  bool operator == (const Request & rhs) const
  {
    if (!(group == rhs.group))
      return false;
    if (!(version == rhs.version))
      return false;
    if (!(class_name == rhs.class_name))
      return false;
    if (!(func_name == rhs.func_name))
      return false;
    if (!(param == rhs.param))
      return false;
    return true;
  }
  bool operator != (const Request &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Request & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(Request &a, Request &b);

} // namespace

#endif
