//-----------------------------------------------------------------------------
// Uninstall program for the TX Library Visual Studio .NET Help - (c) Ded, 2006
//-----------------------------------------------------------------------------

var Shell      = WScript.CreateObject ("WScript.Shell");
var FS         = WScript.CreateObject ("Scripting.FileSystemObject");
var DebugMode  = false;

main (WScript.Arguments.length, WScript.Arguments);

//-----------------------------------------------------------------------------

function main (argc, argv)
    {
    var cmd = "Setup.js /uninstall ";
    for (var i = 0; i < argc; i++) cmd += argv (i);

    Shell.Run (cmd);
    }
