// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TL6_PuzzleIOEditorTarget : TargetRules
{
	public TL6_PuzzleIOEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("TL6_PuzzleIO");
	}
}
