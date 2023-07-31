// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MetalHeartPlatformerPlugin : ModuleRules
{
	public MetalHeartPlatformerPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "Projects",
                "CoreUObject",
                "Engine",
                "MetalHeartPlatformerPluginLibrary",
				"Protobuf",
            }
			);

        PrivateDependencyModuleNames.AddRange(
			new string[]
            {
               
            }
			);

        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
    }
}
