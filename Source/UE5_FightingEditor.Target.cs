// Generic Fighting Game

using UnrealBuildTool;
using System.Collections.Generic;

public class UE5_FightingEditorTarget : TargetRules
{
	public UE5_FightingEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "UE5_Fighting" } );
	}
}
