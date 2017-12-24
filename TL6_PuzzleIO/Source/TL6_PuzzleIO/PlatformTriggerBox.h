// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PlatformTriggerBox.generated.h"

/**
 * A trigger which signals one or more platforms to move.
 */
UCLASS()
class TL6_PUZZLEIO_API APlatformTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	
	APlatformTriggerBox();


protected:
	UPROPERTY(EditAnywhere)
	bool bInhibitsMovement;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	TSet<class AMovingPlatform*> PlatformsToTrigger;

	UPROPERTY(EditAnywhere)
	TSet<class AMovingPlatform*> PlatformsToInhibit;

	UFUNCTION()
	void Activate(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void Deactivate(AActor* OverlappedActor, AActor* OtherActor);

};
