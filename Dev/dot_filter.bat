
@set .tmp=%temp%\~tmp%random%%random%%random%%random%%random%%random%

@%do% copy %1 %.tmp% > nul 2>>&1
@%do% sed32 -e "s/anonymous_namespace\\{TXLib::h\\}:://g" ^
            -e "s/anonymous_namespace\\{TXLib\.h\\}:://g" %.tmp% > %1

@%do% del %.tmp% > nul 2>>&1

@%do% wait 0
