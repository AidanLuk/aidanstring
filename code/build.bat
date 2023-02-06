@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build
cl -Zi ..\code\aidan_string.c 
popd