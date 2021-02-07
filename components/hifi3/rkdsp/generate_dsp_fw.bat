@echo off
setlocal enabledelayedexpansion
if "%1%"=="" (
    echo Pleae input project name
    echo Usage:
    echo   %0% ^<project name^> [config file]
    echo       ^<project name^> is necessary
    echo       [config  file] is optional
    echo Example:
    echo   %0% RK2108 FwConfig.xml
    goto end
)

SET project=%1
if not exist projects\%project%\Makefile (
    echo Cannot find projects\%project%\Makefile
    echo Please check your project name
    goto end
)
for /f "tokens=*" %%a in (projects\%project%\Makefile) do (
    set cmd_str=%%a
)
set "cmd_str=!cmd_str:""= !"

for /f "tokens=2 delims==" %%a in (projects\%project%\Makefile) do (
    set path_str=%%a
)
for /f "tokens=1* delims=; " %%a in ("!path_str!") do (
    set path_str=%%a
)

:stringLOOP
    for /f "tokens=1* delims=\\ " %%a in ("!cmd_str!") do (
        set substring=%%a
        if "!substring!" EQU "bin" (
            set configuration_str=%%b
            goto endLOOP
        )
        set cmd_str=%%b
    )
    if "!cmd_str!" NEQ "" goto stringLOOP
)
:endLOOP
for /f "tokens=1-2 delims=\\ " %%a in ("!configuration_str!") do (
    set configuration=%%a
    set target=%%b
)

if "%2%"=="" (
    SET config=FwConfig.xml
) else (
    SET config=%2
)

echo Project: %project%
echo Target : %target%
echo Config : %config%
echo Configuration: %configuration%
echo ToolsPath: %path_str%

if not exist projects\%project%\bin\%configuration%\%target%\%project% (
    echo Cannot find projects\%project%\bin\%configuration%\%target%\%project%
    echo Please check your project name
    goto end
)
if not exist projects\%project%\%config% (
    echo Cannot find projects\%project%\%config%
    goto end
)

if exist tools\HifiFirmwareGenerator\Bin2Array.xml (
    del tools\HifiFirmwareGenerator\Bin2Array.xml
)
if exist projects\%project%\Bin2Array.xml (
    copy projects\%project%\Bin2Array.xml tools\HifiFirmwareGenerator\Bin2Array.xml
)

if not exist tools\HifiFirmwareGenerator\input (
    md tools\HifiFirmwareGenerator\input
)

if exist tools\HifiFirmwareGenerator\FwConfig.xml (
    del tools\HifiFirmwareGenerator\FwConfig.xml
)
type nul > tools\HifiFirmwareGenerator\FwConfig.xml
for /f "tokens=*" %%a in (projects\%project%\%config%) do (
    set tmp=%%a
    set "tmp=!tmp:tag_corename=%configuration%!"
    set "tmp=!tmp:tag_toolspath=%path_str%!"
    echo !tmp!>>tools\HifiFirmwareGenerator\FwConfig.xml
)

copy projects\%project%\bin\%configuration%\%target%\%project% tools\HifiFirmwareGenerator\input
cd tools\HifiFirmwareGenerator\
HifiFirmwareGenerator.exe
FirmwareArrayGenerator.exe
cd ..\..\

:end
endlocal
