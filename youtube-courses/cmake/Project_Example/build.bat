mkdir build & cd build
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../cmake/arm_toolchain.cmake ..
cmake --build .