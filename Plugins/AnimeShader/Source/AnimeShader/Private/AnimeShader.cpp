// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimeShader.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FAnimeShaderModule"

void FAnimeShaderModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Fetch the absolute path to the plugins root directory.
	FString PluginBaseDirectory = IPluginManager::Get().FindPlugin(FAnimeShaderModule::Name)->GetBaseDir();
	// Append the local shader directory.
	FString ShaderDirectory = FPaths::Combine(PluginBaseDirectory, TEXT("Shaders"));
	// Construct the virtual path shorthand.
	FString VirtualShaderDirectory = FString::Printf(TEXT("/Plugin/%s"), *FAnimeShaderModule::Name);
	// Create a mapping to the virtual shader directory shorthand.
	AddShaderSourceDirectoryMapping(VirtualShaderDirectory, ShaderDirectory);
}

void FAnimeShaderModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Cleanup the virtual source directory mapping.
	ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAnimeShaderModule, AnimeShader)