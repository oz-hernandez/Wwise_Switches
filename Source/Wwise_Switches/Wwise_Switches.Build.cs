// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Wwise_Switches : ModuleRules
{
	public Wwise_Switches(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "AkAudio" });
	}
}
