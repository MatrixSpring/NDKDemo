package com.dawn.appndk.jni;

public class JNITest {
    public String key = "hello world !! ";

    public static String keyName = "hello !! !!! !!";

    public native String stringFromJNI();

    public native String accessStaticField();

    public native String accessStaticMethod();
}
