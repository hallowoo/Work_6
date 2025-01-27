#pragma once

#include "CoreMinimal.h"
#include "FBoolVector.h"
#include <cmath>
#include "GameFramework/Actor.h"
#include "PopPad.generated.h"

UCLASS()
class WORK_6_API APopPad : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APopPad();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PopPad|Components")
	USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PopPad|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PopPad|Rotation")
	FVector3f RotationSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PopPad|Swoosh")
	bool IsSwoosh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PopPad|Swoosh")
	float SwooshTime;
	
	
	float RotationSpeedCheck;
	float SwooshSumTime;
	int ToggleCount;
	void AddActorRotation(float DeltaTime);
	void SwooshComponent(UStaticMeshComponent* ComponentName, float &Time);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	

};
