@ECHO OFF
setlocal enabledelayedexpansion
pushd %~dp0..

:: Get All Source Files
pushd src
set source_files=
for /r %%f in (*.c) do set source_files=!source_files! %%f
popd

:: Choose clang As Compiler
set clang=1

:: Unpack Build Arguments
for %%a in (%*) do set "%%a=1"
if "%debug%"=="1"   set release=0 && echo [debug mode]
if "%release%"=="1" set debug=0 && echo [release mode]
if "%clang%"=="1" echo [clang compile]

:: Compile/Link Line Definitions
set clang_common=  -I..\src\ -Wall -Werror -Wextra
set clang_debug=   call clang -g -O0 -DDEBUG=1 %clang_common%
set clang_release= call clang -O2 -DDEBUG=0 %clang_common%
set clang_link=
set clang_out= -o

:: Choose Compile/Link Lines
if "%clang%"=="1"   set compile_link=%clang_link%
if "%clang%"=="1"   set out=%clang_out%
if "%debug%"=="1"   set compile=%clang_debug%
if "%release%"=="1" set compile=%clang_release%

:: Prepare Build Directory
if not exist build mkdir build

:: Build Program
pushd build
%compile% %source_files% %compile_link% %out%HexForge.exe || exit /b 1
popd
echo [build success]
