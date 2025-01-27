

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomPuzzle.generated.h"

UCLASS()
class WORK_6_API ARandomPuzzle : public AActor
{
	GENERATED_BODY()
	
public:	

	ARandomPuzzle();


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RandomPuzzle | Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor|Components")
	class UBoxComponent* SpawnExtent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomPuzzle | Components")
	TSubclassOf<AActor> SpawnClass;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomPuzzle | Properties")
	int CourseLength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomPuzzle | Properties")
	int CourseWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomPuzzle | Properties")
	float Interval;

	FVector MoveLocation;
	int PrevRand;
	int RandNum;
	int SpawnNumber;


	virtual void BeginPlay() override;

	void SetRandomCourse();

};
