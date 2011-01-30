@echo off

set .files=*.bak *.save *.cbtemp *.~* TXLib*.chm.bak TXLib*.log TXLib*.log.bak

for /f %%1 in ('dir/b/a %.files%') do del/a %%1

cd Dev
for /f %%1 in ('dir/b/a %.files%') do del/a %%1
cd..
