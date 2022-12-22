@echo off
color 2
echo *************************************************************************************
echo   *****************WELCOME TO EXWORLD PROJECT GENERATOR*************************
echo                ******************************************                           
echo          ******************************************************* 
echo                **************************************
echo                    ************************
echo                           ************
echo                               ****
echo                                **
set rootpath=%~dp0
set /p enginepath="Where is your Unreal Engine Path located? "
echo %enginepath%


set wd="%rootpath%Binaries"
IF EXIST "%wd%" 	(
	rmdir /s /q %wd%
) 
set wd="%rootpath%.vs"
IF EXIST "%wd%" 	(
	rmdir /s /q %wd%
) 
set wd="%rootpath%Intermediate"
IF EXIST "%wd%" 	(
	rmdir /s /q %wd%
) 
set wd="%rootpath%Saved"
IF EXIST "%wd%" 	(
	rmdir /s /q %wd%
) 
set wd="%rootpath%Demotest.sln"
IF EXIST "%wd%" 	(
	rmdir /s /q %wd%
) 

cmd /C "%enginepath%\Engine\Build\BatchFiles\GenerateProjectFiles.bat %rootpath%Demotest.uproject"
IF ERRORLEVEL 3 (ECHO Please Check the Pathof the engine and then try again Example: C:\UnrealEngine-4.24 <- Something like this. PRESS ENTER AND TRY AGAIN
pause
exit
)
IF ERRORLEVEL 2 (ECHO Please Check the Pathof the engine and then try again Example: C:\UnrealEngine-4.24 <- Something like this. PRESS ENTER AND TRY AGAIN
pause
exit
)
IF ERRORLEVEL 1 (ECHO Please Check the Pathof the engine and then try again Example: C:\UnrealEngine-4.24 <- Something like this. PRESS ENTER AND TRY AGAIN
pause
exit
)

cmd /C "%enginepath%\Engine\Binaries\DotNET\UnrealBuildTool.exe Development Win64 -Project=%rootpath%Demotest.uproject -TargetType=Editor -Progress -NoHotReloadFromIDE"
cmd /C "%rootpath%Demotest.uproject"

set /p test="Opening the DemoTest Project............. "