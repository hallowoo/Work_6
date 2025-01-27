// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorRandomSpawner.h"
#include "Components/BoxComponent.h"
#include "Flash.h"


// Sets default values
AActorSpawner::AActorSpawner()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneComponent);

	SpawnExtent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SpawnExtent->SetupAttachment(SceneComponent);
	SpawnExtent->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	SpawnExtent->SetCollisionProfileName(TEXT("NoCollision"));

	bIsSpawnAtOnce = false;
	bIsRandomLocation = true;
	bIsRandomRotation = true;
	HowManySpawn = 0;
	SpawnNumber = 0;
	BoxExtent = FVector(0.0f, 0.0f, 0.0f);
	MaxRange = FVector(0.0f, 0.0f, 0.0f);
	MinRange = FVector(0.0f, 0.0f, 0.0f);
	RandomLocationRange = FVector(0.0f, 0.0f, 0.0f);
	RandomRotateRange = FRotator(0.0f, 0.0f, 0.0f);
	ActorClassToSpawn = AActor::StaticClass();
	SpawnInterval = 0.0f;
	bIsTimerActive = false;

}

void AActorSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetBoxExtent();
	
	if (ActorClassToSpawn && !bIsSpawnAtOnce)
	{
		GetWorldTimerManager().SetTimer(SpawnTimer, this, &AActorSpawner::SpawnActor, SpawnInterval, true);
		bIsTimerActive = true;
	}
	else if (ActorClassToSpawn && bIsSpawnAtOnce)
	{
		while (SpawnNumber < HowManySpawn)
		{
			SpawnActor();
		}
	}
}

void AActorSpawner::SpawnActor()
{
	SetRandomRange();
	FVector SpawnLocation = GetActorLocation() + RandomLocationRange;
	GetWorld()->SpawnActor<AActor>(ActorClassToSpawn, SpawnLocation, RandomRotateRange);
	SpawnNumber++;
	if (SpawnNumber == HowManySpawn && bIsTimerActive)
	{
		GetWorldTimerManager().ClearTimer(SpawnTimer);
	}
}

void AActorSpawner::GetBoxExtent()
{
	BoxExtent = SpawnExtent->GetScaledBoxExtent();
}

void AActorSpawner::SetRandomRange()
{
	MaxRange = BoxExtent;
	MinRange = BoxExtent * -1.0f;

	FMath::RandInit(FPlatformTime::Cycles());
	if (bIsRandomLocation)
	{
		RandomLocationRange.X = FMath::RandRange(MinRange.X, MaxRange.X);
		RandomLocationRange.Y = FMath::RandRange(MinRange.Y, MaxRange.Y);
		RandomLocationRange.Z = FMath::RandRange(MinRange.Z, MaxRange.Z);
	}

	if (bIsRandomRotation)
	{
		RandomRotateRange.Roll = FMath::RandRange(0.0f, 360.0f);
		RandomRotateRange.Pitch = FMath::RandRange(0.0f, 360.0f);
		RandomRotateRange.Yaw = FMath::RandRange(0.0f, 360.0f);
	}
}