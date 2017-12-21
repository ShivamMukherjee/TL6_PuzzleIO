// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TL6_PuzzleIOTarget : TargetRules
{
	public TL6_PuzzleIOTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("TL6_PuzzleIO");
	}
}
