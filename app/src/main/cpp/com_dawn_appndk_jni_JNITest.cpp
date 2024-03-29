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
JNIEXPORT jobject JNICALL Java_com_dawn_appndk_jni_JNITest_accessConstructor(JNIEnv *env, jobject jobj){
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

    //printf("time :: %l ",time);

   return date_obj;
};

//调用父类的方法
JNIEXPORT void JNICALL Java_com_dawn_appndk_jni_JNITest_accessNonvirtualMethod(JNIEnv *env, jobject jobj){
    //获取Java中定义jni接口对象的类
    jclass jcls = env->GetObjectClass(jobj);
    //获取这个类中的属性id
    jfieldID jfid= env->GetFieldID(jcls,"person","Lcom/dawn/appndk/bean/Person;");
    //获取属性值
    jobject jobj_person = env->GetObjectField(jobj,jfid);
    //执行属性中的方法
    //1.获取方法所在的类
    jclass jclas_person = env->FindClass("com/dawn/appndk/bean/Person");
    //2.获取类中的方法签名
    jmethodID jmid = env->GetMethodID(jclas_person, "playerGame", "()V");
    //3.执行方法
    //env->CallObjectMethod(jobj_person,jmid);
    env->CallNonvirtualObjectMethod(jobj_person,jclas_person,jmid);
};

//jni异常捕获 保证Java的继续执行
JNIEXPORT void JNICALL Java_com_dawn_appndk_jni_JNITest_catchException(JNIEnv *env, jobject jobj){
    jclass cls = env->GetObjectClass(jobj);
    jfieldID fid = env->GetFieldID(cls, "key2", "Ljava/lang/String;");
    //检测是否发生Java异常
    jthrowable exception = env->ExceptionOccurred();
    if(exception != NULL){
        //让Java代码可以继续运行
        //清空异常信息
        env->ExceptionClear();

    }
    //通过ThrowNew抛出异常
    //env->ThrowNew();
};

//jni缓存的使用
JNIEXPORT void JNICALL Java_com_dawn_appndk_jni_JNITest_jniCache(JNIEnv *env, jobject jobj){
    jclass cls = env->GetObjectClass(jobj);
    //获取jfieldID只获取一次
    //局部静态变量 作用域在函数里但是生命周期是全局的
    static jfieldID key_id = NULL;
    if(key_id == NULL){
        key_id = env->GetFieldID(cls, "key", "Ljava/lang/String;");
    }

};

//jni缓存的使用initIds 全局变量初始化
jfieldID key_fid;
jmethodID random_mid;
JNIEXPORT void JNICALL Java_com_dawn_appndk_jni_JNITest_initGlobalIds(JNIEnv *env, jobject jobj){
    jclass cls = env->GetObjectClass(jobj);
    key_fid = env->GetFieldID(cls, "key","Ljava/lang/String;");
    random_mid = env->GetMethodID(cls, "gentRandomInt", "<I>I");
};