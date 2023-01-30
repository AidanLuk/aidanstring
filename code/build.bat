@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
cl -Zi ..\code\aidanstring.c 
popd