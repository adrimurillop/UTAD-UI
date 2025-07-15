// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PracticaFinal_UI : ModuleRules
{
	public PracticaFinal_UI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Slate", "SlateCore" });
	}
}
