#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Flash.generated.h"

UCLASS()
class WORK_6_API AFlash : public AActor
{
	GENERATED_BODY()
	
public:	

	AFlash();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flash|Components")
	USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Components")
	class UParticleSystemComponent* ParticleComp;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	FVector MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	FRotator RotateSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	FVector FlashOffsetManual;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	FVector RandomFlashOffsetMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	FVector RandomFlashOffsetMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties", meta = (ClampMin = "0.0", ClampMax = "360.0", UIMin = "0.0", UIMax = "360.0"))
	FRotator FlashRotateManual;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties", meta = (ClampMin = "0.0", ClampMax = "360.0", UIMin = "0.0", UIMax = "360.0"))
	FRotator RandomFlashRotateMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties", meta = (ClampMin = "0.0", ClampMax = "360.0", UIMin = "0.0", UIMax = "360.0"))
	FRotator RandomFlashRotateMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	float FlashPeriod;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	bool bIsFlashLooping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	bool bIsFlashRandomOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flash|Properties")
	bool bIsFlashRandomRotate;

	FVector FlashOffset;
	FRotator FlashRotate;
	FTimerHandle Timer;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void MoveFlash();
	void SetFlashOffsetRandom();
	void SetFlashOffsetManual();
	void SetFlashRotateRandom();
	void SetFlashRotateManual();
	void ActorMove(float DeltaTime);
};
