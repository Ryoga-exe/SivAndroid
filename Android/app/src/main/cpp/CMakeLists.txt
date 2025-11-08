cmake_minimum_required(VERSION 3.22.1)
project(test CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(Siv3D REQUIRED CONFIG)
find_package(game-activity REQUIRED CONFIG)  # 明示しておくと安全

add_library(test SHARED Main.cpp)

target_link_libraries(test PRIVATE
        siv3d::Siv3D
        game-activity::game-activity_static  # 伝播してても明示推奨
        android
        log
        EGL
        GLESv3
        jnigraphics
        ${CMAKE_DL_LIBS}                      # 念のため（dlsym 等）
)

# GameActivity の JNI 初期化関数 & あなたの android_main を“必ず残す”
target_link_options(test PRIVATE
        "-uJava_com_google_androidgamesdk_GameActivity_initializeNativeCode"
        "-uandroid_main"
)
