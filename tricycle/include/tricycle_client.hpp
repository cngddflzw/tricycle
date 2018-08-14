//
// Created by Zhenwei Liu on 2018/8/14.
//

#ifndef TRICYCLE_TRICYCLE_CLIENT_HPP
#define TRICYCLE_TRICYCLE_CLIENT_HPP

#include <stdio.h>
#include <string>

using namespace std;

namespace tricycle {

    class TricycleClient {
    public:
        void Invoke(string addr, int port, string &_return, const Request &request);
    };
}

#endif
