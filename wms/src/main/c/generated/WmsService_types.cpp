/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "WmsService_types.h"

#include <algorithm>

namespace trafodion { namespace wms { namespace thrift {

int _kOperationValues[] = {
  Operation::OPERATION_BEGIN,
  Operation::OPERATION_UPDATE,
  Operation::OPERATION_END,
  Operation::OPERATION_UPDATE_PARENT_ID,
  Operation::OPERATION_CANCEL_CHILDREN
};
const char* _kOperationNames[] = {
  "OPERATION_BEGIN",
  "OPERATION_UPDATE",
  "OPERATION_END",
  "OPERATION_UPDATE_PARENT_ID",
  "OPERATION_CANCEL_CHILDREN"
};
const std::map<int, const char*> _Operation_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kOperationValues, _kOperationNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kActionValues[] = {
  Action::ACTION_CONTINUE,
  Action::ACTION_REJECT,
  Action::ACTION_CANCEL,
  Action::ACTION_KILL,
  Action::ACTION_WARNING,
  Action::ACTION_PRIORITY_LOW,
  Action::ACTION_PRIORITY_MEDIUM,
  Action::ACTION_PRIORITY_HIGH
};
const char* _kActionNames[] = {
  "ACTION_CONTINUE",
  "ACTION_REJECT",
  "ACTION_CANCEL",
  "ACTION_KILL",
  "ACTION_WARNING",
  "ACTION_PRIORITY_LOW",
  "ACTION_PRIORITY_MEDIUM",
  "ACTION_PRIORITY_HIGH"
};
const std::map<int, const char*> _Action_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(8, _kActionValues, _kActionNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

const char* KeyValue::ascii_fingerprint = "8030FA0B1A7FF7D870C593DE44E90298";
const uint8_t KeyValue::binary_fingerprint[16] = {0x80,0x30,0xFA,0x0B,0x1A,0x7F,0xF7,0xD8,0x70,0xC5,0x93,0xDE,0x44,0xE9,0x02,0x98};

uint32_t KeyValue::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->boolValue);
          this->__isset.boolValue = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->byteValue);
          this->__isset.byteValue = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->shortValue);
          this->__isset.shortValue = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->intValue);
          this->__isset.intValue = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->longValue);
          this->__isset.longValue = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->floatValue);
          this->__isset.floatValue = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->stringValue);
          this->__isset.stringValue = true;
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

uint32_t KeyValue::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("KeyValue");

  if (this->__isset.boolValue) {
    xfer += oprot->writeFieldBegin("boolValue", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->boolValue);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.byteValue) {
    xfer += oprot->writeFieldBegin("byteValue", ::apache::thrift::protocol::T_BYTE, 2);
    xfer += oprot->writeByte(this->byteValue);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.shortValue) {
    xfer += oprot->writeFieldBegin("shortValue", ::apache::thrift::protocol::T_I16, 3);
    xfer += oprot->writeI16(this->shortValue);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.intValue) {
    xfer += oprot->writeFieldBegin("intValue", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->intValue);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.longValue) {
    xfer += oprot->writeFieldBegin("longValue", ::apache::thrift::protocol::T_I64, 5);
    xfer += oprot->writeI64(this->longValue);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.floatValue) {
    xfer += oprot->writeFieldBegin("floatValue", ::apache::thrift::protocol::T_DOUBLE, 6);
    xfer += oprot->writeDouble(this->floatValue);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.stringValue) {
    xfer += oprot->writeFieldBegin("stringValue", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->stringValue);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(KeyValue &a, KeyValue &b) {
  using ::std::swap;
  swap(a.boolValue, b.boolValue);
  swap(a.byteValue, b.byteValue);
  swap(a.shortValue, b.shortValue);
  swap(a.intValue, b.intValue);
  swap(a.longValue, b.longValue);
  swap(a.floatValue, b.floatValue);
  swap(a.stringValue, b.stringValue);
  swap(a.__isset, b.__isset);
}

const char* Data::ascii_fingerprint = "3744E9C024E14DD4F9ECA86B921D240A";
const uint8_t Data::binary_fingerprint[16] = {0x37,0x44,0xE9,0xC0,0x24,0xE1,0x4D,0xD4,0xF9,0xEC,0xA8,0x6B,0x92,0x1D,0x24,0x0A};

uint32_t Data::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->keyValues.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _ktype1;
            ::apache::thrift::protocol::TType _vtype2;
            xfer += iprot->readMapBegin(_ktype1, _vtype2, _size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              std::string _key5;
              xfer += iprot->readString(_key5);
              KeyValue& _val6 = this->keyValues[_key5];
              xfer += _val6.read(iprot);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.keyValues = true;
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

uint32_t Data::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Data");

  if (this->__isset.keyValues) {
    xfer += oprot->writeFieldBegin("keyValues", ::apache::thrift::protocol::T_MAP, 1);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->keyValues.size()));
      std::map<std::string, KeyValue> ::const_iterator _iter7;
      for (_iter7 = this->keyValues.begin(); _iter7 != this->keyValues.end(); ++_iter7)
      {
        xfer += oprot->writeString(_iter7->first);
        xfer += _iter7->second.write(oprot);
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Data &a, Data &b) {
  using ::std::swap;
  swap(a.keyValues, b.keyValues);
  swap(a.__isset, b.__isset);
}

const char* Header::ascii_fingerprint = "CE62EB594CA7F8C2ABE78957866085E9";
const uint8_t Header::binary_fingerprint[16] = {0xCE,0x62,0xEB,0x59,0x4C,0xA7,0xF8,0xC2,0xAB,0xE7,0x89,0x57,0x86,0x60,0x85,0xE9};

uint32_t Header::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->version);
          this->__isset.version = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->clientIpAddress);
          this->__isset.clientIpAddress = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->clientTimestamp);
          this->__isset.clientTimestamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->clientUserName);
          this->__isset.clientUserName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->clientApplication);
          this->__isset.clientApplication = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->serverLastUpdated);
          this->__isset.serverLastUpdated = true;
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

