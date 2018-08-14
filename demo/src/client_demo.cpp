//
// Created by Zhenwei Liu on 2018/8/13.
//

#include<tricycle/proxy_service.h>
#include<tricycle/tricycle_client.hpp>
#include"demo_service.hpp"


#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <stdio.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using namespace tricycle;
using namespace business;
using namespace std;

/**
 * c++ 调用 java 服务测试
 */
int main() {

    const string addr = "localhost";
    const int port = 9091;
    TricycleClient client = TricycleClient();

    string result("");

    Request request = Request();
    request.group = "arch";
    request.version = "1.0.0";
    request.class_name = "com.zim.demo.rpcproxy.java.DemoJavaService";
    request.func_name = "sayHello";
    request.param = "[\"Zim\"]";

    client.Invoke(addr, port, result, request);
    printf("result: %s\n", result.c_str());
    return 0;
}