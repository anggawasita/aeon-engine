#!/bin/bash

export RASPBERRY_PI_SDK_ROOT=/opt/vc

rm -rf build
mkdir build
cd build
cmake ../ -DAEON_GFX_RENDERER=GLES2 -DAEON_PLATFORM=RaspberryPi -DAEON_SKIP_COPY_ASSETS_TO_RUNTIME_PATH=1
cd ..
