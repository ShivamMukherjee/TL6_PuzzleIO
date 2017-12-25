// Fill out your copyright notice in the Description page of Project Settings.

#include "TL6_PuzzleIOGameInstance.h"

#include "Engine/Engine.h"

#define RETURN_IF_NULL(x) if (!ensure((x) != nullptr)) return;


void UTL6_PuzzleIOGameInstance::Init()
{
}

void UTL6_PuzzleIOGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	UWorld* World = GetWorld();

	RETURN_IF_NULL(Engine)
	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting..."));

	// Take server to hosted level
	RETURN_IF_NULL(World)
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");

}

void UTL6_PuzzleIOGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	APlayerController* FirstLocalPlayerController = GetFirstLocalPlayerController();

	FString Message = TEXT("Joining address: ") + Address;
	RETURN_IF_NULL(Engine)
	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, Message);

	// Take client to hosted level through address
	RETURN_IF_NULL(FirstLocalPlayerController)
	FirstLocalPlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
