:------------------------------------------------------------------------------
: Update script for TX Library - (c) Ded, 2010-14
:------------------------------------------------------------------------------
@echo off
@setlocal enableextensions enabledelayedexpansion 2>nul & if errorlevel == 1 (set ./v=0)
@if "%1" == "#" shift & shift & goto %2
@set #0="%~f0"
@echo.

 (set do=@ECHO) & (set log=con)
 (set do=)      & (set log="%temp%\TX%~n0.log")
:(set do=)      & (set log=nul)

@echo.                                                           >> %log% 2>>&1

:------------------------------------------------------------------------------
:main

set target=%~dp0..

set links="http://storage.ded32.net.ru/Lib/TX/TXLib Update.url"

set clean="TXLib Update.*", "*.tmp"

:------------------------------------------------------------------------------

for %%1 in (wget md5sum sed wait) do (
    set %%1="%~dp0%%1.exe"
    if not "%./v%" == "0" if not exist !%%1! set %%1=%%1.exe
    )
                                                                
%do% pushd %target%                                              >> %log% 2>>&1

@echo TXLib Update started:  %DATE% %TIME%, Folder %CD%
@echo TXLib Update started:  %DATE% %TIME%, Folder %CD%          >> %log% 2>>&1
@echo.                                                           >> %log% 2>>&1

for %%1 in (%clean%) do %do% del "%%~1"                          >> %log% 2>>&1

%do% %wget% --no-check-certificate %links% -O "TXLib Update.links.tmp" >> %log% 2>>&1

@echo Update links:                                              >> %log% 2>>&1
type "TXLib Update.links.tmp"                                    >> %log% 2>>&1
@echo.                                                           >> %log% 2>>&1

for /f "usebackq tokens=*" %%A in ("TXLib Update.links.tmp") do (

    %do% call %#0% # update-from %%A                             >> %log% 2>>&1
    )

call "TXLib Update"                                              >> %log% 2>>&1
                                                                
for %%1 in (%clean%) do %do% del "%%~1"                          >> %log% 2>>&1
                                                                
@echo TXLib Update finished: %DATE% %TIME%, Folder %CD%          >> %log% 2>>&1
@echo TXLib Update finished: %DATE% %TIME%, Folder %CD%                                 
                                                                
%do% popd                                                        >> %log% 2>>&1

@echo.                                                           >> %log% 2>>&1
@echo ********************************************************** >> %log% 2>>&1

title Update Finished

%do% %wait% 5                                                   2>> %log%
goto eof

:------------------------------------------------------------------------------
:update-from

@echo %#0% %1:
@echo.

%do% %wget%   --no-check-certificate "%~1TXLib Update.md5" -O - | %do% %sed% "s/\\/\//g"            > "TXLib Update.md5.tmp"
%do% %md5sum% -c                        "TXLib Update.md5.tmp"  | %do% %sed% -n "/FAILED/ s/:.*//p" > "TXLib Update.tmp"
@echo.

@echo Update list:
type "TXLib Update.tmp"
@echo.

for /f "usebackq tokens=*" %%A in ("TXLib Update.tmp") do (

    @echo Updating "%%~A":

    %do% md                             "%%~dpA"
    %do% %wget% --no-check-certificate "%~1%%~A" -O "%%~fA.tmp"
    if not errorlevel 1 %do% move /y                "%%~fA.tmp" "%%~fA"
    
    @echo.
    )
    
@echo Done
@echo.

goto eof

:------------------------------------------------------------------------------
:eof
