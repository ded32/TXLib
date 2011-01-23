@echo off
@set .files=*
@if not !.files! == * (cmd /v:on /c %0 %*) & exit

set .files=*. *.awx *.bat *.bmp *.cbp *.chm *.cpp *.css *.dox *.gif *.h *.htm *.ico *.inf *.ini *.jpg *.js *.png *.reg *.script *.template *.txt *.vcproj *.vsdir *.vsz

call hg init
attrib +h .hg

for /r %%1 in (%.files%) do (set .file=%%1) & (call hg add "!.file:%cd%\=!")
