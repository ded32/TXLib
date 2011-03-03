//=============================================================================
// Setup program for the TX Application Wizard - (c) Ded, 2006
// Currently supporting: MSVS 2003-2010, MSVS 6.0, CodeBlocks, Dev-CPP
//=============================================================================

var IgnoreErrors = true;
var DebugMode    = false;

var WizardName   = "TX Application";
var FilesPath    = "TX Application";
var Action       = "install";

//-----------------------------------------------------------------------------

var Shell        = WScript.CreateObject ("WScript.Shell");
var FS           = WScript.CreateObject ("Scripting.FileSystemObject");

main (WScript.Arguments.length, WScript.Arguments);

//-----------------------------------------------------------------------------

function main (argc, argv)
    {
    try { main_IgnoreErrors (argc, argv); }
    catch (e) {}
    }

//-----------------------------------------------------------------------------

function main_IgnoreErrors (argc, argv)
    {
    for (var i = 0; i < argc; i++)
        {
        if (argv (i) == "/debug")     DebugMode = true;
        if (argv (i) == "/uninstall") Action    = "uninstall";
        }

    var src = FS.GetAbsolutePathName (FS.FolderExists ("Wizard")? "Wizard" : ".");
    if (src == null || src == "") src = ".";

    src += "\\" + FilesPath;
    Debug ("main(): src = " + src);

    if (!FS.FolderExists (src)) return Error ("Cannot find Wizard folder " + src);

    var ok = 0;
    ok += VS_Setup  ("9.0",  src + "\\VS");
    ok += VS_Setup  ("8.0",  src + "\\VS");
    ok += VS_Setup  ("7.1",  src + "\\VS");
    ok += VS_Setup  ("7.0",  src + "\\VS");
    ok && VS_HelpSetup      (src + "\\VS\\Help");

    ok += VS_Setup  ("10.0", src + "\\VS");

    ok += VS6_Setup ("6.0",  src + "\\VS6");

    ok += DevCPP_Setup      (src + "\\DevCPP");
    ok += CodeBlocks_Setup  (src + "\\CodeBlocks");

    if (!ok) return Error ("Cannot find compiler(s) or errors occured.");

    try 
        {
        if (Action == "install" && !DebugMode) 
            Shell.Run (FS.GetAbsolutePathName (src + "\\..\\..\\"));
        }

    catch (e) {}
    }

//=============================================================================
// VS Setup
//=============================================================================

