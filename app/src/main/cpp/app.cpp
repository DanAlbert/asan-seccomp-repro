#include <jni.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_android_developer_asantest_MainActivity_stringFromJNI(JNIEnv *env, jobject) {
    return env->NewStringUTF("Hello, world!");
}
