/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef generic_service_TYPES_H
#define generic_service_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>



namespace tricycle {

typedef struct _Request__isset {
  _Request__isset() : class_name(false), func_name(false), param(false) {}
  bool class_name;
  bool func_name;
  bool param;
} _Request__isset;

class Request {
 public:

  static const char* ascii_fingerprint; // = "AB879940BD15B6B25691265F7384B271";
  static const uint8_t binary_fingerprint[16]; // = {0xAB,0x87,0x99,0x40,0xBD,0x15,0xB6,0xB2,0x56,0x91,0x26,0x5F,0x73,0x84,0xB2,0x71};

  Request() : class_name(), func_name(), param() {
  }

  virtual ~Request() throw() {}

  std::string class_name;
  std::string func_name;
  std::string param;

  _Request__isset __isset;

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