function VS_Setup (version, src)
    {
    var dest = VS_GetRootDir (version, "VC");
    Debug ("VS_Setup (" + version + "): dest = " + dest);

    if (dest == null) return 0;
    if (!FS.FolderExists (dest)) return Error ("Cannot find " + dest), 0;

    try
        {
        if (Action ==   "install") VS_CopyFiles   (dest, src, version);
        if (Action == "uninstall") VS_DeleteFiles (dest);
             
        Echo (WizardName + " Wizard successfully " + Action + "ed for VS " + version);
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//-----------------------------------------------------------------------------

function VS_GetRootDir (version, name)
    {
    try
        {
        return Shell.RegRead ("HKLM\\Software\\Microsoft\\VisualStudio\\" + version + "\\Setup\\" + name + "\\ProductDir");
        }

    catch (e) 
        {
        return null;
        }
    }

//-----------------------------------------------------------------------------

function VS_CopyFiles (dest, src, version)
    {
    var absolutePath = src;

    InjectTXLibH (dest + "\\Include", src);

    src  += "\\" + WizardName;
    dest += "\\VCProjects";

    CopyFile (dest, src + ".ico");
    CopyFile (dest, src + ".vsdir");

    // Read and write .vsz, replace absolute path when found

    dest += "\\" + WizardName;

    try
        {
        var srcF  = OpenTextFile (src  + ".vsz", "r", true);
        var destF = OpenTextFile (dest + ".vsz", "w", true);
        if (srcF == null || destF == null) return;

        while (!srcF.AtEndOfStream)
            {
            var s = srcF.ReadLine();
            s = s.replace ("$(VERSION)",       version);
            s = s.replace ("$(ABSOLUTE_PATH)", absolutePath);
            destF.WriteLine (s);
            }

        srcF.Close();
        destF.Close();
        }

    catch (e)
        {
        throw Error (e, "Cannot copy file(s)");
        }
    }

//-----------------------------------------------------------------------------

function VS_DeleteFiles (dest)
    {
    DeleteFile (dest + "\\Include\\TXLib.h", DebugMode);

    dest += "\\VCProjects\\" + WizardName;

    DeleteFile (dest + ".ico",   DebugMode);
    DeleteFile (dest + ".vsdir", DebugMode);
    DeleteFile (dest + ".vsz",   DebugMode);
    }

//-----------------------------------------------------------------------------

function VS_HelpSetup (src)
    {
    if (!Ask ("Install Help for Visual Studio 2003-2008? " +
              "(This may take few minutes to complete)")) return;

    try
        {
        var cmd = "\"" + src + "\\H2Reg.exe\" ";

        if (Action ==   "install") cmd += "-r ";
        if (Action == "uninstall") cmd += "-u ";

        cmd += "-m cmdfile=TXLibReg.ini"

        Shell.Run (cmd, 8, true);

        Echo (WizardName + " Help successfully " + Action + "ed for VS 2003/2005");
        }

    catch (e)
        {
        throw Error (e, "Cannot setup Help for Visual Studio 2003/2005");
        }
    }

//=============================================================================
// VS6 Setup
//=============================================================================

function VS6_Setup (version, src)
    {
    var dest = VS_GetRootDir (version, "Microsoft Visual C++");
    Debug ("VS6_Setup (" + version + "): dest = " + dest);

    if (dest == null) return 0;
    if (!FS.FolderExists (dest)) return Error ("Cannot find " + dest), 0;

    try
        {
        if (Action ==   "install") VS6_CopyFiles   (dest, src);
        if (Action == "uninstall") VS6_DeleteFiles (dest);
             
        Echo (WizardName + " Wizard successfully " + Action + "ed for VS " + version);
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//-----------------------------------------------------------------------------

function VS6_CopyFiles (dest, src)
    {
    InjectTXLibH (dest + "\\Include", src);

    CopyFile (dest + "\\..\\COMMON\\MSDev98\\Bin\\IDE", src + "\\TXWZ.awx");
    }

//-----------------------------------------------------------------------------

function VS6_DeleteFiles (dest)
    {
    DeleteFile (dest + "\\Include\\TXLib.h", DebugMode);

    DeleteFile (dest + "\\..\\COMMON\\MSDev98\\Bin\\IDE\\TXWZ.awx", DebugMode);
    }

//=============================================================================
// Dev-CPP Setup
//=============================================================================

function DevCPP_Setup (src)
    {
    var dest = DevCPP_GetRootDir();
    Debug ("DevCPP_Setup(): dest = " + dest);

    if (dest == null) return 0;
    if (!FS.FolderExists (dest)) return Error ("Cannot find " + dest);

    try
        {
        if (Action ==   "install") DevCPP_CopyFiles   (dest, src);
        if (Action == "uninstall") DevCPP_DeleteFiles (dest);
             
        Echo (WizardName + " Wizard successfully " + Action + "ed for Dev-CPP");
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//-----------------------------------------------------------------------------

function DevCPP_GetRootDir()
    {
    try
        {
        var iniFile = FS.GetAbsolutePathName (Shell.SpecialFolders ("Desktop") + 
                                              "\\..\\Application Data\\Dev-Cpp\\DevCPP.ini");
    	Debug ("DevCPP_GetRootDir(): iniFile = " + iniFile);

        var ini = OpenTextFile (iniFile, "r", false); if (ini == null) return null;

        var root = null;
        var directoriesSection = false;

        while (!ini.AtEndOfStream)
            {
            var s = ini.ReadLine();

            if (s.substr (0, 1) == "[")
               directoriesSection = (s.toLowerCase() == "[directories]");

            if (directoriesSection)
               {
               var pos = s.indexOf ("Exec=");
               if (pos == -1) continue;

               root = s.substr (pos+6, s.length-(pos+6)-2);
               }
            }

        ini.Close();

        return root;
        }

    catch (e) 
        {
        return null;
        }
    }

//-----------------------------------------------------------------------------

function DevCPP_CopyFiles (dest, src)
    {
    InjectTXLibH (dest + "\\Include", src);

    src  += "\\" + WizardName;
    dest += "\\Templates";

    CopyFile (dest, src + ".template");
    CopyFile (dest, src + "_Main.txt");
    }

//-----------------------------------------------------------------------------

function DevCPP_DeleteFiles (dest)
    {
    DeleteFile (dest + "\\Include\\TXLib.h", DebugMode);

    dest += "\\Templates\\" + WizardName;

    DeleteFile (dest + ".template", DebugMode);
    DeleteFile (dest + "_Main.txt", DebugMode);
    }

//=============================================================================
// CodeBlocks Setup
//=============================================================================

function CodeBlocks_Setup (src)
    {
    var dest = CodeBlocks_GetRootDir();
    Debug ("CodeBlocks_Setup(): dest = " + dest);

    if (dest == null) return 0;
    if (!FS.FolderExists (dest)) return Error ("Cannot find " + dest);

    try
        {
        if (Action ==   "install") CodeBlocks_CopyFiles   (dest, src);
        if (Action == "uninstall") CodeBlocks_DeleteFiles (dest);
             
        Echo (WizardName + " Wizard successfully " + Action + "ed for CodeBlocks");
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//-----------------------------------------------------------------------------

function CodeBlocks_GetRootDir()
    {
    try
        {
        return Shell.RegRead ("HKCU\\Software\\CodeBlocks\\Path");
        }

    catch (e) 
        {
        return null;
        }
    }

//-----------------------------------------------------------------------------

function CodeBlocks_CopyFiles (dest, src)
    {
    InjectTXLibH (dest + "\\MinGW\\Include", src);

    dest += "\\Share\\CodeBlocks\\Templates\\";
    src  += "\\";

    CopyFile (dest, src + WizardName + ".template");
    CopyFile (dest, src + WizardName + ".cbp");
    CopyFile (dest, src + WizardName + ".png");
    CopyFile (dest, src + WizardName + "-main-cpp.cpp");

    dest += "wizard\\";
    src  += "wizard\\";
    CreateFolder (dest);
    CopyFile (dest, src + "config.script");

    dest += "tx\\";
    src  += "tx\\";
    CreateFolder (dest);
    CopyFile (dest, src + "logo.png");
    CopyFile (dest, src + "wizard.gif");
    CopyFile (dest, src + "wizard.png");
    CopyFile (dest, src + "wizard.script");

    dest += "files\\";
    src  += "files\\";
    CreateFolder (dest);
    CopyFile (dest, src + "main.cpp");
    }

//-----------------------------------------------------------------------------

function CodeBlocks_DeleteFiles (dest)
    {
    DeleteFile (dest + "\\MinGW\\Include\\TXLib.h", DebugMode);

    dest += "\\Share\\CodeBlocks\\Templates\\" + WizardName;

    DeleteFile (dest + ".template",     DebugMode);
    DeleteFile (dest + ".cbp",          DebugMode);
    DeleteFile (dest + ".png",          DebugMode);
    DeleteFile (dest + "-main-cpp.cpp", DebugMode);
    }

//=============================================================================

function InjectTXLibH (dest, src)
    {
    var txLibH_dest = FS.GetAbsolutePathName (dest + "\\TXLib.h");
    var txLibH_src  = FS.GetAbsolutePathName (src  + "\\..\\..\\..\\TXLib.h");

    try
        {
        var f = OpenTextFile (txLibH_dest, "w", true); if (f == null) return;

        f.WriteLine ('#include "' + txLibH_src + '"');
        f.Close();
        }

    catch (e)
        {
        throw Error (e, "Cannot write to " + txLibH_dest);
        }
    }

//=============================================================================

function OpenTextFile (file, mode, required)
    {
    file = FS.GetAbsolutePathName (file);

    try 
        {
        var f = null;
        if (mode == "r") f = FS.OpenTextFile (file, 1);
        if (mode == "w") f = FS.OpenTextFile (file, 2, true);         

        if (f == null && required) Error ("Cannot open " + file);
        return f;
        }

    catch (e)
        {
        if (required) throw Error (e, "Cannot open " + file);
	return null;
        }
    }

//-----------------------------------------------------------------------------

function CopyFile (dest, src)
    {
    dest = FS.GetAbsolutePathName (dest);
    src  = FS.GetAbsolutePathName (src);

    try 
        {
        FS.CopyFile (src, dest + "\\");
        }

    catch (e)
        {
        throw Error (e, "Cannot copy " + src + " to " + dest);
        }
    }

//-----------------------------------------------------------------------------

function DeleteFile (file, required)
    {
    file = FS.GetAbsolutePathName (file);

    try 
        {
        FS.DeleteFile (file);
        }

    catch (e)
        {
        if (required) throw Error (e, "Cannot delete file " + file);
        }
    }

//-----------------------------------------------------------------------------

function CreateFolder (folder)
    {
    folder = FS.GetAbsolutePathName (folder);

    try 
        {
        FS.CreateFolder (folder);
        }

    catch (e) {}
    }

//-----------------------------------------------------------------------------

function Error (e, msg)
    {
    var descr = "";
    if (e != null && 
        e.description != null &&
        e.description != 'undefined' &&
        e.description.length != 0) descr = e.description;

    if (msg != "" && descr != "") msg += ": ";
    msg += descr;

    if (!IgnoreErrors)
       Echo ("ERROR: " + msg + "\n\n" + 
             "Don't be disappointed at this message!" + "\n\n" +
             "Anyway, you may use TXLib.h file without proceeding this setup.");

    return e;
    }

//-----------------------------------------------------------------------------

function Debug (msg)
    {
    if (DebugMode) Echo (msg);
    }

//-----------------------------------------------------------------------------

function Ask (msg)
    {
    var Yes      = 6;
    var No       = 7;
    var YesNo    = 4;
    var Question = 32;

    return Shell.Popup (msg + "    ", 60, "TX Application Wizard Setup", 
                        YesNo + Question) == Yes;
    }

//-----------------------------------------------------------------------------

function Echo (msg)
    {
    var OK          = 0;
    var Information = 64;

    return Shell.Popup (msg + "    ", 10, "TX Application Wizard Setup", 
                        OK + Information);
    }


