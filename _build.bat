@echo off
if not "%~dp0" == "%temp%\" (xcopy/ah/y %0 %temp%\ > nul) & (%temp%\%~nx0)

:ci
echo Committing...

for %%1 in (TXLib.h Dev\*.dox Doc\1_MainPage.txt) do echo.>> %%1

call hg ci -m "%*" 
call hg kwshrink
call hg kwexpand
attrib +h %~nx0

:chm
echo Making docs...

del TXLib-v0172a.rar.exe-TXLib.h        >nul 2>nul
del TXLib-v0172a.rar.exe-TXLib Help.chm >nul 2>nul

set doxygen_=-nointeractive

copy Dev\TXLib-Reference.dox >nul
call doxygen_ TXLib-Reference.dox
move TXLib-Reference.chm Dev\ >nul
del TXLib-Reference.dox

copy Dev\TXLib-Help.dox >nul
call doxygen_ TXLib-Help.dox

echo GENERATE_TREEVIEW = YES >> TXLib-Help.dox
echo GENERATE_HTMLHELP = NO  >> TXLib-Help.dox
call doxygen_ TXLib-Help.dox
del TXLib-Help.dox

call hg ci -m "~" 

:rar
echo Preparing RAR info...

echo Title=Установка TX Library>                                                            %Temp%\~log
echo Path=.\TX>>                                                                            %Temp%\~log
echo Overwrite=1>>                                                                          %Temp%\~log
echo Setup=WScript Wizard\Setup.js>>                                                        %Temp%\~log
echo.>>                                                                                     %Temp%\~log
echo Text=     Установка TX Library>>                                                       %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     TX Library Setup>>                                                           %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
call hg parents --template "Text=     [Version: {branches|nonempty}, Revision: {rev}]" >>   %Temp%\~log
echo.>>                                                                                     %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     $Copyright$| sed32 s/\$//g >> %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     Внимание! Это альфа-версия.>>                                                %Temp%\~log
echo Text=     Для использования требуется согласование>>                                   %Temp%\~log
echo Text=     с автором библиотеки.>>                                                      %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     Revisions log:>>                                                             %Temp%\~log
echo Text=>>                                                                                %Temp%\~log

call hg log | sed32 "s/^^/Text\=     /" >> %Temp%\~log

echo Exporting the archive...
call hg archive __archive

set .file=TXLib-$v$.rar.exe
set .file=%.file:$v: =v%
set .file=%.file: $=%

echo Making RAR (%.file%)...

cd __archive
del _* 2>nul
attrib +h  .hg_*.*
ren     "TXLib-*.*" "TXLib *.*"
ren "Dev\TXLib-*.*" "TXLib *.*"
xcopy/s %Temp%\Doxygen\HTML Doc\HTML.ru /i > nul
del              ..\%.file% 2>nul
rar a -r -s -sfx ..\%.file% -z%Temp%\~log > nul
cd ..

rd/s/q __archive

rar x -o+ %.file% . Doc\HTML.ru > nul
copy TXLib.h        "%.file%-TXLib.h"        > nul
copy TXLib-Help.chm "%.file%-TXLib Help.chm" > nul

echo http://storage.ded32.net.ru/get.pl?url=http://dl.dropbox.com/u/1557330/TXLib/TX.72/%.file% | cliptext
