package com.soft.demo11;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    //jni
    public native String avcodecInfo();

    static {
        System.loadLibrary("FFmpegCodec");
        System.loadLibrary("avcodec");
        System.loadLibrary("avfilter");
        System.loadLibrary("avformat");
        System.loadLibrary("avutil");
        System.loadLibrary("swresample");
        System.loadLibrary("swscale");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView Codec_info = (TextView) findViewById(R.id.TextView_codec_info);
        Codec_info.setMovementMethod(ScrollingMovementMethod.getInstance());
        Codec_info.setText(avcodecInfo());

        new Player().runNative();

    }
}
