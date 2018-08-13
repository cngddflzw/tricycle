//
// Created by Zhenwei Liu on 2018/8/7.
//

#ifndef TRICYCLE_DEMO_SERVICE_HPP
#define TRICYCLE_DEMO_SERVICE_HPP

#include <string>
#include <tricycle/json.h>

using namespace std;

namespace business {

    class Result {
    private:
        string name_;
        int code_;

    public:
        Result(const string &n, const int &c);

        string GetName() const;

        int GetCode() const;
    };

    class Param {
    private:
        string name_;
        int code_;

    public:
        Param(const string &n, const int &c);

        string GetName() const;

        int GetCode() const;
    };

    class DemoService {

    public:
        string Test(const Json::Value &json_array) const;

        string Test2(const Json::Value &json_array) const;
    };
}

#endif
