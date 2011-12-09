:-------------------------------------------------
@(set do=) & set log=%temp%\~TX_build.log
:(set do=@ECHO    ) & (set log=CON)
:-------------------------------------------------
@if /i not "%~dp0" == "%temp%\" @(xcopy/ah/y %0 %temp%\ > nul) & @(cmd /v:on /c %temp%\%~nx0 %*) & @(goto end)
@echo %0 %* >> %log%
@if "%1" == "#" @goto %2
:-------------------------------------------------
@echo off

set .cmd=ci doc rar update push

set .file=TXLib-$v$.rar.exe
set .file=%.file:$v: =v%
set .file=%.file: $=%

set .md5="TXLib Update.md5"

if /i "%1" == "" %0 ci doc rar update push push-doc push-sf

:-------------------------------------------------

for %%1 in (%*) do call %0 # %%1 %*

echo FINISHED
goto end

:-------------------------------------------------
:ci
echo Committing...

%do% for %%1 in (TXLib.h Dev\*.dox Doc\1_MainPage.txt Dev\doxygen_hdr.htm) do echo.>> %%1
del %%1 >> %log% 2>>&1

 %do% call hg ci
:%do% call hg ci -m "%*"
:%do% call hg kwshrink
:%do% call hg kwexpand

 %do% attrib +h %~nx0

goto end

:-------------------------------------------------
:doc
:docs
echo Making docs...

     set .html=%Temp%\Doxygen\HTML
%do% set doxygen_=-nointeractive

%do% for %%1 in (Dev\TXLib-Help.dox Dev\TXLib-Reference.dox Dev\doxygen_*.* Dev\dot_filter.bat) do copy %%1 >> %log% 2>>&1

:doc-ref

%do% echo HHC_LOCATION = none.exe       >> TXLib-Reference.dox
%do% echo HTML_FOOTER = doxygen_chm.htm >> TXLib-Reference.dox
%do% call doxygen_ TXLib-Reference.dox

pushd %.html%
for %%1 in (*.htm *.map) do (%do% copy %%1 %temp%\~ > nul) & (%do% sed32 "s/anonymous_namespace{TXLib.h}:://g" %temp%\~ > %%1)
%do% "%ProgramFiles%\HTML Help Workshop\hhc.exe" index.hhp >> %log% 2>>&1
del %Temp%\~hh*.tmp >> %log% 2>>&1
popd

%do% del      Dev\TXLib-Reference.chm      >> %log% 2>>&1
%do% move %.html%\TXLib-Reference.chm Dev\ >> %log% 2>>&1

:doc-help

%do% echo HTML_FOOTER = doxygen_chm.htm >> TXLib-Help.dox
%do% call doxygen_ TXLib-Help.dox

%do% echo GENERATE_TREEVIEW = YES       >> TXLib-Help.dox
%do% echo GENERATE_HTMLHELP = NO        >> TXLib-Help.dox
%do% echo HTML_FOOTER = doxygen_htm.htm >> TXLib-Help.dox
%do% call doxygen_ TXLib-Help.dox

%do% for %%1 in (TXLib-Help.dox TXLib-Reference.dox doxygen_*.* dot_filter.bat) do del %%1 >> %log% 2>>&1

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

%do% del _* >> %log% 2>>&1
%do% attrib +h  .hg_*.*

%do% ren         "TXLib-*.*"   "TXLib *.*"       >> %log% 2>>&1
%do% copy     "..\TXLib-*.chm" "TXLib *.chm"     >> %log% 2>>&1
%do% copy "..\Dev\TXLib-*.chm" "Dev\TXLib *.chm" >> %log% 2>>&1

%do% xcopy/s %Temp%\Doxygen\HTML Doc\HTML.ru /i >> %log% 2>>&1

%do% del              ..\%.file% >> %log% 2>>&1
%do% rar a -r -s -sfx ..\%.file% -z%Temp%\~log >> %log% 2>>&1

%do% cd ..
%do% rd/s/q __archive

%do% rd/s/q              Doc\HTML.ru  >> %log% 2>>&1
%do% rar x -o+ %.file% . Doc\HTML.ru\ >> %log% 2>>&1

%do% move /y %.file% _OFF\Public >> %log% 2>>&1

goto end

:-------------------------------------------------
:update
echo Copying files for TXUpdate...

%do% pushd _OFF\Public\TXUpdate

%do% copy ..\..\..\TXLib.h        "TXLib.h"        >> %log% 2>>&1
%do% copy ..\..\..\TXLib-Help.chm "TXLib Help.chm" >> %log% 2>>&1

%do% attrib -h %.md5%
%do% del %.md5% >> %log% 2>>&1

%do% for /r %%1 in (*.*) do (set .f=%%~1) & (set .f=!.f:%cd%\=!) & (set .f=!.f:\=/!) & %do% md5sum "!.f!" >> %.md5%
%do% attrib +h %.md5%

%do% popd

goto end

:-------------------------------------------------
:push
echo Pushing to Google Code...

%do% call _OFF\Bin\hg-push

goto end

:-------------------------------------------------
:push-doc
:push-docs
echo Pushing docs to Masterhost...

call _OFF\Bin\ftp-push-docs >> %log% 2>>&1

goto end

:-------------------------------------------------
:push-sf
echo Pushing release to SF...

call _OFF\Bin\sf-push "_OFF\Public\TXUpdate\TXLib Help.chm" ^
                      "_OFF\Public\TXUpdate\TXLib.h"        ^
                      "_OFF\Public\%.file%" >> %log% 2>>&1
goto end

:=================================================
:autoupdate
echo Making AutoUpdate pack...

%do% set .file=TXLib-Update.rar.exe

%do% echo TempMode=Are you agreed to TXLib license (http://ded32.net.ru/index/0-6) and want to set up TX Library Auto Update?    , TX Library Auto Update Setup> %Temp%\~log
%do% echo Overwrite=1>>                                                            %Temp%\~log
%do% echo Setup=WScript UpdateSetup.js>>                                           %Temp%\~log

%do% pushd Wizard\_OFF\TXUpdate
%do% del              ..\..\..\%.file%               >> %log% 2>>&1
%do% rar a -r -s -sfx ..\..\..\%.file% -z%Temp%\~log >> %log% 2>>&1
%do% popd

%do% move /y %.file% _OFF\Public

goto end

:-------------------------------------------------
:end
