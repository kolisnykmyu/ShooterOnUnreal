// ShooterOnUnreal Game. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShooterOnUnrealTarget : TargetRules
{
	public ShooterOnUnrealTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ShooterOnUnreal" } );
	}
}
