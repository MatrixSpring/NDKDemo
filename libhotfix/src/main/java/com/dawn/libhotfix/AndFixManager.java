package com.dawn.libhotfix;

import android.content.Context;
import android.os.Build;

import java.io.File;

import dalvik.system.DexClassLoader;
import dalvik.system.DexFile;

public class AndFixManager {
    private Context context;
    private File optFile;

//    public AndFixManager(Context context) {
//        this.context = context;
//        handlerNative.init(Build.VERSION.SDK_INT);
//    }
//
//    public void fix(File file, final ClassLoader classLoader){
//        optFile = new File(context.getFilesDir(), file.getName());
//        if(optFile.exists()){
//            optFile.delete();
//        }
//        try {
//            final DexFile dexFile = DexFile.loadDex();
//            ClassLoader classLoader1 = findClass();
//        }catch (Exception e){
//            e.printStackTrace();
//        }
//    }
}
