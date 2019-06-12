package com.dawn.libhotfix;

import android.content.Context;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.jar.Attributes;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;
import java.util.jar.Manifest;

/**
 * 将修改了的patch-class文件加载到内存中
 * 进行解析 找到解析的出错标识
 * 将出错标识添加到hashmap中
 * 使用修复的方法替换老的错误的方法
 */
public class Patch {
    private Context mContext;
    private File mFile;
    private Map<String,List<String>> mClassMap;

    public Patch(Context mContext, File mFile) {
        this.mContext = mContext;
        this.mFile = mFile;
    }

    /**
     *
     */
    private void init(){
        JarFile jarFile = null;
        InputStream inputStream = null;
        mClassMap = new HashMap<>();
        List<String> list = new ArrayList<>();
        try {
            jarFile = new JarFile(mFile);
            JarEntry jarEntry = jarFile.getJarEntry("META-INF/PATCH.MF");
            inputStream = jarFile.getInputStream(jarEntry);

            Manifest manifest = new Manifest(inputStream);
            //通过manifest 拿到mf文件里面的key-value
            Attributes attributes = manifest.getMainAttributes();
            Attributes.Name attrName;
            for(Iterable<?> ite = (Iterable<?>) attributes.keySet().iterator(); ((Iterator) ite).hasNext();){
                attrName = (Attributes.Name) ((Iterator) ite).next();
                if(null != attrName){
                    String name = attrName.toString();
                    if(name.endsWith("Classes")){
                        //声明一个集合
                        list = Arrays.asList(attributes.getValue(name).split(","));
                        if(name.equalsIgnoreCase("Patch-Classes")){
                            mClassMap.put(name, list);
                        }else{
                            mClassMap.put(name.trim().substring(0, name.length()-8), list);
                        }
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try {
                inputStream.close();
                jarFile.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


}
