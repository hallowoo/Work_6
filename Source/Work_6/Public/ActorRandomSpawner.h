// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorRandomSpawner.generated.h"

UCLASS()
class WORK_6_API AActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	

	AActorSpawner();

	UFUNCTION()
	void SpawnActor();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpawnActor|Components")
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Components")
	class UBoxComponent* SpawnExtent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Class")
	TSubclassOf<AActor> ActorClassToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Spawn")
	bool bIsSpawnAtOnce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Spawn")
	bool bIsRandomLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Spawn")
	bool bIsRandomRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Spawn")
	int HowManySpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Spawn")
	float SpawnInterval;

	int SpawnNumber;

	FVector BoxExtent;
	FVector MaxRange;
	FVector MinRange;
	FVector RandomLocationRange;
	FRotator RandomRotateRange;
	FTimerHandle SpawnTimer;
	bool bIsTimerActive;


	virtual void BeginPlay() override;

	void GetBoxExtent();
	void SetRandomRange();
};
