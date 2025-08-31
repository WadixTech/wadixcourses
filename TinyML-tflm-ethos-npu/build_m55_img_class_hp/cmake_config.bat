cmake -G "Eclipse CDT4 - Ninja" ^
-DTARGET_PLATFORM=ensemble ^
-DTARGET_SUBSYSTEM=RTSS-HP ^
-DTARGET_REVISION=B ^
-DCMAKE_TOOLCHAIN_FILE=scripts/cmake/toolchains/bare-metal-gcc.cmake ^
-DCONSOLE_UART=4 ^
-DCMAKE_BUILD_TYPE=Release ^
-DLOG_LEVEL=LOG_LEVEL_DEBUG ..