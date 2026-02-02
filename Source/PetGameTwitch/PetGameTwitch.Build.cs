// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class PetGameTwitch : ModuleRules
{
	public PetGameTwitch(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        CppStandard = CppStandardVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		bUseUnity = false;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "TwitchSDK" });
        PrivateDependencyModuleNames.AddRange(new string[] { "TwitchSDK" });
        
//        PrivateIncludePaths.Add(Path.Combine("G:\\VideoGameProjects\\DZKProjects\\PetGameTwitch\\Plugins\\TwitchSDK\\TwitchSDK-Unreal-121523\\core\\include"));
//        PublicAdditionalLibraries.Add(Path.Combine("G:\\VideoGameProjects\\DZKProjects\\PetGameTwitch\\Source\\ThirdParty\\core\\build\\Debug\\R66.lib"));
//       RuntimeDependencies.Add(Path.Combine("G:\\VideoGameProjects\\DZKProjects\\PetGameTwitch\\Source\\PetGameTwitch\\ThirdParty\\core\\build\\Debug\\R66.dll"));
//        PublicDelayLoadDLLs.Add("R66.dll");
		
		// Uncomment if you are using Slate UI
		//	PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
