// ShooterOnUnreal Game. All Rights Reserved.

using UnrealBuildTool;

public class ShooterOnUnreal : ModuleRules
{
  public ShooterOnUnreal(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

    PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "InputCore" });

    PrivateDependencyModuleNames.AddRange(new string[] { });

    PublicIncludePaths.AddRange(new[]
      {
        "ShooterOnUnreal/Public/Player",
        "ShooterOnUnreal/Public/Components",
        "ShooterOnUnreal/Public/Dev",
        "ShooterOnUnreal/Public/Weapon",
        "ShooterOnUnreal/Public/UI"
      });

    // Uncomment if you are using Slate UI
    // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

    // Uncomment if you are using online features
    // PrivateDependencyModuleNames.Add("OnlineSubsystem");

    // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
  }
}