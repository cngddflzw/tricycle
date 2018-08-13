//
// Created by Zhenwei Liu on 2018/8/7.
//

#include <tricycle.hpp>

namespace tricycle {

    map<const string, const Invoker *> InvokerManager::invoker_map_ = map<const string, const Invoker *>();

    static string CreateKey(const string &class_name, const string &func_name) {
        return class_name + "::" + func_name;
    }

    void InvokerManager::Register(const string &class_name, const string &func_name, const Invoker *val) {
        invoker_map_[CreateKey(class_name, func_name)] = val;
    }

    const Invoker *InvokerManager::GetInvoker(const string &class_name, const string &func_name) {
        return invoker_map_[CreateKey(class_name, func_name)];
    }
}
