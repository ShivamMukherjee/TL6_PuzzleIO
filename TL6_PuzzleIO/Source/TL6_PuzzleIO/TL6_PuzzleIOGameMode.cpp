// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TL6_PuzzleIOGameMode.h"
#include "TL6_PuzzleIOCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATL6_PuzzleIOGameMode::ATL6_PuzzleIOGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
