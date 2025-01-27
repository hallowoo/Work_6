// Fill out your copyright notice in the Description page of Project Settings.


#include "Flash.h"
#include "Particles/ParticleSystemComponent.h"


AFlash::AFlash()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneComponent);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneComponent);

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	ParticleComp->SetupAttachment(SceneComponent);
	ParticleComp->SetAbsolute(false, true, false);


	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = FVector(0.0f, 0.0f, 0.0f);
	FlashOffsetManual = FVector(0.0f, 0.0f, 0.0f);
	RandomFlashOffsetMax = FVector(0.0f, 0.0f, 0.0f);
	RandomFlashOffsetMin = FVector(0.0f, 0.0f, 0.0f);

	FlashRotateManual = FRotator(0.0f, 0.0f, 0.0f);
	RandomFlashRotateMax = FRotator(0.0f, 0.0f, 0.0f);
	RandomFlashRotateMin = FRotator(0.0f, 0.0f, 0.0f);

	FlashOffset = FVector(0.0f, 0.0f, 0.0f);
	FlashRotate = FRotator(0.0f, 0.0f, 0.0f);
	FlashPeriod = 0.0f;
	bIsFlashLooping = true;
	bIsFlashRandomOffset = false;
	bIsFlashRandomRotate = false;
}

void AFlash::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(Timer, this, &AFlash::MoveFlash , FlashPeriod, bIsFlashLooping);
}

void AFlash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ActorMove(DeltaTime);
}

void AFlash::MoveFlash()
{
	if (!bIsFlashRandomOffset)
	{
		SetFlashOffsetManual();
		AddActorLocalOffset(FlashOffset);
		FlashOffset *= -1.0f;
	}
	else if (bIsFlashRandomOffset)
	{
		SetFlashOffsetRandom();
		AddActorLocalOffset(FlashOffset);
	}

	if (!bIsFlashRandomRotate)
	{
		SetFlashRotateManual();
		AddActorLocalRotation(FlashRotate);
		FlashRotate *= -1.0f;
	}
	else if (bIsFlashRandomRotate)
	{
		SetFlashRotateRandom();
		AddActorLocalRotation(FlashRotate);
	}
}

void AFlash::ActorMove(float DeltaTime)
{
	FVector MoveTick = MoveSpeed * DeltaTime;
	AddActorLocalOffset(MoveTick);
}

void AFlash::SetFlashOffsetRandom()
{
	FlashOffset.X = FMath::RandRange(RandomFlashOffsetMin.X, RandomFlashOffsetMax.X);
	FlashOffset.Y = FMath::RandRange(RandomFlashOffsetMin.Y, RandomFlashOffsetMax.Y);
	FlashOffset.Z = FMath::RandRange(RandomFlashOffsetMin.Z, RandomFlashOffsetMax.Z);
}

void AFlash::SetFlashOffsetManual()
{
	FlashOffset = FlashOffsetManual;
}

void AFlash::SetFlashRotateRandom()
{
	FlashRotate.Roll = FMath::RandRange(RandomFlashRotateMin.Roll, RandomFlashRotateMax.Roll);
	FlashRotate.Pitch = FMath::RandRange(RandomFlashRotateMin.Pitch, RandomFlashRotateMax.Pitch);
	FlashRotate.Yaw = FMath::RandRange(RandomFlashRotateMin.Yaw, RandomFlashRotateMax.Yaw);

}

void AFlash::SetFlashRotateManual()
{
	FlashRotate = FlashRotateManual;
}