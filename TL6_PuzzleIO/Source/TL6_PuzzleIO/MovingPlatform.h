// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class TL6_PUZZLEIO_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMovingPlatform();

protected:
	UPROPERTY(EditAnywhere)
	float Speed = 10.f;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	// For setting up a target location from within the editor
	FVector TargetLocation;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:

	// cache the direction this is headed
	FVector PathDirection;

	float PathDistance;
	
	FVector GlobalTargetLocation;

	FVector GlobalStartLocation;
};
