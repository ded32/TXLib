//==================================================================================
// Setup script for TX Application Wizard - (c) Ded, 2006-2019
// Currently supporting: MSVS 2010-2019, CodeBlocks, Dev-CPP, misc. MinGW etc.
//
// $Version: 00173a, Revision: 166 $
// $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
// $Date: 2020-07-08 18:51:08 +0400 $
//==================================================================================

var DebugMode    = false;
var IgnoreErrors = !DebugMode;

var WizardName   = "TX Application";
var FilesPath    = "TX Application";
var Action       = "install";

//----------------------------------------------------------------------------------

var Shell      = WScript.CreateObject ("WScript.Shell");
var ShellApp   = WScript.CreateObject ("Shell.Application");
var FS         = WScript.CreateObject ("Scripting.FileSystemObject");
var Desktop    = Shell.SpecialFolders ("Desktop");
var Documents  = Shell.SpecialFolders ("MyDocuments");
var Startup    = Shell.SpecialFolders ("Startup");
var Programs64 = Shell.ExpandEnvironmentStrings ("%ProgramFiles%");
var Programs32 = Shell.ExpandEnvironmentStrings ("%ProgramFiles(x86)%");
var Windows    = Shell.ExpandEnvironmentStrings ("%WinDir%");
var Windows32  = Shell.ExpandEnvironmentStrings ("%WinDir%") + "\\System32";
var TempDir    = Shell.ExpandEnvironmentStrings ("%Temp%");
var LogFile    = OpenLog();

//==================================================================================

if (IgnoreErrors) { try { main (WScript.Arguments.Length, WScript.Arguments); } catch (e) {} }
else                    { main (WScript.Arguments.Length, WScript.Arguments); }

//==================================================================================

