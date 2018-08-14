//
// Created by Zhenwei Liu on 2018/8/13.
//

#include<tricycle/tricycle.hpp>
#include<tricycle/tricycle_server.hpp>

#include "demo_service.hpp"

using namespace business;
using namespace tricycle;

int main() {
    DemoService *service = new DemoService();

    TRICYCLE_CREATE_CLS(DemoService, Test, service);
    TRICYCLE_CREATE_CLS(DemoService, Test2, service);

    TricycleServer server = TricycleServer();
    server.Serve(9090);
}