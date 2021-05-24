# Falling Forty-two

## Install Cocos2d-x library (all platforms)

Add i386 to the list of architectures `apt` will look for when searching for packages:

    sudo dpkg --add-architecture i386

Install the following dependencies (Ubuntu 18.04):

    sudo apt-get update && apt-get upgrade
    sudo apt-get install python-minimal git curl unzip g++ libgdk-pixbuf2.0-dev python-pip cmake libx11-dev libxmu-dev libglu1-mesa-dev libgl2ps-dev libxi-dev libzip-dev libpng-dev libcurl4-gnutls-dev libfontconfig1-dev libsqlite3-dev libglew-dev libssl-dev libgtk-3-dev libglfw3 libglfw3-dev xorg-dev

If running another version of Ubuntu, see https://docs.cocos2d-x.org/cocos2d-x/v3/en/installation/Linux.html for more information on the dependencies to install (although this guide is known to be incomplete)

Setup your environment variables by appending the following lines to your `.bashrc` or `.profile`:

    export COCOS_X_ROOT="/opt/cocos2d-x"
    export COCOS_CONSOLE_ROOT="$COCOS_X_ROOT/tools/cocos2d-console/bin"
    export COCOS_TEMPLATES_ROOT="$COCOS_X_ROOT/templates"
    export PATH="$COCOS_X_ROOT:$COCOS_CONSOLE_ROOT:COCOS_TEMPLATES_ROOT:$PATH"

Clone the Cocos2d-x library repository and checkout on the 4.0 tag:

    git -c advice.detachedHead=false clone -b "cocos2d-x-4.0" --single-branch "https://github.com/cocos2d/cocos2d-x.git" "$COCOS_X_ROOT"
    cd "$COCOS_X_ROOT"

Setup the Cocos2d-x library:

    git submodule update --init && git submodule update
    python2 "download-deps.py" -r yes
    ./install-deps-linux.sh

Make sure everything is ready to compile for Linux:

    mkdir -p "build/linux-build" && cd "build/linux-build"
    cmake -DCMAKE_BUILD_TYPE=Release "../.." && make -j $(nproc)

If running Ubuntu 20.04, you *might* need to install the following packages (see https://discuss.cocos2d-x.org/t/cocos2d-x-4-0-setup-on-ubuntu-20-04-1-lts/51251):

    sudo apt install libglfw3 libglfw3-dev
    sudo apt install libxxf86vm1 libxxf86vm-dev libxxf86vm1-dbg

If running Ubuntu 20.04, the pre-compiled `libchipmunk.a` binary in the `external/chipmunk/prebuilt/linux/64-bit/libchipmunk.a` directory won't work and you need to replace it by this one: https://github.com/cocos2d/cocos2d-x/files/4272227/libchipmunk7.0.1.zip (see https://github.com/cocos2d/cocos2d-x/issues/20471)

## Install Android SDK (Android only)

Setup your environment variables by appending the following lines to your `.bashrc` or `.profile`:

    export ANDROID_SDK_ROOT="/opt/android_sdk"
    export NDK_ROOT="$ANDROID_SDK_ROOT/ndk/16.1.4479499"
    export CMAKE_ROOT="$ANDROID_SDK_ROOT/cmake/3.10.2.4988404"
    export PATH="$ANDROID_SDK_ROOT:$ANDROID_SDK_ROOT/tools/bin:$ANDROID_SDK_ROOT/tools:$ANDROID_SDK_ROOT/platform-tools:$NDK_ROOT:$PATH:$CMAKE_ROOT/bin"

Install the Java 8 JRE and JDK:

    sudo apt-get install openjdk-8-jdk openjdk-8-jre

Download the Android SDK:

    mkdir -p "ANDROID_SDK_ROOT" && cd "$ANDROID_SDK_ROOT"
    curl "https://dl.google.com/android/repository/sdk-tools-linux-4333796.zip" -o "tools.zip" && unzip "tools.zip" && rm "tools.zip"

Accept the SDK licenses:

    sdkmanager --licenses
  
Install the following plugins:

    sdkmanager --install 'platforms;android-28'
    sdkmanager --install 'ndk;16.1.4479499'
    sdkmanager --install 'cmake;3.10.2.4988404'

Install Ninja as it is required by CMake:

    sudo apt-get install ninja-build (see https://stackoverflow.com/questions/54500937/cocos2d-x-android-build-failed)

Make sure everything is ready to compile for Android:

    cd "$COCOS_X_ROOT/tests/cpp-tests/proj.android"
    printf "sdk.dir=$ANDROID_SDK_ROOT\nndk.dir=$NDK_ROOT\ncmake.dir=$CMAKE_ROOT\n" >> "local.properties"
    ./gradlew assembleDebug

## Build and run Falling Forty-two on Linux

Build the Falling Forty-two binary using CMake and make

    cd fallingfortytwo
    mkdir "build" && cd "build"
    cmake -DCMAKE_BUILD_TYPE=Debug ".." && make -j $(nproc)

Run the generated binary

    cd bin/fallingfortytwo
    ./fallingfortytwo

## Build Falling Forty-two for Android and deploy on device

Setup gradle so it knows where to find the Android SDK, NDK and CMake

    cd fallingfortytwo/android
    printf "sdk.dir=$ANDROID_SDK_ROOT\nndk.dir=$NDK_ROOT\ncmake.dir=$CMAKE_ROOT\n" >> "local.properties"

Start gradle using the gradle wrapper (see https://developer.android.com/studio/build/building-cmdline)

    ./gradlew assembleDebug

Connect an Android device and install the generated binary using the gradle wrapper (see https://developer.android.com/studio/build/building-cmdline)

    ./gradlew installDebug