function main (argc, argv)
    {
    for (var i = 0; i < argc; i++)
        {
        if (argv (i) == "/debug")     DebugMode = true;
        if (argv (i) == "/uninstall") Action    = "uninstall";
        }

    var txFolder = FS.GetAbsolutePathName (FS.GetParentFolderName (WScript.ScriptFullName) + "\\..");

    var src = txFolder + "\\Wizard\\" + FilesPath;
    Debug ("main(): src = '" + src + "'");

    try { ProcessRegAndLnk (txFolder, src); } catch (e) {}
    
    if (!FS.FolderExists (src)) return Error ("Cannot find Setup folder '" + src + "'"), 1;

    var ok = 0, vsOk = 0, sdkOk = 0, sysOk = 0;

    ok += CodeBlocks_Setup      (src + "\\CodeBlocks");
    ok += DevCPP_511_Setup      (src + "\\DevCPP");
    ok += DevCPP_4992_Setup     (src + "\\DevCPP");

    ok += WinSDK_Setup          (src + "\\VS", "C:\\MinGW");
    ok += WinSDK_Setup          (src + "\\VS", "C:\\MinGW64");

    ok += WinSDK_Setup          (src + "\\VS", Programs32 + "\\MinGW");
    ok += WinSDK_Setup          (src + "\\VS", Programs64 + "\\MinGW");

    ok += WinSDK_Setup          (src + "\\VS", Programs32 + "\\Qt\\Tools");
    ok += WinSDK_Setup          (src + "\\VS", Programs64 + "\\Qt\\Tools");

    ok += WinSDK_Setup          (src + "\\VS", Programs32 + "\\Cygwin\\usr\\include");
    ok += WinSDK_Setup          (src + "\\VS", Programs64 + "\\Cygwin\\usr\\include");

    ok += vsOk += VS_Setup_1719 (src + "\\VS", "2019");                 // 2019

    ok += vsOk += VS_Setup_1719 (src + "\\VS", "2017");                 // 2017

    ok += vsOk += VS_Setup      (src + "\\VS", "14.0", "14.0_Config");  // 2015
    ok += vsOk += VS_Setup      (src + "\\VS", "12.0", "12.0_Config");  // 2013
    ok += vsOk += VS_Setup      (src + "\\VS", "11.0", "11.0_Config");  // 2012
    ok += vsOk += VS_Setup      (src + "\\VS", "10.0", "10.0_Config");  // 2010

    ok += sdkOk += WinSDK_Setup  (src + "\\VS", Programs32 + "\\Windows Kits");
    ok += sdkOk += WinSDK_Setup  (src + "\\VS", Programs32 + "\\Microsoft SDKs\\Windows");

    ok += sysOk  = SupportDLLs_CopyFiles (txFolder + "\\Windows", Windows);

    Debug ("\r" + "Setup ended: ok = '" + ok + "', vsOk = '" + vsOk + "', sdkOk = '" + sdkOk + "', sysOk = '" + sysOk + "'\n");

    var installSuccess = ok && ((Action == "install") && !DebugMode);

    if (vsOk && !sdkOk) Echo ("TXLib предупреждает:" + "\n\n"                                                +
                              "У вас найдена MS Visual Studio, но нет прав для записи в папку "              +
                              "'" + Programs32 + "'. Проекты с использованием TX Library могут не работать " +
                              "не работать для Visual Studio. Это не обязательно, но лучше перезапустите   " +
                              "установку TXLib с правами администратора."                                    +
                              "\n\n"                                                                         +
                              "TXLib warning:" + "\n\n"                                                      +
                              "MS Visual Studio detected, but TXLib Setup have no rights to write to  "      +
                              "'" + Programs32 + "'. TX Library projects for Visual Studio may have build "  +
                              "errors. You'd better run TXLib Setup as Administrator.");

    if (!sysOk)         Echo ("TXLib предупреждает:" + "\n\n"                                                +
                              "У нет прав для записи библиотек Microsoft для поддержки отладки в папку "     +
                              "'" + Windows + "'. TX Library не сможет помочь вам в отладке ваших "          +
                              "замечательных проектов. :( Это не обязательно, но лучше перезапустите "       +
                              "установку TXLib с правами администратора или сами скопируйте библиотеки "     +
                              "из папки TX\\Windows в папку " + "'" + Windows + "'."                         +
                              "\n\n"                                                                         +
                              "TXLib warning:" + "\n\n"                                                      +
                              "TXLib Setup  have no rights to save Microsoft debug libraries to "            +
                              "'" + Windows + "' folder. TX Library can not help you to debug your amazing " +
                              "projects. :( You'd better run TXLib Setup as Administrator, or manually copy "+
                              "the files from 'TX\\Windows' folder to " + "'" + Windows + "' folder.");

    if (installSuccess) Echo ("Установка TXLib почти завершена. Библиотекой уже можно пользоваться.\n\n"     +
                              "Последний шаг - установка автоматического обновления библиотеки."             +
                              "\n\n"                                                                         +
                              "TXLib Setup is almost completed. You may use TX Library right now.\n"         +
                              "The last step ahead is to setup TXLib Automatic Update.");

    if (installSuccess) InstallUpdate (txFolder, src);

    if (ok) Echo  ("\n" + "TXLib " + Action + "ed successfully!");
    else    Error ("\n" + "Cannot find compiler(s) or some errors occured. See log file in %TEMP% folder for details.");

    if (installSuccess) Shell.Run (txFolder);

    return 0;
    }

//==================================================================================

