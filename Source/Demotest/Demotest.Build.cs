// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

using UnrealBuildTool;

public class Demotest : ModuleRules
{
	public Demotest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[] 
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Sockets",
				"OnlineSubsystemUtils",
				"PhysXVehicles",
				"SpatialGDK",
				"AIModule",
				"GameplayTasks",
				"NavigationSystem",
				"Json", 
				"JsonUtilities",
				"HTTP",
				"UMG", "Slate", "SlateCore"
			});
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"ExWorldLoadingScreen", "PlayFab", "PlayFabCpp", "PlayFabCommon","EXWorldCombat","ALSV4_CPP", "WebSockets"
			});
	}
}