uint32_t Header::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Header");

  xfer += oprot->writeFieldBegin("version", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->version);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("clientIpAddress", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->clientIpAddress);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("clientTimestamp", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->clientTimestamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("clientUserName", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->clientUserName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("clientApplication", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->clientApplication);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("serverLastUpdated", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->serverLastUpdated);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Header &a, Header &b) {
  using ::std::swap;
  swap(a.version, b.version);
  swap(a.clientIpAddress, b.clientIpAddress);
  swap(a.clientTimestamp, b.clientTimestamp);
  swap(a.clientUserName, b.clientUserName);
  swap(a.clientApplication, b.clientApplication);
  swap(a.serverLastUpdated, b.serverLastUpdated);
  swap(a.__isset, b.__isset);
}

const char* Request::ascii_fingerprint = "252EE71CE3D737D84E12CF91BC47093B";
const uint8_t Request::binary_fingerprint[16] = {0x25,0x2E,0xE7,0x1C,0xE3,0xD7,0x37,0xD8,0x4E,0x12,0xCF,0x91,0xBC,0x47,0x09,0x3B};

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
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->header.read(iprot);
          this->__isset.header = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->data.read(iprot);
          this->__isset.data = true;
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

  xfer += oprot->writeFieldBegin("header", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->header.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->data.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Request &a, Request &b) {
  using ::std::swap;
  swap(a.header, b.header);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

const char* Response::ascii_fingerprint = "252EE71CE3D737D84E12CF91BC47093B";
const uint8_t Response::binary_fingerprint[16] = {0x25,0x2E,0xE7,0x1C,0xE3,0xD7,0x37,0xD8,0x4E,0x12,0xCF,0x91,0xBC,0x47,0x09,0x3B};

uint32_t Response::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->header.read(iprot);
          this->__isset.header = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->data.read(iprot);
          this->__isset.data = true;
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

uint32_t Response::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Response");

  xfer += oprot->writeFieldBegin("header", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->header.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->data.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Response &a, Response &b) {
  using ::std::swap;
  swap(a.header, b.header);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

const char* Stream::ascii_fingerprint = "5F9965D46A4F3845985AC0F9B81C3C69";
const uint8_t Stream::binary_fingerprint[16] = {0x5F,0x99,0x65,0xD4,0x6A,0x4F,0x38,0x45,0x98,0x5A,0xC0,0xF9,0xB8,0x1C,0x3C,0x69};

uint32_t Stream::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->comment);
          this->__isset.comment = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timestamp);
          this->__isset.timestamp = true;
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

uint32_t Stream::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Stream");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("comment", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->comment);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->timestamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Stream &a, Stream &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.value, b.value);
  swap(a.comment, b.comment);
  swap(a.timestamp, b.timestamp);
  swap(a.__isset, b.__isset);
}

const char* StreamResponse::ascii_fingerprint = "DDDA8F891CEFA6BAEE9C7096D0B1642F";
const uint8_t StreamResponse::binary_fingerprint[16] = {0xDD,0xDA,0x8F,0x89,0x1C,0xEF,0xA6,0xBA,0xEE,0x9C,0x70,0x96,0xD0,0xB1,0x64,0x2F};

uint32_t StreamResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->streamList.clear();
            uint32_t _size8;
            ::apache::thrift::protocol::TType _etype11;
            xfer += iprot->readListBegin(_etype11, _size8);
            this->streamList.resize(_size8);
            uint32_t _i12;
            for (_i12 = 0; _i12 < _size8; ++_i12)
            {
              xfer += this->streamList[_i12].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.streamList = true;
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

uint32_t StreamResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("StreamResponse");

  xfer += oprot->writeFieldBegin("streamList", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->streamList.size()));
    std::vector<Stream> ::const_iterator _iter13;
    for (_iter13 = this->streamList.begin(); _iter13 != this->streamList.end(); ++_iter13)
    {
      xfer += (*_iter13).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StreamResponse &a, StreamResponse &b) {
  using ::std::swap;
  swap(a.streamList, b.streamList);
  swap(a.__isset, b.__isset);
}

