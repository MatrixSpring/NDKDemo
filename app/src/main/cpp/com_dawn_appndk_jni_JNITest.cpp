//
// Created by dawn on 2019/6/2.
//
#include <string>
#include "com_dawn_appndk_jni_JNITest.h"

JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_stringFromJNI(JNIEnv *env, jobject jobj){
    std::string hello = "Hello from C++ ";
    // 使用GetObjectClass方法获取obj对应的jclass。
    jclass cls = env->GetObjectClass(jobj);
    //fieldID
    jfieldID strID = env->GetFieldID(cls,"key","Ljava/lang/String;");
    //获取java属性的值
    jstring jstr = (jstring)env->GetObjectField(jobj,strID);
    //拷贝到数组指针中
    const char *pszStr = env->GetStringUTFChars(jstr,JNI_FALSE);
    //生成新的string对象
    jstring new_str = env->NewStringUTF("xxXXXX");
    //释放new的对象
    env->ReleaseStringUTFChars(jstr,pszStr);
    //设置新的值
    env->SetObjectField(jobj,strID,new_str);

   return env->NewStringUTF(hello.c_str());
};

//访问静态属性
JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_accessStaticField(JNIEnv *env, jobject jobj){
     std::string hello = "Hello from C++ gfgfgfgfgf";
      // 使用GetObjectClass方法获取obj对应的jclass。通过对象获取类
      jclass cls = env->GetObjectClass(jobj);
      //fieldID
      jfieldID strID = env->GetStaticFieldID(cls,"keyName","Ljava/lang/String;");
      //获取java属性的值
      jstring jstr = (jstring)env->GetStaticObjectField(cls,strID);
      //拷贝到数组指针中
      const char *pszStr = env->GetStringUTFChars(jstr,JNI_FALSE);
      //
      jstring new_str = env->NewStringUTF("xxXXXXffff");
      env->ReleaseStringUTFChars(jstr,pszStr);

      env->SetStaticObjectField(cls,strID,new_str);

     return env->NewStringUTF(hello.c_str());
};

//访问方法
JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_accessMethod(JNIEnv *env, jobject jobj){
   std::string hello = "Hello from C++ gfgfgfgfgf";
   //jobject cls = (*env)->GetObjectClass(env, jobj);
   // jclass cls = env->GetObjectClass(jobj);       // 使用GetObjectClass方法获取obj对应的jclass。
    //fieldID
    //jfieldID strID = env->GetMethodID(cls,"key","Ljava/lang/String;");
    //获取java属性的值
    //jstring jstr = (jstring)env->GetObjectField(jobj,strID);
    //拷贝到数组指针中
    //const char *pszStr = env->GetStringUTFChars(jstr,JNI_FALSE);
    //
    //jstring new_str = env->NewStringUTF("xxXXXX");
    //env->ReleaseStringUTFChars(jstr,pszStr);

    //env->SetObjectField(jobj,strID,new_str);

   return env->NewStringUTF(hello.c_str());
};

//访问静态方法
JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_accessStaticMethod(JNIEnv *env, jobject jobj){
   std::string hello = "Hello from C++ gfgfgfgfgf";
   //jobject cls = (*env)->GetObjectClass(env, jobj);
    jclass cls = env->GetObjectClass(jobj);       // 使用GetObjectClass方法获取obj对应的jclass。
    //fieldID
    jfieldID strID = env->GetFieldID(cls,"key","Ljava/lang/String;");
    //获取java属性的值
    jstring jstr = (jstring)env->GetObjectField(jobj,strID);
    //拷贝到数组指针中
    const char *pszStr = env->GetStringUTFChars(jstr,JNI_FALSE);
    //
    jstring new_str = env->NewStringUTF("xxXXXX");
    env->ReleaseStringUTFChars(jstr,pszStr);

    env->SetObjectField(jobj,strID,new_str);

   return env->NewStringUTF(hello.c_str());
};

//访问java中的构造函数
JNIEXPORT jstring JNICALL Java_com_dawn_appndk_jni_JNITest_accessConstructor(JNIEnv *env, jobject jobj){
   std::string hello = "Hello from C++ gfgfgfgfgf";
   //jobject cls = (*env)->GetObjectClass(env, jobj);
    jclass cls = env->FindClass("java/util/Date");       // 使用GetObjectClass方法获取obj对应的jclass。
    //fieldID
    jmethodID constructorID =  env->GetMethodID(cls,"<init>","()V");
    //实例化对象
    jobject date_obj = env->NewObject(cls, constructorID);
    //调用 getTime 方法
    jmethodID mid = env->GetMethodID(cls,"getTime", "()J");
    //获取时间戳
    jlong time = env->CallLongMethod(date_obj, mid);

    printf("time :: %l ",time);

   return env->NewStringUTF(hello.c_str());
};


