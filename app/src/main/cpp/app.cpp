#include <jni.h>
#include <string>

void foo() {
#ifdef __LP64__
    throw 42;
#else
    throw 24;
#endif
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_android_developer_asantest_MainActivity_stringFromJNI(JNIEnv *env, jobject) {
    std::string hello;
    try {
        foo();
        hello = "Caught nothing";
    } catch (const int &ex) {
        hello = std::string("Caught ") + std::to_string(ex);
    }
    return env->NewStringUTF(hello.c_str());
}