function ProcessRegAndLnk (txFolder, src)
    {
    if (Action == "install")
        {
        var hive = null;

        try
            {
            hive = "HKCU"; Shell.RegWrite ("HKCU\\Software\\TX Library\\ProductDir", txFolder);
            hive = "HKLM"; Shell.RegWrite ("HKLM\\SOFTWARE\\TX Library\\ProductDir", txFolder);
            }

        catch (e)
            {
            Debug ("WARNING: ProcessRegAndLnk(): Cannot write to Registry: " + hive);
            }
            
        CreateShortcut (Desktop + "\\Ярлык для TX.lnk",
                        txFolder, "", "",
                        "Папка TX Library", src + "\\VS\\TX Application.ico", 4);
        src += "\\..";

        CreateShortcut (txFolder + "\\Обновление TXLib.lnk",
                        src + "\\UPDATE.bat", "", src,
                        "Обновить TX Library", Windows32 + "\\shell32.dll, 13", 4);
        }

    if (Action == "uninstall")
        {
        Shell.RegDelete ("HKCU\\Software\\TX Library\\");
        Shell.RegDelete ("HKLM\\SOFTWARE\\TX Library\\");

        DeleteFile (Desktop + "\\Ярлык для TX.lnk");
        DeleteFile (Startup + "\\TXUpdate.lnk");
        }
    }

//----------------------------------------------------------------------------------

function InstallUpdate (txFolder, src)
    {
    src += "\\..";

    if (Ask ("Установить автоматическое обновление TX Library?\n\n" +
             "Рекомендуется: [Да]."                                 +
             "\n\n"                                                 +
             "Set up TX Library Automatic Update?\n"                +
             "Recommended: [Yes]."))
        {
        var update = FS.GetAbsolutePathName (src + "\\UPDATE.js");

        CreateShortcut (Startup   + "\\TXUpdate.lnk",
                        Windows32 + "\\WScript.exe", '"' + update + '" 120 0', src,
                        "TXLib automatic update", Windows + "\\shell32.dll, 13", 7);
        }

    if (Ask ("Найти обновления для библиотеки TX Library?\n\n"                     +
             "Рекомендуется: [Да]." + "\n\n"                                       +
             "Скорость обновления зависит от скорости вашего Интернет-соединения." +
             "\n\n"                                                                +
             "Find updates for TX Library now? Recommended: [Yes]." + "\n"         +
             "Update speed depends on your Internet connection speed."))
        {
        var update = '"' + FS.GetAbsolutePathName (src + "\\UPDATE.bat") + '"';

        Debug ("\r" + "Shell.Run (" + update + ")");

        Shell.Run (update, 2, true);
        }
    }

//==================================================================================
// CodeBlocks Setup
//==================================================================================

