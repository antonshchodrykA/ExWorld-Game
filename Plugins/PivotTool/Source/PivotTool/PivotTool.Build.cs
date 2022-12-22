// Copyright 2017-2019 marynate. All Rights Reserved.

using UnrealBuildTool;

public class PivotTool : ModuleRules
{
	public PivotTool(ReadOnlyTargetRules Target) : base(Target)
    {
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"PivotTool/Private",
				"PivotTool/Private/EdMode",
				"PivotTool/Private/Widgets",
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"DetailCustomizations",
				"Engine",
				"EditorStyle",
				"PropertyEditor",
				"Projects",
				"Settings",
				"Slate",
				"SlateCore",
				"ImageWrapper",
				"InputCore",
				"LevelEditor",
				"RawMesh",
				"RenderCore",
				"UnrealEd",
				"WorkspaceMenuStructure",
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			}
			);
	}
}
