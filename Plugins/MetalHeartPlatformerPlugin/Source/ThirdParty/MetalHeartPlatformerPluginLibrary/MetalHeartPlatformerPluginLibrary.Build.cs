// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class MetalHeartPlatformerPluginLibrary : ModuleRules
{
    public MetalHeartPlatformerPluginLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        string DllBinaryPath = Path.Combine(ModuleDirectory, "..", "..", "..", "Binaries", "Win64", "frontend_async.dll");

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {

            string IncludeDir = Path.Combine(ModuleDirectory, "include");
            string LibDir = Path.Combine(ModuleDirectory, "windows");
            string LibPath = Path.Combine(LibDir, "frontend_async.lib");
            string DllPath = Path.Combine(LibDir, "frontend_async.dll");

            System.Console.WriteLine("IncludeDir: " + IncludeDir);
            System.Console.WriteLine("LibPath: " + LibPath);
            System.Console.WriteLine("DllPath: " + DllPath);
            System.Console.WriteLine("DllBinaryPath: " + DllBinaryPath);

            CopyFile(DllPath, DllBinaryPath);

            PublicSystemIncludePaths.AddRange(
            new string[]
            {
                IncludeDir
            }
            );
            //PublicIncludePaths.Add(IncludeDir);
            PublicAdditionalLibraries.Add(LibPath);
            RuntimeDependencies.Add(DllPath);
        }
        else
        {
            System.Console.WriteLine("ERROR: Unsupported platform");
        }
    }

    private void CopyFile(string src, string dest)
    {
        if (System.IO.File.Exists(dest))
        {
            System.IO.File.SetAttributes(dest,
                System.IO.File.GetAttributes(dest) & ~System.IO.FileAttributes.ReadOnly);
        }

        try
        {
            System.IO.File.Copy(src, dest, true);
        }
        catch (System.Exception e)
        {
            System.Console.WriteLine("Failed to copy file {0}", e.Message);
        }
    }
}
