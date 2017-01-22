@ECHO OFF

REM build boost
REM C:\Libs\boost\boost_1_53_0>b2 -j4 --build-dir=build --stagedir=stage variant=release link=shared threading=multi runtime-link=shared stage

IF EXIST build rmdir /S /Q build
mkdir build

REM configure
cmake -H. -Bbuild^
	-DBOOST_ROOT="C:\Libs\boost\boost_1_53_0" ^
	-DBOOST_LIBRARYDIR="C:\Libs\boost\boost_1_53_0\stage\lib" ^
	-DCPPUNIT_INCLUDE_DIR="C:\Libs\cppunit\cppunit-1.12.1\include" ^
	-DCPPUNIT_LIBRARY_RELEASE="C:\Libs\cppunit\cppunit-1.12.1\lib\cppunit.lib" ^
	-DBUILD_TESTS=1


REM	-DZLIB_INCLUDE_DIR="%ZLIB_DIR%" ^
REM	-DZLIB_LIBRARY="%ZLIB_DIR%"

REM cmake -G "Visual Studio 10 2010" -D BOOST_ROOT="C:\Libs\boost\boost_1_53_0" -D BOOST_LIBRARYDIR="C:\Libs\boost\boost_1_53_0\stage\lib" -H. -Bbuild

REM build
cmake --build build --config Release --
cmake --build build --config Release --target doc

REM start tests
cd build
set PATH=%PATH%;C:\Libs\boost\boost_1_53_0\stage\lib
ctest -V -C Release
cd ..