//
// Created by Zhenwei Liu on 2018/8/7.
//

#ifndef TRICYCLE_TRICYCLE_HPP
#define TRICYCLE_TRICYCLE_HPP

#include <string>
#include "json.h"

using namespace std;

namespace tricycle {

    class Invoker {
    public:
        virtual string Invoke(const Json::Value &json_array) const = 0;
    };

    class InvokerManager {
    private:
        static map<const string, const Invoker *> invoker_map_;

    public:
        static void Register(const string &class_name, const string &func_name, const Invoker *val);

        static const Invoker *GetInvoker(const string &class_name, const string &func_name);
    };

}

#endif

#ifndef TRICYCLE_CREATE_CLS
#define TRICYCLE_CREATE_CLS(class_name, func_name, instance) \
class TRICYCLE_CREATE_CLAZZ_NAME(class_name, func_name): public Invoker {\
private: \
    class_name* TRICYCLE_CREATE_INSTANCE_NAME(class_name, func_name); \
public: \
    TRICYCLE_CREATE_CLAZZ_NAME(class_name, func_name)(class_name *i) { \
        TRICYCLE_CREATE_INSTANCE_NAME(class_name, func_name) = i; \
    } \
    string Invoke(const Json::Value &json_array) const { \
        return TRICYCLE_CREATE_INSTANCE_NAME(class_name, func_name)->func_name(json_array); \
    } \
}; \
InvokerManager::Register(#class_name, #func_name, new TRICYCLE_CREATE_CLAZZ_NAME(class_name, func_name)(instance));
#endif

#ifndef TRICYCLE_CREATE_INSTANCE_NAME
#define TRICYCLE_CREATE_INSTANCE_NAME(class_name, func_name) TRICYCLE_CREATE_NAME(class_name, func_name, INSTANCE)
#endif

#ifndef TRICYCLE_CREATE_CLAZZ_NAME
#define TRICYCLE_CREATE_CLAZZ_NAME(class_name, func_name) TRICYCLE_CREATE_NAME(class_name, func_name, CLAZZ)
#endif

#ifndef TRICYCLE_CREATE_NAME
#define TRICYCLE_CREATE_NAME(class_name, func_name, suffix) class_name##_##func_name##_##suffix
#endif

#ifndef TRICYCLE_FUNC_KEY
#define TRICYCLE_FUNC_KEY(class_name, func_name) TRICYCLE_TO_STR(class_name##_##func_name##_ivk)
#endif

#ifndef TRICYCLE_TO_STR
#define TRICYCLE_TO_STR(A) #A
#endif
