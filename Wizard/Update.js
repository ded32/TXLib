//==================================================================================
// Update script for TXLib - (c) Ded, 2019
//
// $Version: 00173a, Revision: 165 $
// $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
// $Date: 2020-03-26 21:07:18 +0400 $
//==================================================================================

var DebugMode    = false;
var IgnoreErrors = !DebugMode;

//----------------------------------------------------------------------------------

var Shell      = WScript.CreateObject ("WScript.Shell");
var FS         = WScript.CreateObject ("Scripting.FileSystemObject");
var TempDir    = Shell.ExpandEnvironmentStrings ("%Temp%");
var LogFile    = OpenLog();

//==================================================================================

if (IgnoreErrors) { try { main (WScript.Arguments.Length, WScript.Arguments); } catch (e) {} }
else                    { main (WScript.Arguments.Length, WScript.Arguments); }

//==================================================================================

function main (argc, argv)
    {
    if (argc >= 1)
        {
        Debug ("Waiting for " + argv (0) + " sec...\r");

        WScript.Sleep (argv (0) * 1000);
        }

    var wndStyle = 0;
    if (argc >= 1) wndStyle = 1;
    if (argc >= 2) wndStyle = argv (1);
    if (DebugMode) wndStyle = 1;

    var dir = FS.GetAbsolutePathName (WScript.ScriptFullName);
    var dir = dir.substring (0, dir.lastIndexOf ('\\'));

    Debug ("Shell.Run (" + dir + "\\UPDATE.bat, " + wndStyle + ", false)", false);

            Shell.Run (    dir + "\\UPDATE.bat",    wndStyle,     false);
    }

//==================================================================================

function Error (e, msg)
    {
    if (msg == null)        msg = e;
    if (msg == null)        msg = "(null)";
    if (msg == 'undefined') msg = "(undefined)";

    var descr = "";
    if (e != null &&
        e.description !=  null       &&
        e.description !=  undefined  &&
        e.description != 'undefined' &&
        e.description.length != 0) descr = e.description;

    if (msg != "" && descr != "") msg += ": ";
    msg += descr + " (0x" + (e.number >>> 0).toString (16) + ")";

    if (!IgnoreErrors)
        Echo ("ERROR: " + msg + "\n\n" +
              "Don't be disappointed at this message!" + "\n\n" +
              "Anyway, you may use TXLib.h file without proceeding this setup.");
    else
        Debug ("ERROR: " + msg);

    return e;
    }

//----------------------------------------------------------------------------------

function Ask (msg)
    {
    var Yes      = 6;
    var No       = 7;
    var YesNo    = 4;
    var Question = 32;

    var res = Shell.Popup (msg + "    ", 60, "TX Application Wizard Setup", YesNo + Question) == Yes;

    Debug ("\r" + "Ask (" + msg + ') returned "' + res + '"');

    return res;
    }

//----------------------------------------------------------------------------------

function Echo (msg, timeout)
    {
    if (timeout == null) timeout = 5;

    var OK          = 0;
    var Information = 64;

    LogFile.WriteLine (msg);

    if (WScript.FullName.indexOf ("cscript") < 0)
        {
        if (msg.substr (msg.length-1, 1) == "\n") msg = msg.substr (0, msg.length-1);

        return Shell.Popup  (msg + "    ", timeout, "TXLib Setup", OK + Information);
        }
    else
        return WScript.Echo (msg);
    }

//----------------------------------------------------------------------------------

function Debug (msg)
    {
    if (DebugMode) Echo (msg, 300);
    else LogFile.WriteLine (msg.replace (/\n/g, "\\n").replace (/\r/g, "\n"));
    }

//==================================================================================

function OpenLog()
    {
    var name    = WScript.ScriptName;
    var logName = "~TX" + name.substring (0, name.lastIndexOf (".")) + ".log";

    var logDate = new Date;
    var logFile = null;
    
    try { if (logFile == null) logFile = FS.OpenTextFile (TempDir + "\\" + logName, 8, true); } catch (e) {}
    try { if (logFile == null) logFile = FS.OpenTextFile (                 logName, 8, true); } catch (e) {}

    logFile.WriteLine ("\n----------------------------------------------------------");
    logFile.Write (WScript.ScriptFullName + " ");
    for (var i = 0; i < WScript.Arguments.length; i++) logFile.Write (WScript.Arguments (i) + " ");
    logFile.WriteLine (logDate.getFullYear()  + "." + logDate.getMonth()+1 + "." + logDate.getDate() + " " +
                       logDate.getHours()     + ":" + logDate.getMinutes() + ":" + logDate.getSeconds());
    logFile.WriteLine (  "----------------------------------------------------------\n");

    return logFile;
    }

//----------------------------------------------------------------------------------

CloseLog (LogFile);

function CloseLog (logFile)
    {
    logFile.WriteLine ("\n----------------------------------------------------------");
    logFile.Close();
    }

