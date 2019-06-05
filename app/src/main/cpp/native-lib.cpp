#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_dawn_appndk_MainActivity_stringFromJNI(JNIEnv* env, jobject jobj/* this */) {
    std::string hello = "Hello from C++";
    //jobject cls = env->GetObjectClass(env, jobject);
    return env->NewStringUTF(hello.c_str());
}
