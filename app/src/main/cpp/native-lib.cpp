#include <jni.h>
#include <string>
#include "common_lib.h"

extern "C" JNIEXPORT jstring JNICALL
Java_cool_tars_staticlibtest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    Calculator calculator;
    int result = calculator.Add(1, 1);
    std::string result_description = "Calculator got 1 + 1 = " + std::to_string(result);
    hello = hello + "\n" + result_description;
    return env->NewStringUTF(hello.c_str());
}