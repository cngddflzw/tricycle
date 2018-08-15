/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef proxy_service_TYPES_H
#define proxy_service_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace tricycle {

class Request;

typedef struct _Request__isset {
  _Request__isset() : group(false), version(false), class_name(false), func_name(false), param(false) {}
  bool group :1;
  bool version :1;
  bool class_name :1;
  bool func_name :1;
  bool param :1;
} _Request__isset;

class Request {
 public:

  Request(const Request&);
  Request& operator=(const Request&);
  Request() : group(), version(), class_name(), func_name(), param() {
  }

  virtual ~Request() throw();
  std::string group;
  std::string version;
  std::string class_name;
  std::string func_name;
  std::string param;

  _Request__isset __isset;

  void __set_group(const std::string& val);

  void __set_version(const std::string& val);

  void __set_class_name(const std::string& val);

  void __set_func_name(const std::string& val);

  void __set_param(const std::string& val);

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

  virtual void printTo(std::ostream& out) const;
};

void swap(Request &a, Request &b);

inline std::ostream& operator<<(std::ostream& out, const Request& obj)
{
  obj.printTo(out);
  return out;
}

} // namespace

#endif