//-----------------------------------------------------------------------------
// Install script for TX Library Automatic Update - (c) Ded, 2010-11
//-----------------------------------------------------------------------------

var Shell   = WScript.CreateObject ("WScript.Shell");
var FS      = WScript.CreateObject ("Scripting.FileSystemObject");
var Desktop = Shell.SpecialFolders ("Desktop");
var Startup = Shell.SpecialFolders ("Startup");

main (WScript.Arguments.length, WScript.Arguments);

//-----------------------------------------------------------------------------

function main (argc, argv)
    {
    try 
        {
        var src = FS.GetAbsolutePathName (FS.GetParentFolderName (WScript.ScriptFullName));

        var txFolder = txFolder = Desktop + "\\TX";
        try { txFolder = Shell.RegRead ("HKCU\\Software\\TX Library\\ProductDir"); } catch (e) {}

        var dest = txFolder + "\\Wizard\\";
        try { FS.CreateFolder (txFolder); FS.CreateFolder (dest); } catch (e) {}

        var status = "successfully ";
        var error  = "";

        try {
            FS.CopyFile (src + "\\*.*", dest);
            }
        catch (e)
            {
            status = "is NOT ";
            error  = ":\n\n" + 'ERROR: CopyFile (from: "' + src + '\\*.*", to: "' + dest + '"): ' + e.message;
            }
        
        try {
            CreateShortcut (Startup + "\\TXUpdate.lnk", 
                            dest + "cmd$.exe", "/c wait 120 & Update", dest,
                            "TXLib automatic update", "shell32.dll, 13", 7);
            }
        catch (e)
            {
            status = "is NOT ";
            error  = ":\n\n" + 'ERROR: CreateShortcut (file: "' + Startup + '\\TXUpdate.lnk"): ' + e.message;
            }

        if (Ask ('TXLib automatic update ' + status + 'installed for "' + txFolder + '"' + error + '.    \n\n' +
                 "Update TXLib now?"))
            {
            Shell.Run ('"' + dest + "Update.bat" + '"');
            }

        return 0;
        }

    catch (e) { throw e; }
    }

//-----------------------------------------------------------------------------

function CreateShortcut (lnkName, target, args, workDir, descr, icon, wndStyle)
    {
    var lnk = Shell.CreateShortcut (lnkName);

    lnk.TargetPath       = target;
    lnk.Arguments        = args;
    lnk.WorkingDirectory = workDir;
    lnk.Description      = descr;
    lnk.IconLocation     = icon;
    lnk.WindowStyle      = wndStyle;

    lnk.Save();

    return lnk;
    }

//-----------------------------------------------------------------------------

function Ask (msg)
    {
    var Yes      = 6;
    var No       = 7;
    var YesNo    = 4;
    var Question = 32;

    return Shell.Popup (msg + "    ", 60, "TXLib Update Setup", 
                        YesNo + Question) == Yes;
    }

//-----------------------------------------------------------------------------

function Echo (msg)
    {
    var OK          = 0;
    var Information = 64;

    return Shell.Popup (msg + "    ", 10, "TXLib Update Setup", 
                        OK + Information);
    }

