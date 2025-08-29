// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = GetActorLocation();
	zeroLocation = FVector(0, 0, 0);
	UE_LOG(LogTemp, Warning, TEXT("HELLO"));
	for(int32 i = 0; i < 10; i++) Move(CurrentLocation);
	UE_LOG(LogTemp, Display, TEXT("Total Distance : %f"), Distance(zeroLocation, CurrentLocation));

}

// Called every frame 
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move(FVector& Location)
{
	FVector beforeLocation = Location;
	Location.X += Step();
	Location.Y += Step();
	Location.Z += Step();
	if (FMath::RandRange(0, 1) == 1) UE_LOG(LogTemp, Warning, TEXT("!!EVNET!!"));
	UE_LOG(LogTemp, Display, TEXT("Distance : %f"), Distance(beforeLocation, Location));
	SetActorLocation(Location);
	UE_LOG(LogTemp, Display, TEXT("Location (%f , %f , %f)"), Location.X, Location.Y, Location.Z);
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::Distance(FVector& beforeLocation, FVector& afterLocation)
{
	return sqrt(pow(afterLocation.X - beforeLocation.X, 2) + pow(afterLocation.Y - beforeLocation.Y, 2));
}
