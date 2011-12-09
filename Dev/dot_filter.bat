
@%do% copy %1 %temp%\~ > nul
@%do% sed32 -e "s/anonymous_namespace\\{TXLib::h\\}:://g" ^
            -e "s/anonymous_namespace\\{TXLib\.h\\}:://g" %temp%\~ > %1
