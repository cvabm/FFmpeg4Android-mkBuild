### FFmpeg4Android-mkBuild
Android.mk方式编译ffmpeg  
参考：https://righere.github.io/2016/10/10/build-ffmpeg4Android/

ndk版本：android-ndk-r14b  

1、直接运行：app显示所有编解码器，并打印日志：my name is xx  
2、编译.so包供其他app使用：在jni目录下执行ndk-build，生成目录src/main/libs/armeabi