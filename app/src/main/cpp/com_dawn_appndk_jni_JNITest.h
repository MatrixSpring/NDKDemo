/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_dawn_appndk_jni_JNITest */

#ifndef _Included_com_dawn_appndk_jni_JNITest
#define _Included_com_dawn_appndk_jni_JNITest
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_dawn_appndk_jni_JNITest
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_stringFromJNI(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_accessStaticField(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_accessMethod(JNIEnv *, jobject);

JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_accessStaticMethod(JNIEnv *, jobject);
//访问构造方法
JNIEXPORT jobject JNICALL Java_com_dawn_appndk_jni_JNITest_accessConstructor(JNIEnv *, jobject);
//访问父类的方法
JNIEXPORT void JNICALL Java_com_dawn_appndk_jni_JNITest_accessNonvirtualMethod(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
