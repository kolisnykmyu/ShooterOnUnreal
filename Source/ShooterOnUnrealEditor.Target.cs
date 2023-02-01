// ShooterOnUnreal Game. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ShooterOnUnrealEditorTarget : TargetRules
{
	public ShooterOnUnrealEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ShooterOnUnreal" } );
	}
}
