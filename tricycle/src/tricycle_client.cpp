//
// Created by Zhenwei Liu on 2018/8/14.
//

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <stdio.h>

#include "tricycle/proxy_service.h"
#include "tricycle_client.hpp"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using namespace std;

namespace tricycle {

    void TricycleClient::Invoke(string addr, int port, string &_return, const Request &request) {
        boost::shared_ptr<TTransport> socket(new TSocket(addr, port));
        boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
        boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
        transport->open();

        ProxyServiceClient client(protocol);

        client.Invoke(_return, request);

        transport->close();
    }
}
