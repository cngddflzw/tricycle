/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "proxy_service_types.h"

#include <algorithm>

namespace tricycle {

const char* Request::ascii_fingerprint = "BFF0E21728CB005F9AA5774A41542B8D";
const uint8_t Request::binary_fingerprint[16] = {0xBF,0xF0,0xE2,0x17,0x28,0xCB,0x00,0x5F,0x9A,0xA5,0x77,0x4A,0x41,0x54,0x2B,0x8D};

uint32_t Request::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->group);
          this->__isset.group = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->version);
          this->__isset.version = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->class_name);
          this->__isset.class_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->func_name);
          this->__isset.func_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->param);
          this->__isset.param = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Request::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Request");

  xfer += oprot->writeFieldBegin("group", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->group);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("version", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->version);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("class_name", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->class_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("func_name", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->func_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("param", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->param);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Request &a, Request &b) {
  using ::std::swap;
  swap(a.group, b.group);
  swap(a.version, b.version);
  swap(a.class_name, b.class_name);
  swap(a.func_name, b.func_name);
  swap(a.param, b.param);
  swap(a.__isset, b.__isset);
}

} // namespace
