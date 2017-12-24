// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * A platform that shuttles between two positions at a constant speed.
 */
UCLASS()
class TL6_PUZZLEIO_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

	void IncrementTriggerCount() { ActiveTriggerCount++; }

	void DecrementTriggerCount() { if (ActiveTriggerCount > 0) ActiveTriggerCount--; }

protected:
	UPROPERTY(EditAnywhere)
	// The constant speed at which the platform magically nudges through free space 
	float Speed;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	// For setting up a target location from within the editor
	FVector TargetLocation;

	UPROPERTY(EditAnywhere)
	// The minimum number of triggers currently active that instigate platform movement
	int32 ActiveTriggerCount = 1;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:
	// Coordinates of the Target location relative to the World's coordinates
	FVector GlobalTargetLocation;
	
	// Coordinates of the Start location relative to the World's coordinates
	FVector GlobalStartLocation;

};
