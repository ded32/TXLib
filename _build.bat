@echo off
if not "%1" == "" goto %1

echo Making docs...

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

:ci
echo Committing...

call hg ci -m "%*" 
call hg kwexpand
call hg ci -m "~" 

attrib +h %0

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
echo Text=     [$Version$]| sed32 s/\$//g >>                         %Temp%\~log
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

echo http://storage.ded32.net.ru/get.pl?url=http://dl.dropbox.com/u/1557330/TXLib/TX.72/%.file% | cliptext

