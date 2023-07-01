// Generic Fighting Game

using UnrealBuildTool;

public class UE5_Fighting : ModuleRules
{
    public UE5_Fighting(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "MetalHeartPlatformerPlugin"
        });

        PublicIncludePaths.AddRange(new string[] {
            "UE5_Fighting/Public/Core"
        });
    }
}
