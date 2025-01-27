#include "PopPad.h"

APopPad::APopPad()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneComponent);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneComponent);

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	RotationSpeedCheck = RotationSpeed.X + RotationSpeed.Y + RotationSpeed.Z;

	SwooshTimeMax = 0;
	SwooshTimeMin = 0;

	SwooshTime = 0;
	IsSwoosh = false;
	SwooshSumTime;
	ToggleCount = 0;
}

void APopPad::BeginPlay()
{
	Super::BeginPlay();
	SwooshTime = FMath::RandRange(SwooshTimeMin, SwooshTimeMax);
}

void APopPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SwooshSumTime += DeltaTime;	
	SwooshComponent(StaticMeshComp, SwooshSumTime);
	AddActorRotation(DeltaTime);
}

void APopPad::AddActorRotation(float DeltaTime)
{
	AddActorLocalRotation(FRotator(RotationSpeed.Y * DeltaTime, RotationSpeed.Z * DeltaTime, RotationSpeed.X * DeltaTime));
}


void APopPad::SwooshComponent(UStaticMeshComponent* ComponentName, float &Time)
{
	
	if (IsSwoosh)
	{		
		if (ToggleCount == 0 && Time >= SwooshTime)
		{
			ComponentName->ToggleVisibility();
			ComponentName->SetCollisionProfileName("NoCollision");
			SwooshTime = FMath::RandRange(SwooshTimeMin, SwooshTimeMax);
			ToggleCount = 1;
			Time = 0;

		}
		else if (ToggleCount == 1 && Time >= SwooshTime/3)
		{
			ComponentName->ToggleVisibility();
			ComponentName->SetCollisionProfileName("Default");
			SwooshTime = FMath::RandRange(SwooshTimeMin, SwooshTimeMax);
			ToggleCount = 0;
			Time = 0;
		}
	}
}