const char* Rule::ascii_fingerprint = "5F9965D46A4F3845985AC0F9B81C3C69";
const uint8_t Rule::binary_fingerprint[16] = {0x5F,0x99,0x65,0xD4,0x6A,0x4F,0x38,0x45,0x98,0x5A,0xC0,0xF9,0xB8,0x1C,0x3C,0x69};

uint32_t Rule::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->comment);
          this->__isset.comment = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->timestamp);
          this->__isset.timestamp = true;
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

uint32_t Rule::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Rule");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("comment", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->comment);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->timestamp);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Rule &a, Rule &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.value, b.value);
  swap(a.comment, b.comment);
  swap(a.timestamp, b.timestamp);
  swap(a.__isset, b.__isset);
}

const char* RuleResponse::ascii_fingerprint = "DDDA8F891CEFA6BAEE9C7096D0B1642F";
const uint8_t RuleResponse::binary_fingerprint[16] = {0xDD,0xDA,0x8F,0x89,0x1C,0xEF,0xA6,0xBA,0xEE,0x9C,0x70,0x96,0xD0,0xB1,0x64,0x2F};

uint32_t RuleResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->ruleList.clear();
            uint32_t _size14;
            ::apache::thrift::protocol::TType _etype17;
            xfer += iprot->readListBegin(_etype17, _size14);
            this->ruleList.resize(_size14);
            uint32_t _i18;
            for (_i18 = 0; _i18 < _size14; ++_i18)
            {
              xfer += this->ruleList[_i18].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.ruleList = true;
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

uint32_t RuleResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("RuleResponse");

  xfer += oprot->writeFieldBegin("ruleList", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->ruleList.size()));
    std::vector<Rule> ::const_iterator _iter19;
    for (_iter19 = this->ruleList.begin(); _iter19 != this->ruleList.end(); ++_iter19)
    {
      xfer += (*_iter19).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RuleResponse &a, RuleResponse &b) {
  using ::std::swap;
  swap(a.ruleList, b.ruleList);
  swap(a.__isset, b.__isset);
}

const char* WorkloadResponse::ascii_fingerprint = "D0D9EE8C6C26E09B1A4E0CDB1751C878";
const uint8_t WorkloadResponse::binary_fingerprint[16] = {0xD0,0xD9,0xEE,0x8C,0x6C,0x26,0xE0,0x9B,0x1A,0x4E,0x0C,0xDB,0x17,0x51,0xC8,0x78};

uint32_t WorkloadResponse::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->workloadList.clear();
            uint32_t _size20;
            ::apache::thrift::protocol::TType _etype23;
            xfer += iprot->readListBegin(_etype23, _size20);
            this->workloadList.resize(_size20);
            uint32_t _i24;
            for (_i24 = 0; _i24 < _size20; ++_i24)
            {
              xfer += this->workloadList[_i24].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.workloadList = true;
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

uint32_t WorkloadResponse::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("WorkloadResponse");

  xfer += oprot->writeFieldBegin("workloadList", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->workloadList.size()));
    std::vector<Request> ::const_iterator _iter25;
    for (_iter25 = this->workloadList.begin(); _iter25 != this->workloadList.end(); ++_iter25)
    {
      xfer += (*_iter25).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(WorkloadResponse &a, WorkloadResponse &b) {
  using ::std::swap;
  swap(a.workloadList, b.workloadList);
  swap(a.__isset, b.__isset);
}

const char* IOError::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t IOError::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t IOError::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
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

uint32_t IOError::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("IOError");

  xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->message);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(IOError &a, IOError &b) {
  using ::std::swap;
  swap(a.message, b.message);
  swap(a.__isset, b.__isset);
}

const char* IllegalArgument::ascii_fingerprint = "EFB929595D312AC8F305D5A794CFEDA1";
const uint8_t IllegalArgument::binary_fingerprint[16] = {0xEF,0xB9,0x29,0x59,0x5D,0x31,0x2A,0xC8,0xF3,0x05,0xD5,0xA7,0x94,0xCF,0xED,0xA1};

uint32_t IllegalArgument::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->message);
          this->__isset.message = true;
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

uint32_t IllegalArgument::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("IllegalArgument");

  xfer += oprot->writeFieldBegin("message", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->message);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(IllegalArgument &a, IllegalArgument &b) {
  using ::std::swap;
  swap(a.message, b.message);
  swap(a.__isset, b.__isset);
}

}}} // namespace