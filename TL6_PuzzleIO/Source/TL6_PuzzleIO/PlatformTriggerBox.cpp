// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTriggerBox.h"
#include "MovingPlatform.h"

#include "Components/BoxComponent.h"
#include "Components/BillboardComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


APlatformTriggerBox::APlatformTriggerBox()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlatformTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &APlatformTriggerBox::Activate);
	OnActorEndOverlap.AddDynamic(this, &APlatformTriggerBox::Deactivate);

	// Hide the collision box and trigger sprite in-game
	GetCollisionComponent()->SetHiddenInGame(true);
	GetSpriteComponent()->SetHiddenInGame(true);

	// Ideally no platform should be both set to be triggered and inhibited
	if (PlatformsToTrigger.Intersect(PlatformsToInhibit).Num() != 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Some platforms being triggered are also being inhibited! Rescinding control!"));

		// each player fires a quit message and exits from the game
		for (auto PlayerController = GetWorld()->GetPlayerControllerIterator(); PlayerController; ++PlayerController)
		{
			PlayerController->Get()->ConsoleCommand("quit");
		}
	}
}

void APlatformTriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTriggerBox::Activate(AActor* OverlappedActor, AActor* OtherActor)
{
	// For each registered platform, vary count by the number of enabling influences
	for (AMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->IncrementTriggerCount();
	}
	
	// For each registered platform, vary count by the number of inhibiting influences
	for (AMovingPlatform* Platform : PlatformsToInhibit)
	{
		Platform->DecrementTriggerCount();
	}
}

void APlatformTriggerBox::Deactivate(AActor* OverlappedActor, AActor* OtherActor)
{
	// For each registered platform, vary count by the number of enabling influences
	for (AMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->DecrementTriggerCount();
	}
	
	// For each registered platform, vary count by the number of inhibiting influences
	for (AMovingPlatform* Platform : PlatformsToInhibit)
	{
		Platform->IncrementTriggerCount();
	}
}
