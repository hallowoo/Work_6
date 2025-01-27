// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <cmath>
#include "Blooming.generated.h"

UCLASS()
class WORK_6_API ABlooming : public AActor
{
	GENERATED_BODY()
	
public:	

	ABlooming();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Blooming|Components")
	USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blooming|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blooming|Properties")
	FVector3f ScaleSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blooming|Properties")
	FVector3f MaxScale;


	FVector3f TotalScaleTime;
	FVector3f StartScaleSpeed;
	FVector3f StartScale;	
	float Pi;
	float DelayTime;


	void SetActorScale(float DeltaTime);
	void GetStartScaleInfo();
};
