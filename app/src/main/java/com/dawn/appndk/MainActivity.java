package com.dawn.appndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.dawn.appndk.jni.JNITest;

import java.util.Date;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    JNITest jniTest;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        jniTest = new JNITest();
        tv.setText(jniTest.key+" : "+jniTest.stringFromJNI()+" :stringFromJNI"+stringFromJNI()+" : "+jniTest.key);

        tv.setText(JNITest.keyName+" : "+jniTest.accessStaticField()+"  : "+JNITest.keyName);

        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                jniTest.accessNonvirtualMethod();

            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
