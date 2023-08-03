# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.22.1)

# Declares and names the project.

project("staticlibtest")

set(CMAKE_CXX_STANDARD 11)
set(libs_DIR ${CMAKE_SOURCE_DIR}/../../../libs)
#set(ANDROID_ABI "arm64-v8a")
#add_library(_static_test STATIC IMPORTED)
#set_target_properties(_static_test PROPERTIES IMPORTED_LOCATION /Users/tars/AndroidStudioProjects/StaticLibTest/app/libs/lib_static_test.a)
add_library(lib_common STATIC IMPORTED)
set_target_properties(lib_common PROPERTIES IMPORTED_LOCATION /Users/tars/AndroidStudioProjects/StaticLibTest/app/libs/liblib_common.a)

#target_link_libraries(_static_test INTERFACE lib_common)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        staticlibtest

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        staticlibtest

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        lib_common)

target_include_directories(staticlibtest PUBLIC /Users/tars/AndroidStudioProjects/StaticLibTest/app/libs/include)
#target_link_libraries(staticlibtest PRIVATE static_test)
