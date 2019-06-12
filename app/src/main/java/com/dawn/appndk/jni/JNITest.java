package com.dawn.appndk.jni;

import com.dawn.appndk.bean.Person;
import com.dawn.appndk.bean.Student;

import java.util.Date;

public class JNITest {
    static {
        System.loadLibrary("native-lib");
        //初始化全局变量
        initGlobalIds();
    }

    public String key = "hello world !! ";
    public static String keyName = "hello !! !!! !!";

    public Person person = new Student();

    public native String stringFromJNI();

    public native String accessStaticField();

    public native String accessStaticMethod();

    public native Date accessConstructor();
    //获取父类的方法
    public native void accessNonvirtualMethod();
    //捕获异常
    public native void catchException();
    //jni缓存
    public native void jniCache();
    //jni缓存initIds
    public native static void initGlobalIds();
}
