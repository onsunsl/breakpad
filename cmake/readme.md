### android build on windows:

* config

D:\tools\cmake-3.28.3-windows-x86_64\bin\cmake.EXE --no-warn-unused-cli -DCMAKE_INSTALL_PREFIX=output -DCMAKE_C_COMPILER:FILEPATH=D:/Qt/androidSDK/ndk/21.3.6528147/toolchains/llvm/prebuilt/windows-x86_64/bin/clang.exe -DCMAKE_CXX_COMPILER:FILEPATH=D:/Qt/androidSDK/ndk/21.3.6528147/toolchains/llvm/prebuilt/windows-x86_64/bin/clang++.exe -DCMAKE_TOOLCHAIN_FILE:FILEPATH=D:/Qt/androidSDK/ndk/21.3.6528147/build/cmake/android.toolchain.cmake -DANDROID_NATIVE_API_LEVEL:STRING=25 -DANDROID_ABI:STRING=armeabi-v7a -DANDROID_STL:STRING=c++_shared -DANDROID_SDK:PATH=D:/Qt/androidSDK -DANDROID_NDK:PATH=D:/Qt/androidSDK/ndk/21.3.6528147 -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_C_COMPILER:FILEPATH=D:\Qt\androidSDK\ndk\21.3.6528147\toolchains\llvm\prebuilt\windows-x86_64\bin\clang.exe -DCMAKE_CXX_COMPILER:FILEPATH=D:\Qt\androidSDK\ndk\21.3.6528147\toolchains\llvm\prebuilt\windows-x86_64\bin\clang++.exe -SD:/workspace/breakpad/cmake -Bd:/workspace/breakpad/bin -G Ninja

* build
D:\tools\cmake-3.28.3-windows-x86_64\bin\cmake.EXE --build d:/workspace/breakpad/bin --config Debug --target all --


### linux build:
* config
cmake --no-warn-unused-cli -DCMAKE_INSTALL_PREFIX=output -DCMAKE_BUILD_TYPE:STRING=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -S/mnt/d/workspace/breakpad/cmake -B/mnt/d/workspace/breakpad/bin/linux -G Ninja

* build
cmake --build /mnt/d/workspace/breakpad/bin/linux --config Debug --target all


### windows
`src/processor`only supports the GNU(MinGW) compiler on Windows




### run demo
cd bin/bin
dump_syms ./demo > ./demo.sym
mkdir ./symbols/demo/demo_version_from_dump_sym
mv ./demo.sym ./symbols/demo/demo_version_from_dump_sym

./demo
./minidump_stackwalk /mnt/dump/xxxx.dmp ./symbols




