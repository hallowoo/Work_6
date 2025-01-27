// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FBoolVector.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct WORK_6_API FBoolVector
{
	GENERATED_BODY()

public:
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Z;

	FBoolVector();
	FBoolVector(bool X, bool Y, bool Z);
	~FBoolVector();
};
