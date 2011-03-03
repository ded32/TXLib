//=============================================================================
// Default.js for TXWizard (c) Ded, 2006
//=============================================================================

function main()
    {
    try
        {
        if (!CanUseDrive (PROJECT_PATH())) return VS_E_WIZARDBACKBUTTONPRESS;
            
        prj = CreateProject (PROJECT_NAME(), PROJECT_PATH());

        AddCommonConfig (prj, PROJECT_NAME(), true);

        var 
        config = prj.Object.Configurations ("Debug");
        SetConfigSettings ("Debug",   config, prj, config.Tools ("VCCLCompilerTool"), config.Tools ("VCLinkerTool"));

        config = prj.Object.Configurations ("Release");
        SetConfigSettings ("Release", config, prj, config.Tools ("VCCLCompilerTool"), config.Tools ("VCLinkerTool"));

        AddFilters (prj);
        if (!PROJECT_EMPTY()) AddFilesToNewProjectWithInfFile (prj, PROJECT_NAME());

        prj.Object.Save();
        }
        
    catch (e) { throw e; }
    }

//=============================================================================

function SetConfigSettings (name, config, prj, compiler, linker)
    {
// lines which are commented out are in AddCommonConfig()

    var preprocessorDefinitions = GetPlatformDefine (config);
    var D = (name.toLowerCase() == "debug");
    var R = (name.toLowerCase() == "release");

// project
//         prj.Object.RootNamespace                = CreateIdentifierSafeName (PROJECT_NAME());

// config
//  if (R) config.WholeProgramOptimization         = WholeProgramOptimizationLinkTimeCodeGen;
    
           config.OutputDirectory                  = "$(SolutionDir)$(Configuration)\\";
           config.IntermediateDirectory            = "$(Configuration)\\";

           config.CharacterSet                     = config.charSetMBCS;

// compiler
//         compiler.Detect64BitPortabilityProblems = true;
//  if (D) compiler.Optimization                   = optimizeDisabled;
//  if (D) compiler.MinimalRebuild                 = true;
//  if (D) compiler.BasicRuntimeChecks             = runtimeBasicCheckAll;
//  if (D) compiler.DebugInformationFormat         = debugEditAndContinue;
//  if (R) compiler.DebugInformationFormat         = debugEnabled;

           compiler.WarningLevel                   = WarningLevel_4;
                                            
           preprocessorDefinitions                += "_WINDOWS;_CONSOLE;";
    if (D) preprocessorDefinitions                += "_DEBUG";
    if (R) preprocessorDefinitions                += "NDEBUG";
           compiler.PreprocessorDefinitions        = preprocessorDefinitions;
          
           compiler.UsePrecompiledHeader           = pchNone;
    try  { SetNoPchSettings (prj); } catch (e) {}

    if (D) compiler.RuntimeLibrary                 = rtMultiThreadedDebug;
    if (R) compiler.RuntimeLibrary                 = rtMultiThreaded;

           compiler.AdditionalIncludeDirectories   = "$(SolutionDir)\\Include";
           
// linker
//           linker.TargetMachine                    = machineX86;
//           linker.GenerateDebugInformation         = true;
//    if (R) linker.OptimizeReferences               = optReferences;
//    if (R) linker.EnableCOMDATFolding              = optFolding;
    
           linker.SubSystem                        = subSystemConsole;
           
    if (D) linker.LinkIncremental                  = linkIncrementalYes;
    if (R) linker.LinkIncremental                  = linkIncrementalNo;

           linker.ProgramDatabaseFile              = "$(OutDir)\\" + PROJECT_NAME() + ".pdb";
    
           linker.AdditionalLibraryDirectories     = "$(SolutionDir)\\Lib";
      }

//-----------------------------------------------------------------------------

function GetTargetName (item, prjName, resPath, helpPath)
    {
    try
        {
        switch (item.toLowerCase())
            {
            case "_main.cpp":
            case "_main.u.cpp":  return prjName + ".cpp";

            case "readme.txt":
            case "readme.u.txt": return "ReadMe.txt";
            }

        return item; 
        }

    catch (e) { throw e; }
    }

//-----------------------------------------------------------------------------

function SetFileProperties (prjFile, item)
    {
    return false;
    }

//-----------------------------------------------------------------------------

function AddFilters (prj)
    {
    try
        {
        prj.Object.AddFilter ("Source Files") .Filter = SOURCE_FILTER();
        }

    catch (e) { throw e; }
    }

//-----------------------------------------------------------------------------
// This function is called by the Wizard

function OnFinish (prj, obj)
    {
    try
        {
        main();
        }
        
    catch (e)
        {
        if (e.description.length != 0) SetErrorInfo (e);
        return e.number;
        }
    }

//-----------------------------------------------------------------------------

function PROJECT_NAME()  { return wizard.FindSymbol ("PROJECT_NAME");  }
function PROJECT_PATH()  { return wizard.FindSymbol ("PROJECT_PATH");  }
function PROJECT_EMPTY() { return wizard.FindSymbol ("PROJECT_EMPTY"); }
function SOURCE_FILTER() { return wizard.FindSymbol ("SOURCE_FILTER"); }

