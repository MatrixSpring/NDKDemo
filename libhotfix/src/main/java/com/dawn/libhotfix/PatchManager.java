package com.dawn.libhotfix;

import android.content.Context;

import java.io.File;

public class PatchManager {
    private Context context;
    private AndFixManager andManager;
    public PatchManager(Context context) {
        this.context = context;
        init();
    }

    private void init(){
        andManager = new AndFixManager(context);
    }

    public void loadPatch(String path){
        File file = new File(path);
        Patch patch = new Patch(context, file);
    }
}
