// Generic Fighting Game

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5_FightingTarget : TargetRules
{
	public UE5_FightingTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "UE5_Fighting" } );
	}
}
