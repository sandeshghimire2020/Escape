// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Door_2.h"
#include "GameFramework\Actor.h"

// Sets default values for this component's properties
UDoor_2::UDoor_2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoor_2::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw = TargetYaw + InitialYaw;
	
	if (!Press)
	{
		UE_LOG(LogTemp, Error, TEXT("%s It has component on it but the Press is not on  "), *GetOwner()->GetName());

	}
	

	
	ActorOpenDoors = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	
}


// Called every frame
void UDoor_2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(Press && Press->IsOverlappingActor(ActorOpenDoors))
		{
			OpenDoor(DeltaTime);
			DoorLastOpened = GetWorld()->GetTimeSeconds();
		}
		else
		{
			if(GetWorld()->GetTimeSeconds() - DoorLastOpened > DoorCloseDelay)
			{
			CloseDoor(DeltaTime);
			}
		}

	
}

void UDoor_2::OpenDoor(float DeltaTime){

	// UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	// UE_LOG(LogTemp, Warning, TEXT("This is yaw: %f"), GetOwner()->GetActorRotation().Yaw);


	CurrentYaw= FMath::FInterpTo(CurrentYaw,TargetYaw,DeltaTime,DoorOpenSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

}
void UDoor_2::CloseDoor(float DeltaTime){


	CurrentYaw= FMath::FInterpTo(CurrentYaw,InitialYaw,DeltaTime,DoorCloseSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

}