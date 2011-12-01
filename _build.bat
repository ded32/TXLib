:-------------------------------------------------
@echo off
@(set do=) & set nul=NUL
:(set do=@ECHO    ) & (set nul=CON)
@if not "%~dp0" == "%temp%\" @(xcopy/ah/y %0 %temp%\ > nul) & @(cmd /v:on /c %temp%\%~nx0 %*) & @(goto end)
@echo %0 %* > %nul%
@if "%1" == "#" goto %2
:-------------------------------------------------

set .cmd=ci doc rar update push

set .file=TXLib-$v$.rar.exe
set .file=%.file:$v: =v%
set .file=%.file: $=%

set .md5="TXLib Update.md5"

if /i "%1" == "" %0 ci doc rar update push

:-------------------------------------------------

for %%1 in (%*) do call %0 # %%1 %*
goto end

:-------------------------------------------------
:ci
echo Committing...

%do% for %%1 in (TXLib.h Dev\*.dox Doc\1_MainPage.txt) do echo.>> %%1
del %%1 > nul 2> nul

 %do% call hg ci
:%do% call hg ci -m "%*"
:%do% call hg kwshrink
:%do% call hg kwexpand

 %do% attrib +h %~nx0

goto end

:-------------------------------------------------
:doc
echo Making docs...

%do% set doxygen_=-nointeractive

%do% copy          Dev\TXLib-Reference.dox > %nul%
%do% call doxygen_     TXLib-Reference.dox
%do% move              TXLib-Reference.chm Dev\ > %nul%
%do% del               TXLib-Reference.dox

%do% copy          Dev\TXLib-Help.dox > %nul%
%do% call doxygen_     TXLib-Help.dox

%do% echo GENERATE_TREEVIEW = YES >> TXLib-Help.dox
%do% echo GENERATE_HTMLHELP = NO  >> TXLib-Help.dox
%do% call doxygen_                   TXLib-Help.dox
%do% del                             TXLib-Help.dox

goto end

:-------------------------------------------------
:rar
echo Preparing RAR info...

%do% echo Title=Установка TX Library>                                                            %Temp%\~log
%do% echo Path=.\TX>>                                                                            %Temp%\~log
%do% echo Overwrite=1>>                                                                          %Temp%\~log
%do% echo Setup=WScript Wizard\Setup.js>>                                                        %Temp%\~log
%do% echo.>>                                                                                     %Temp%\~log
%do% echo Text=     Установка TX Library>>                                                       %Temp%\~log
%do% echo Text=>>                                                                                %Temp%\~log
%do% echo Text=     TX Library Setup>>                                                           %Temp%\~log
%do% echo Text=>>                                                                                %Temp%\~log
%do% call hg parents --template "Text=     [Version: {branches|nonempty}, Revision: {rev}]" >>   %Temp%\~log
%do% echo.>>                                                                                     %Temp%\~log
%do% echo Text=>>                                                                                %Temp%\~log
%do% echo Text=     $Copyright$| sed32 s/\$//g >> %Temp%\~log
%do% echo Text=>>                                                                                %Temp%\~log
%do% echo Text=     Внимание! Это альфа-версия.>>                                                %Temp%\~log
%do% echo Text=     Для использования требуется согласование>>                                   %Temp%\~log
%do% echo Text=     с автором библиотеки.>>                                                      %Temp%\~log
%do% echo Text=>>                                                                                %Temp%\~log
%do% echo Text=>>                                                                                %Temp%\~log
%do% echo Text=     Revisions log:>>                                                             %Temp%\~log
%do% echo Text=>>                                                                                %Temp%\~log

%do% call hg log | sed32 "s/^^/Text\=     /" >> %Temp%\~log

echo Exporting the archive...
%do% call hg archive __archive

echo Making RAR (%.file%)...

%do% cd __archive

%do% del _* 2>%nul%
%do% attrib +h  .hg_*.*
%do% ren     "TXLib-*.*" "TXLib *.*"
%do% ren "Dev\TXLib-*.*" "TXLib *.*"
%do% xcopy/s %Temp%\Doxygen\HTML Doc\HTML.ru /i > %nul%

%do% del              ..\%.file% 2>%nul%
%do% rar a -r -s -sfx ..\%.file% -z%Temp%\~log > %nul%

%do% cd ..
%do% rd/s/q __archive

%do% rar x -o+ %.file% . Doc\HTML.ru > %nul%

%do% move /y %.file% _OFF\Public

goto end

:-------------------------------------------------
:update
echo Preparing files for update...

%do% pushd _OFF\Public\TXUpdate

%do% copy ..\..\..\TXLib.h        "TXLib.h"        >  %nul%
%do% copy ..\..\..\TXLib-Help.chm "TXLib Help.chm" >  %nul%

%do% attrib -h %.md5%
%do% del %.md5% > %nul% 2> %nul%

%do% for /r %%1 in (*.*) do (set .f=%%~1) & (set .f=!.f:%cd%\=!) & (set .f=!.f:\=/!) & %do% md5sum "!.f!" >> %.md5%
%do% attrib +h %.md5%

%do% popd

goto end

:-------------------------------------------------
:push
echo Pushing to Google Code...

%do% call _OFF\Bin\hg-push

goto end

:=================================================
:autoupdate
echo Making AutoUpdate pack...

%do% set .file=TXLib-Update.rar.exe

%do% echo TempMode=Are you agreed to TXLib license (http://ded32.net.ru/index/0-6) and want to set up TX Library Auto Update?    , TX Library Auto Update Setup> %Temp%\~log
%do% echo Overwrite=1>>                                                            %Temp%\~log
%do% echo Setup=WScript UpdateSetup.js>>                                           %Temp%\~log

%do% pushd Wizard\_OFF\TXUpdate
%do% del              ..\..\..\%.file% 2> %nul%
%do% rar a -r -s -sfx ..\..\..\%.file% -z%Temp%\~log > %nul%
%do% popd

%do% move /y %.file% _OFF\Public

goto end

:-------------------------------------------------
:end
