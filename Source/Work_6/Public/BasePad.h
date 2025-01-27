#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "FBoolVector.h"
#include <cmath>
#include "BasePad.generated.h"

using namespace std;

UCLASS()
class WORK_6_API ABasePad : public AActor
{
	GENERATED_BODY()
	
public:	
	ABasePad();

protected:
	//Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BasePad|Componenets")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Componenets")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Componenets")
	UAudioComponent* AudioComp;

	//IsActorLoop
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Move")
	FBoolVector bIsMoveLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Rotation")
	FBoolVector bIsRotateLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	FBoolVector bIsScaleLoop;

	//IsActorUseTimeLimit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Move")
	FBoolVector bIsMoveUseTimeLimit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Rotation")
	FBoolVector bIsRotateUseTimeLimit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	FBoolVector bIsScaleUseTimeLimit;


	//IsComponentLoop
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentMove")
	FBoolVector bIsCompMoveLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentRotation")
	FBoolVector bIsCompRotateLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	FBoolVector bIsCompScaleLoop;
	
	//IsComponentUseTomeLimit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentMove")
	FBoolVector bIsCompMoveUseTimeLimit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentRotation")
	FBoolVector bIsCompRotateUseTimeLimit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	FBoolVector bIsCompScaleUseTimeLimit;

	//IsActorSmoothLoop
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Move")
	FBoolVector IsMoveSmoothLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Rotation")
	FBoolVector IsRotateSmoothLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	FBoolVector IsScaleSmoothLoop;

	//IsComponentSmoothLoop
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentMove")
	FBoolVector IsCompMoveSmoothLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentRotation")
	FBoolVector IsCompRotateSmoothLoop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	FBoolVector IsCompScaleSmoothLoop;
		
	//ActorTransformSpeed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Move")
	FVector3f MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Rotation")
	FVector3f RotateSpeed;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	FVector3f ScaleSpeed;

	//ActorLoopValue
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Move")
	FVector3f MoveLoopDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Rotation")
	FVector3f RotateLoopDegree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	FVector3f ScaleLoopMaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	FVector3f ScaleLoopMinValue;

	//ActorLoopTime
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Move")
	FVector3f MoveLoopTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Rotation")
	FVector3f RotationLoopTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	FVector3f ScaleLoopTime;

	//ActorTransformStartDelay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Move")
	float MoveStartDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Rotation")
	float RotationStartDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|Scale")
	float ScaleStartDelay;

	// ComponentTransformSpeed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentMove")
	FVector3f CompMoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentRotation")
	FVector3f CompRotateSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	FVector3f CompScaleSpeed;

	//ComponentLoopValue
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentMove")
	FVector3f CompMoveLoopDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentRotation")
	FVector3f CompRotateLoopDegree;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	FVector3f CompScaleLoopMaxValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	FVector3f CompScaleLoopMinValue;

	//ComponentLoopTime
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentMove")
	FVector3f CompMoveLoopTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentRotation")
	FVector3f CompRotationLoopTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	FVector3f CompScaleLoopTime;

	//ComponentTransformDelay
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentMove")
	float CompMoveStartDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentRotation")
	float CompRotationStartDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasePad|ComponentScale")
	float CompScaleStartDelay;


	FVector3f StartPosition;


	FVector3f TotalDistance;
	FVector3f TotalDegree;
	FVector3f TotalScale;
	
	FVector3f TotalMoveTime;
	FVector3f TotalRotateTime;
	FVector3f TotalScaleTime;

	FVector3f CompTotalDistance;
	FVector3f CompTotalDegree;
	FVector3f CompTotalScale;
	
	FVector3f CompTotalMoveTime;
	FVector3f CompTotalRotateTime;
	FVector3f CompTotalScaleTime;

	FVector3f MoveStartSpeed;
	FVector3f RotateStartSpeed;
	FVector3f ScaleStartSpeed;

	FVector3f CompMoveStartSpeed;
	FVector3f CompRotateStartSpeed;
	FVector3f CompScaleStartSpeed;

	FVector3f MoveDirection;
	FVector3f RotateDirection;
	FVector3f ScaleDirection;

	FVector3f CompMoveDirection;
	FVector3f CompRotateDirection;
	FVector3f CompScaleDirection;


	float DelayTime;
	float SinValue;
	float Pi;




	UFUNCTION(BlueprintCallable, Category = "BasePad|Function")
	void SetActorPosition(float X, float Y, float Z);
	

	void SetActorRotation(float DeltaTime);
	void SetActorMoving(float DeltaTime);
	void SetActorScale(float DeltaTime);
	void SetComponentRotation(float DeltaTime);
	void SetComponentMoving(float DeltaTime);
	void SetComponentScale(float DeltaTime);
	void GetStartPosition();
	void GetStartSpeed();
	void SetLoopValue(bool IsLoopAxis, bool IsTimeLimit, bool IsSmoothLoop, float& TotalValue, float& TotalTime, float& CurrentSpeed, float DeltaTime, float LoopValue, float LoopTime, float StartSpeed, float& Direction);

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
