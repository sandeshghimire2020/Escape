// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Door_2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UDoor_2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoor_2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
private:
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float TargetYaw=90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* Press;

	UPROPERTY(EditAnywhere)
	AActor* ActorOpenDoors;
	
	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.6f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed=2.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed=3.f;

	
		
};
