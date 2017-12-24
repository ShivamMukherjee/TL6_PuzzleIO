// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// The platform must move!
	SetMobility(EComponentMobility::Movable);

	// only set up replication if this device is the server
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	// Return the required position in world coordinates
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Only update location on the server
	if (HasAuthority() && ActiveTriggerCount > 0)
	{
		// Initialize the location of the object with its current location, then update its value
		FVector LocationPerTick = GetActorLocation();

		// Find the direction and magnitude of the path to be followed
		FVector Path = GlobalTargetLocation - GlobalStartLocation;
		float PathDistance = Path.Size();
		FVector PathDirection = Path.GetSafeNormal();

		// Swap direction if the target reaches its destination
		{
			FVector PathTravelled = LocationPerTick - GlobalStartLocation;
			float DistanceTravelled = PathTravelled.Size();

			if (DistanceTravelled >= PathDistance)
			{
				Swap(GlobalStartLocation, GlobalTargetLocation);
			}
		}
		
		// Update the position of the platform each frame
		LocationPerTick += PathDirection * Speed * DeltaTime;
		SetActorLocation(LocationPerTick);
	}
}

