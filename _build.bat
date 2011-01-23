@echo off
if not "%1" == "" goto %1

echo Making docs...

set doxygen_=-nointeractive
copy Dev\TXLib-Help.dox      >nul & call doxygen_ TXLib-Help.dox      & del TXLib-Help.dox
copy Dev\TXLib-Reference.dox >nul & call doxygen_ TXLib-Reference.dox & del TXLib-Reference.dox
move TXLib-Reference.chm Dev\ >nul

:ci
echo Committing...

call hg ci -m "%*" 

attrib +h %0

:rar
echo Preparing RAR info...

echo Title=��������� TX Library>                                                            %Temp%\~log
echo Path=.\TX>>                                                                            %Temp%\~log
echo Overwrite=1>>                                                                          %Temp%\~log
echo Setup=WScript Wizard\Setup.js>>                                                        %Temp%\~log
echo.>>                                                                                     %Temp%\~log
echo Text=     ��������� TX Library>>                                                       %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     TX Library Setup>>                                                           %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     [$Version$]| sed32 s/\$//g >>                         %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     $Copyright$| sed32 s/\$//g >> %Temp%\~log
echo Text=>>                                                                                %Temp%\~log
echo Text=     ��������! ��� �����-������.>>                                                %Temp%\~log
echo Text=     ��� ������������� ��������� ������������>>                                   %Temp%\~log
echo Text=     � ������� ����������.>>                                                      %Temp%\~log
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
ren     "TXLib-*.*" "TXLib *.*"
ren "Dev\TXLib-*.*" "TXLib *.*"
del              ..\%.file% 2>nul
rar a -r -s -sfx ..\%.file% -z%Temp%\~log 
cd ..

rd/s/q __archive

echo http://storage.ded32.net.ru/get.pl?url=http://dl.dropbox.com/u/1557330/TXLib/TX.72/%.file% | cliptext
