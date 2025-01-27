// Fill out your copyright notice in the Description page of Project Settings.


#include "Blooming.h"


ABlooming::ABlooming()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneComponent);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneComponent);

	PrimaryActorTick.bCanEverTick = true;

	ScaleSpeed = FVector3f(0.0f, 0.0, 0.0f);
	MaxScale = FVector3f(1.0f, 1.0, 1.0f);
	TotalScaleTime = FVector3f(0.0f, 0.0, 0.0f);

	Pi = 3.141592;
	DelayTime = 0.0f;
	StartScaleSpeed = FVector3f(0.0f, 0.0, 0.0f);
	StartScale = FVector3f(1.0f, 1.0, 1.0f);

}

void ABlooming::BeginPlay()
{
	Super::BeginPlay();
	GetStartScaleInfo();
}

void ABlooming::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorScale(DeltaTime);
}

void ABlooming::GetStartScaleInfo()
{
	StartScaleSpeed = ScaleSpeed;
	StartScale = (FVector3f)GetActorScale3D();
}

void ABlooming::SetActorScale(float DeltaTime)
{
	FVector3f CurrentScale = (FVector3f)GetActorScale3D();
	if (!FMath::IsNearlyZero(CurrentScale.X + CurrentScale.Y + CurrentScale.Z))
	{
		TotalScaleTime.X += ScaleSpeed.X * DeltaTime;
		TotalScaleTime.Y += ScaleSpeed.Y * DeltaTime;
		TotalScaleTime.Z += ScaleSpeed.Z * DeltaTime;

		float ScaleRangeX = MaxScale.X - StartScale.X;
		if (CurrentScale.X < MaxScale.X)
		{
			ScaleSpeed.X = StartScaleSpeed.X * sin(TotalScaleTime.X / ScaleRangeX) * Pi;
		}
		else
		{
			ScaleSpeed.X = 0.0f;
		}

		float ScaleIncreaseX = 1.0f + ScaleSpeed.X * DeltaTime;

		float ScaleRangeY = MaxScale.Y - StartScale.Y;
		if (CurrentScale.Y < MaxScale.Y)
		{
			ScaleSpeed.Y = StartScaleSpeed.Y * sin(TotalScaleTime.Y / ScaleRangeY) * Pi;
		}
		else
		{
			ScaleSpeed.Y = 0.0f;
		}

		float ScaleIncreaseY = 1.0f + ScaleSpeed.Y * DeltaTime;

		float ScaleRangeZ = MaxScale.Z - StartScale.Z;
		if (CurrentScale.Z < MaxScale.Z)
		{
			ScaleSpeed.Z = StartScaleSpeed.Z * sin(TotalScaleTime.Z / ScaleRangeZ) * Pi;
		}
		else
		{
			ScaleSpeed.Z = 0.0f;
		}

		float ScaleIncreaseZ = 1.0f + ScaleSpeed.Z * DeltaTime;

		SetActorScale3D(FVector(CurrentScale.X * ScaleIncreaseX, CurrentScale.Y * ScaleIncreaseY, CurrentScale.Z * ScaleIncreaseZ));
	}
}