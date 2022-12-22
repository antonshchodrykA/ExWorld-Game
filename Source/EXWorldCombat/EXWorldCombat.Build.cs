// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EXWorldCombat : ModuleRules
{
	public EXWorldCombat(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "GameplayTasks", "HTTP", "Niagara" });

		PrivateDependencyModuleNames.AddRange(new string[] { "ALSV4_CPP", "Niagara" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "DemoTest" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
