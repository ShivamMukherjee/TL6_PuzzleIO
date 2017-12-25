// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TL6_PuzzleIOGameInstance.generated.h"

/**
 * Defines some console commands to be used for initiating a game.
 */
UCLASS()
class TL6_PUZZLEIO_API UTL6_PuzzleIOGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	virtual void Init() override;
	
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);
};
