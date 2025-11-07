#include <jni.h>

#include <game-activity/GameActivity.h>
#include <game-activity/native_app_glue/android_native_app_glue.h>

// #include "Renderer.h"

#include <android/log.h>
#include <sstream>

extern std::ostream aout;

void Main() {
    aout << "Hello world" << std::endl;
}