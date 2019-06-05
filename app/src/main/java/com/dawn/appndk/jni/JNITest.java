package com.dawn.appndk.jni;

import com.dawn.appndk.bean.Person;
import com.dawn.appndk.bean.Student;

import java.util.Date;

public class JNITest {
    public String key = "hello world !! ";
    public static String keyName = "hello !! !!! !!";

    public Person person = new Student();

    public native String stringFromJNI();

    public native String accessStaticField();

    public native String accessStaticMethod();

    public native Date accessConstructor();
    //获取父类的方法
    public native void accessNonvirtualMethod();
}
