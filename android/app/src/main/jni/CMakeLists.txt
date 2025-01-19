cmake_minimum_required(VERSION 3.13)

# Define the library name here.
project(appmodules)

# This file includes all the necessary to let you build your React Native application
include(${REACT_ANDROID_DIR}/cmake-utils/ReactNative-application.cmake)

# Define where the additional source code lives. We need to crawl back the jni, main, src, app, android folders
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ../../../../../shared/NativeSampleModule.cpp)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ../../../../../shared/NativeDnd.cpp)

# Define where CMake can find the additional header files. We need to crawl back the jni, main, src, app, android folders
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ../../../../../shared)

# Path to the .so file
# set(SO_FILE ${CMAKE_SOURCE_DIR}/android/app/src/main/jniLibs/${ANDROID_ABI}/libCommApi.so)
# target_link_libraries(${CMAKE_PROJECT_NAME} ${SO_FILE})