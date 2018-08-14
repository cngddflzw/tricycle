//
// Created by Zhenwei Liu on 2018/8/13.
//
#include <string>
#include <tricycle/json.h>
#include "demo_service.hpp"

using namespace std;

namespace business {

    Result::Result(const string &n, const int &c) {
        name_ = n;
        code_ = c;
    }

    string Result::GetName() const {
        return name_;
    }

    int Result::GetCode() const {
        return code_;
    }

    Param::Param(const string &n, const int &c) {
        name_ = n;
        code_ = c;
    }

    string Param::GetName() const {
        return name_;
    }

    int Param::GetCode() const {
        return code_;
    }

    string DemoService::Test(const Json::Value &json_array) const {
        // deserialization
        Param param = Param(json_array[0]["name"].asString(), json_array[0]["code"].asInt());
        Result result = Result(param.GetName(), param.GetCode());

        // serialization
        Json::Value j;
        j["name"] = result.GetName();
        j["code"] = result.GetCode();
        Json::StreamWriterBuilder builder;
        builder["indentation"] = "";
        return Json::writeString(builder, j);
    }

    string DemoService::Test2(const Json::Value &json_array) const {
        // deserialization
        Param param1 = Param(json_array[0]["name"].asString(), json_array[0]["code"].asInt());
        Param param2 = Param(json_array[1]["name"].asString(), json_array[1]["code"].asInt());
        Result result = Result(param1.GetName() + "::" + param2.GetName(), param1.GetCode() + param2.GetCode());

        // serialization
        Json::Value j;
        j["name"] = result.GetName();
        j["code"] = result.GetCode();
        Json::StreamWriterBuilder builder;
        builder["indentation"] = "";
        return Json::writeString(builder, j);
    }
}