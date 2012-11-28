//-----------------------------------------------------------------------------
// Uninstall script for the TX Application Wizard - (c) Ded, 2006
//-----------------------------------------------------------------------------

var Shell = WScript.CreateObject ("WScript.Shell");

main (WScript.Arguments.length, WScript.Arguments);

//-----------------------------------------------------------------------------

function main (argc, argv)
    {
    var cmd = "Setup.js /uninstall ";
    for (var i = 0; i < argc; i++) cmd += argv (i);

    if (!Ask ("В Вашей совести не осталось достаточно места для совершения    \n" +
              "этого поступка."+"\n\n"+"Очистить совесть?  :)")) return;

    Shell.Run (cmd);
    }

//-----------------------------------------------------------------------------

function Ask (msg)
    {
    var Yes      = 6;
    var No       = 7;
    var YesNo    = 4;
    var Stop     = 16;

    return Shell.Popup (msg + "    ", 60, "Предупреждение", 
                        YesNo + Stop) == Yes;
    }