function CodeBlocks_Setup (src)
    {
    Debug ("\r" + "CodeBlocks_Setup (" + src + ")");

    var dest = CodeBlocks_GetRootDir();
    if ((dest == null) || !FS.FolderExists (dest)) dest = Programs32 + "\\CodeBlocks";
    if ((dest == null) || !FS.FolderExists (dest)) return Error ("Cannot find '" + dest + "'"), 0;

    Debug ("CodeBlocks_Setup(): dest = " + dest);

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

//----------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------

function CodeBlocks_DeleteFiles (dest)
    {
    DeleteFile (dest + "\\MinGW\\Include\\TXLib.h", DebugMode);

    dest += "\\Share\\CodeBlocks\\Templates\\" + WizardName;

    DeleteFile (dest + ".template");
    DeleteFile (dest + ".cbp");
    DeleteFile (dest + ".png");
    DeleteFile (dest + "-main-cpp.cpp");
    }

//==================================================================================
// Dev-CPP 5.1.1 Setup
//==================================================================================

function DevCPP_511_Setup (src)
    {
    Debug ("\r" + "DevCPP_511_Setup (" + src + ")");

    var dest = DevCPP_511_GetRootDir();
    if ((dest == null) || !FS.FolderExists (dest)) dest = Programs32 + "\\Dev-CPP";
    if ((dest == null) || !FS.FolderExists (dest)) return Error ("Cannot find '" + dest + "'"), 0;

    Debug ("DevCPP_511_Setup(): dest = " + dest);

    try
        {
        if (Action ==   "install") DevCPP_CopyFiles   (dest, src);
        if (Action == "uninstall") DevCPP_DeleteFiles (dest);

        Echo (WizardName + " Wizard successfully " + Action + "ed for Dev-CPP 5.11");
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//----------------------------------------------------------------------------------

function DevCPP_511_GetRootDir()
    {
    try
        {
        var path = Shell.RegRead ("HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Dev-C++\\UninstallString");

        return path.substr (0, path.lastIndexOf ("\\"));
        }

    catch (e)
        {
        return null;
        }
    }

//==================================================================================
// Dev-CPP 4.9.9.2 Setup
//==================================================================================

function DevCPP_4992_Setup (src)
    {
    Debug ("\r" + "DevCPP_4992_Setup (" + src + ")");

    var dest = DevCPP_4992_GetRootDir();
    if ((dest == null) || !FS.FolderExists (dest)) return Error ("Cannot find '" + dest + "'"), 0;

    Debug ("DevCPP_4992_Setup(): dest = " + dest);

    try
        {
        if (Action ==   "install") DevCPP_CopyFiles   (dest, src);
        if (Action == "uninstall") DevCPP_DeleteFiles (dest);

        Echo (WizardName + " Wizard successfully " + Action + "ed for Dev-CPP 4.9.9.2");
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//----------------------------------------------------------------------------------

function DevCPP_4992_GetRootDir()
    {
    try
        {
        var iniFile = FS.GetAbsolutePathName (Desktop + "\\..\\Application Data\\Dev-Cpp\\DevCPP.ini");
        Debug ("DevCPP_4992_GetRootDir(): iniFile = " + iniFile);

        var ini = OpenTextFile (iniFile, "r", false);
        if (ini == null) return null;

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

//----------------------------------------------------------------------------------

function DevCPP_CopyFiles (dest, src)
    {
    ProcessDirTree (src, dest, InjectTXLibH, "\\Windows.h")

    src  += "\\" + WizardName;
    dest += "\\Templates";

    CopyFile (dest, src + ".template");
    CopyFile (dest, src + "_Main.txt");
    }

//----------------------------------------------------------------------------------

function DevCPP_DeleteFiles (dest)
    {
    ProcessDirTree (src, dest, DeleteTXLibH, "\\TXLib.h");

    dest += "\\Templates\\" + WizardName;

    DeleteFile (dest + ".template");
    DeleteFile (dest + "_Main.txt");
    }

//==================================================================================
// VS 2017-2019 Setup
//==================================================================================

function VS_Setup_1719 (src, version)
    {
    var dest = Documents + "\\Visual Studio " + version + "\\Templates\\ProjectTemplates";
    Debug ("\r" + "VS_Setup_1719 (" + version + "): dest = " + dest);

    if (!FS.FolderExists (dest)) return Error ("Cannot find '" + dest + "'"), 0;

    try
        {
        if (Action ==   "install") VS_CopyFiles_1719   (dest, src, version);
        if (Action == "uninstall") VS_DeleteFiles_1719 (dest,      version);

        Echo (WizardName + " Wizard successfully " + Action + "ed for VS " + version);
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//----------------------------------------------------------------------------------

function VS_CopyFiles_1719 (dest, src, version)
    {
    Debug ("VS_CopyFiles_1719 (" + dest + ", " + src + ", " + version + ")");

    src  += "\\" + WizardName;
    dest += "\\" + WizardName;

    Debug ("src = " + src + ", dest = " + dest);

    CreateFolder (dest);
    CopyFile     (dest, src + "." + version + ".zip");

    src   = ConvertCP (FS.GetAbsolutePathName (src + "\\..\\..\\..\\.."), "Windows-1251", "UTF-8");
    dest += "\\";

    var zip = WizardName + "." + version + ".zip";
    var prj = WizardName + ".vcxproj";

    UnzipFile (dest + zip, prj, dest, "moveHere");

    CopyFile  (dest + prj, dest + prj, [/\<\/ClCompile\>/g, "  <AdditionalIncludeDirectories>" + src + "</AdditionalIncludeDirectories>\n" +
                                                            "    </ClCompile>"]);
    AddToZip  (dest + zip, dest + prj, "moveHere");
    }

//----------------------------------------------------------------------------------

function VS_DeleteFiles_1719 (dest, version)
    {
    DeleteFile   (dest + "\\" + WizardName + "\\" + WizardName + "." + version + ".zip");
    DeleteFolder (dest + "\\" + WizardName);
    }

//==================================================================================
// VS Setup
//==================================================================================

function VS_Setup (src, version, key)
    {
    var dest = VS_GetRootDir (key, "VC");
    Debug ("\r" + "VS_Setup (" + version + "): dest = " + dest);

    if ((dest == null) || !FS.FolderExists (dest)) return Error ("Cannot find '" + dest + "'"), 0;

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

//----------------------------------------------------------------------------------

function VS_GetRootDir (version, name)
    {
    try
        {
        return Shell.RegRead ("HKCU\\Software\\Microsoft\\VisualStudio\\" + version + "\\Setup\\" + name + "\\ProductDir");
        }

    catch (e)
        {
        return null;
        }
    }

//----------------------------------------------------------------------------------

function VS_CopyFiles (dest, src, version)
    {
    var absolutePath = src;

    InjectTXLibH (dest + "\\Include", src);

    src  += "\\" + WizardName;
    dest += "\\VCProjects";

    CopyFile (dest, src + ".ico");
    CopyFile (dest, src + ".vsdir");


    CopyFile (dest + "\\" + WizardName + ".vsz", src  + ".vsz", ["$(VERSION)", version, "$(ABSOLUTE_PATH)", absolutePath]);
    }

//----------------------------------------------------------------------------------

function VS_DeleteFiles (dest)
    {
    DeleteFile (dest + "\\Include\\TXLib.h");

    dest += "\\VCProjects\\" + WizardName;

    DeleteFile (dest + ".ico");
    DeleteFile (dest + ".vsdir");
    DeleteFile (dest + ".vsz");
    }

//==================================================================================
// Windows SDK Setup
//==================================================================================

function WinSDK_Setup (src, dest)
    {
    Debug ("\r" + "WinSDK_Setup (" + src + ", " + dest + ")");

    if ((dest == null) || !FS.FolderExists (dest)) return 0;

    try
        {
        if (Action ==   "install") ProcessDirTree (src, dest, InjectTXLibH, "\\Windows.h");
        if (Action == "uninstall") ProcessDirTree (src, dest, DeleteTXLibH, "\\TXLib.h");

        Echo ("TX Library successfully " + Action + "ed for '" + dest + "'");
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//==================================================================================

function SupportDLLs_CopyFiles (src, dest)
    {
    Debug ("\r" + "SupportDLLs_CopyFiles (" + src + ", " + dest + ")");

    if ((dest == null) || !FS.FolderExists (dest)) return 0;

    src += "\\";

    try
        {
        CopyFile (dest, src + "dbghelp32.dll");
        CopyFile (dest, src + "dbghelp64.dll");
        CopyFile (dest, src + "mgwhelp32.dll");
        CopyFile (dest, src + "mgwhelp64.dll");

        Debug ("TX Library SupportDLLs successfully " + Action + "ed for '" + dest + "'");
        return 1;
        }

    catch (e)
        {
        return 0;
        }
    }

//==================================================================================

function InjectTXLibH (dest, src)
    {
//  Debug ("InjectTXLibH (" + dest + ", " + src + ")");
    
    var txLibH_dest = FS.GetAbsolutePathName (dest + "\\TXLib.h");
    var txLibH_src  = FS.GetAbsolutePathName (src  + "\\..\\..\\..\\TXLib.h");
    
//  txLibH_src = ConvertCP (txLibH_src, "CP866", "Windows-1251");

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

//----------------------------------------------------------------------------------

function DeleteTXLibH (dest, src)
    {
    DeleteFile (dest + "\\TXLib.h");
    }

//----------------------------------------------------------------------------------

function ProcessDirTree (src, dest, func, marker)
    {
//  Debug ("ProcessDirTree (" + src + ", " + dest + ")");

    if (FS.FileExists (dest + marker))
        {
        Debug ("Marker found (" + dest + "|" + marker + ")");

        func (dest, src);
        }

    var subfolders = FS.GetFolder (dest) .SubFolders;
    for (var en = new Enumerator (subfolders); !en.atEnd(); en.moveNext())
        ProcessDirTree (src, dest + "\\" + en.item().name, func, marker);
    }

//==================================================================================

function OpenTextFile (file, mode, required)
    {
    file = FS.GetAbsolutePathName (file);

    Debug ("OpenTextFile (" + file + ", " + mode + ", " + required + ")");

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

//----------------------------------------------------------------------------------

function CopyFile (dest, src, replace)
    {
    dest = FS.GetAbsolutePathName (dest);
    src  = FS.GetAbsolutePathName (src);

    Debug ("CopyFile     (" + dest + ", " + src + ((replace != null)? ", [" + replace + "]" : "") + ")");

    try
        {
        if (replace != null)
            {
            var file = OpenTextFile (src, "r", true);
            var text = file.ReadAll();
            file.Close();

            for (var i = 0; i < replace.length; i += 2)
                text = text.replace (replace[i], replace[i+1]);

            file = OpenTextFile (dest, "w", true);
            file.Write (text);
            file.Close();
            }
        else
            {
            FS.CopyFile (src, dest + "\\");
            return;
            }
        }

    catch (e)
        {
        throw Error (e, "Cannot copy " + src + " to " + dest);
        }
    }

//----------------------------------------------------------------------------------

function DeleteFile (file, required)
    {
    file = FS.GetAbsolutePathName (file);
    if (required == null) required = false;

    Debug ("DeleteFile   (" + file + ", " + required + ")");

    try
        {
        FS.DeleteFile (file);
        }

    catch (e)
        {
        if (required) throw Error (e, "Cannot delete file " + file);
        }
    }

//----------------------------------------------------------------------------------

function CreateFolder (folder)
    {
    folder = FS.GetAbsolutePathName (folder);

    Debug ("CreateFolder (" + folder + ")");

    try
        {
        for (var pos = folder.indexOf ("\\"); pos != -1; pos = folder.indexOf ("\\", pos+1))
            {
            f = folder.substr (0, pos+1);
            if (!FS.FolderExists (f)) FS.CreateFolder (f);
            }

        if (!FS.FolderExists (folder)) FS.CreateFolder (folder);
        }

    catch (e) {}
    }

//----------------------------------------------------------------------------------

function DeleteFolder (file, required)
    {
    file = FS.GetAbsolutePathName (file);
    if (required == null) required = false;

    Debug ("DeleteFolder (" + file + ", " + required + ")");

    try
        {
        FS.DeleteFolder (file);
        }

    catch (e)
        {
        if (required) throw Error (e, "Cannot delete folder " + file);
        }
    }

//----------------------------------------------------------------------------------

function UnzipFile (zipName, fileName, destFolder, copyFunc)
    {
    zipName    = FS.GetAbsolutePathName (zipName);
    destFolder = FS.GetAbsolutePathName (destFolder);

    Debug ("UnzipFile    (" + zipName + ", " + fileName + ", " + destFolder + ", " + copyFunc + ")");

    try
        {
        var zip = ShellApp.NameSpace (zipName);
        var dst = ShellApp.NameSpace (destFolder);

        var files = 0;
        for (var i = 0; i < zip.Items().Count; i++)
            {
            var item = zip.Items() .Item (i);

            if (item == fileName)
                {
                if      (copyFunc == "copyHere") dst.copyHere (item, 4 + 16);  // No progress bar, Assume Yes on all queries
                else if (copyFunc == "moveHere") dst.moveHere (item, 4 + 16);
                else throw Error ("Bad copyFunc: '" + copyFunc + "'");

                files++;
                }
            }
        }

    catch (e)
        {
        throw Error (e, "UnzipFile(): Cannot unzip '" + fileName + "' from '" + zipName +
                        "' to '" + destFolder + "'");
        }

    return files;
    }

//----------------------------------------------------------------------------------

function AddToZip (zipName, fileName, copyFunc)
    {
    zipName  = FS.GetAbsolutePathName (zipName);
    fileName = FS.GetAbsolutePathName (fileName);

    Debug ("AddToZip     (" + zipName + ", " + fileName + ")");

    try
        {
        var zip  = FS.getFile (zipName)
        var dst  = ShellApp.NameSpace (zip.Path);
        var size = zip.size;

        if      (copyFunc == "copyHere") dst.copyHere (fileName, 4 + 16);  // No progress bar, Assume Yes on all queries
        else if (copyFunc == "moveHere") dst.moveHere (fileName, 4 + 16);
        else throw Error ("Bad copyFunc: '" + copyFunc + "'");

        while (zip.size == size) WScript.Sleep (500);
        }

    catch (e)
        {
        throw Error (e, "AddToZip(): Cannot add " + fileName + " to zip file " + zipName);
        }
    }

//----------------------------------------------------------------------------------

function CreateShortcut (lnkName, target, args, workDir, descr, icon, wndStyle)
    {
    lnkName = FS.GetAbsolutePathName (lnkName);
    target  = FS.GetAbsolutePathName (target);
    workDir = FS.GetAbsolutePathName (workDir);
    icon    = FS.GetAbsolutePathName (icon);

    var lnk = Shell.CreateShortcut (lnkName);

    Debug ("\r" + "CreateShortcut ('" + lnkName + "', '" + target + "', '" + args + "', '" + workDir
                                      + "', '" + descr + "', '" + icon + "', '" + wndStyle + "')");
    lnk.TargetPath       = target;
    lnk.Arguments        = args;
    lnk.WorkingDirectory = workDir;
    lnk.Description      = descr;
    lnk.IconLocation     = icon;
    lnk.WindowStyle      = wndStyle;

    lnk.Save();

    return lnk;
    }

//----------------------------------------------------------------------------------

function ConvertCP (text, sourceCP, destCP)
    {
    var stream = WScript.CreateObject ("ADODB.Stream");

    stream.type = 2;  // Text mode
    stream.mode = 3;  // Read + Write
    stream.open();

    stream.charset = destCP;
    stream.writeText (text);

    stream.position = 0;

    stream.charset = sourceCP;
    return stream.readText();
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

    if (LogFile != null) LogFile.WriteLine (msg);

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
    if (DebugMode)            Echo (msg, 300);
    else if (LogFile != null) LogFile.WriteLine (msg.replace (/\n/g, "\\n").replace (/\r/g, "\n"));
    }

//==================================================================================

function OpenLog()
    {
    var name    = WScript.ScriptName;
    var logDate = new Date;
    var logFile = null;

    try
        {
        logFile = FS.OpenTextFile (TempDir + "\\~TX" + name.substring (0, name.lastIndexOf (".")) + ".log", 8, true);

        logFile.WriteLine ("\n----------------------------------------------------------");
        logFile.Write (WScript.ScriptFullName + " ");
        for (var i = 0; i < WScript.Arguments.length; i++) logFile.Write (WScript.Arguments (i) + " ");
        logFile.WriteLine (logDate.getFullYear()  + "." + logDate.getMonth()+1 + "." + logDate.getDate() + " " +
                           logDate.getHours()     + ":" + logDate.getMinutes() + ":" + logDate.getSeconds());
        logFile.WriteLine (  "----------------------------------------------------------\n");
        }

    catch (e)
        {
        if (logFile != null) logFile.Close();
        logFile = null;
        }
    
    return logFile;
    }

//----------------------------------------------------------------------------------

CloseLog (LogFile);

function CloseLog (logFile)
    {
    if (logFile != null)
        {
        logFile.WriteLine ("\n----------------------------------------------------------");
        logFile.Close();
        logFile = null;
        }
    }
