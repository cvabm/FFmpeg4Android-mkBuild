#include <stdio.h>
#include "libavformat/avformat.h"
#include <libavfilter/avfilter.h>
#include <jni.h>
#include <android/log.h>
#include <android/log.h>
#define TAG "ljg" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型




JNIEXPORT void JNICALL
Java_com_soft_demo11_Player_runNative(JNIEnv *env, jobject thiz) {
    // TODO: implement runNative()

    char * name = "mronion";
    LOGD("my name is %s\n", name );
}

JNIEXPORT jstring Java_com_soft_demo11_MainActivity_avcodecInfo(JNIEnv* env, jobject obj)
{
    char info[4000] = { 0 };
    int count = 100;  //输出前100个codec名字

    av_register_all();//初始化所有decoder和encoder,注册所有容器类型和codec

    AVCodec *c_temp = av_codec_next(NULL);
    while (c_temp != NULL && count > 0){
        //输出解码器和编码器
        if(c_temp->decode != NULL){
            sprintf(info,"%s[Dec]",info);
        }
        else{
            sprintf(info,"%s[Enc]",info);
        }

        sprintf(info,"%s[%10s]\n",info,c_temp->name);


        c_temp = c_temp->next;
        count--;
    }


    return (*env)->NewStringUTF(env, info);
 }