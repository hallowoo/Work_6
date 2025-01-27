#include "BasePad.h"

ABasePad::ABasePad()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	AudioComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

    //IsLoop
	bIsRotateLoop = FBoolVector(false, false, false);
	bIsMoveLoop = FBoolVector(false, false, false);
	bIsScaleLoop = FBoolVector(false, false, false);
	bIsCompRotateLoop = FBoolVector(false, false, false);
	bIsCompMoveLoop = FBoolVector(false, false, false);
	bIsCompScaleLoop = FBoolVector(false, false, false);

	//IsTimeLimit
	bIsMoveUseTimeLimit = FBoolVector(false, false, false);
	bIsRotateUseTimeLimit = FBoolVector(false, false, false);
	bIsScaleUseTimeLimit = FBoolVector(false, false, false);
	bIsCompMoveUseTimeLimit = FBoolVector(false, false, false);
	bIsCompRotateUseTimeLimit = FBoolVector(false, false, false);
	bIsScaleUseTimeLimit = FBoolVector(false, false, false);

	IsMoveSmoothLoop = FBoolVector(false, false, false);
	IsRotateSmoothLoop = FBoolVector(false, false, false);
	IsScaleSmoothLoop = FBoolVector(false, false, false);
	IsCompMoveSmoothLoop = FBoolVector(false, false, false);
	IsCompRotateSmoothLoop = FBoolVector(false, false, false);
	IsCompScaleSmoothLoop = FBoolVector(false, false, false);

	//Speed
	MoveSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	RotateSpeed = FVector3f(0.0f, 0.0f, 0.0f);	
	ScaleSpeed = FVector3f(0.0f, 0.0f, 0.0f);	
	CompMoveSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	CompRotateSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	CompScaleSpeed = FVector3f(0.0f, 0.0f, 0.0f);

	//MaxLoopValue
	RotateLoopDegree = FVector3f(0.0f, 0.0f, 0.0f);
	MoveLoopDistance = FVector3f(0.0f, 0.0f, 0.0f);
	ScaleLoopMaxValue = FVector3f(1.0f, 1.0f, 1.0f);
	ScaleLoopMinValue = FVector3f(1.0f, 1.0f, 1.0f);
	CompRotateLoopDegree = FVector3f(0.0f, 0.0f, 0.0f);
	CompMoveLoopDistance = FVector3f(0.0f, 0.0f, 0.0f);
	CompScaleLoopMaxValue = FVector3f(1.0f, 1.0f, 1.0f);
	CompScaleLoopMinValue = FVector3f(1.0f, 1.0f, 1.0f);
	
	//TotalValue
	TotalDegree = FVector3f(0.0f, 0.0f, 0.0f);
	TotalDistance = FVector3f(0.0f, 0.0f, 0.0f);
	TotalScale = FVector3f(0.0f, 0.0f, 0.0f);
	TotalRotateTime = FVector3f(0.0f, 0.0f, 0.0f);
	TotalMoveTime = FVector3f(0.0f, 0.0f, 0.0f);
	TotalScaleTime = FVector3f(0.0f, 0.0f, 0.0f);
	CompTotalDegree = FVector3f(0.0f, 0.0f, 0.0f);
	CompTotalDistance = FVector3f(0.0f, 0.0f, 0.0f);
	CompTotalScale = FVector3f(0.0f, 0.0f, 0.0f);
	CompTotalRotateTime = FVector3f(0.0f, 0.0f, 0.0f);
	CompTotalMoveTime = FVector3f(0.0f, 0.0f, 0.0f);
	CompTotalScaleTime = FVector3f(0.0f, 0.0f, 0.0f);
	
	//MaxLoopTime
	MoveLoopTime = FVector3f(0.0f, 0.0f, 0.0f);
	RotationLoopTime = FVector3f(0.0f, 0.0f, 0.0f);
	ScaleLoopTime = FVector3f(0.0f, 0.0f, 0.0f);
	CompMoveLoopTime = FVector3f(0.0f, 0.0f, 0.0f);
	CompRotationLoopTime = FVector3f(0.0f, 0.0f, 0.0f);
	CompScaleLoopTime = FVector3f(0.0f, 0.0f, 0.0f);

	//StartDelay
	MoveStartDelay = 0.0f;
	RotationStartDelay = 0.0f;
	ScaleStartDelay = 0.0f;
	CompMoveStartDelay = 0.0f;
	CompRotationStartDelay = 0.0f;
	CompScaleStartDelay = 0.0f;

	MoveDirection = FVector3f(1.0f, 1.0f, 1.0f);
	RotateDirection = FVector3f(1.0f, 1.0f, 1.0f);
	ScaleDirection = FVector3f(1.0f, 1.0f, 1.0f);
	CompMoveDirection = FVector3f(1.0f, 1.0f, 1.0f);
	CompRotateDirection = FVector3f(1.0f, 1.0f, 1.0f);
	CompScaleDirection = FVector3f(1.0f, 1.0f, 1.0f);


	//StartSpeed
	MoveStartSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	RotateStartSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	ScaleStartSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	CompMoveStartSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	CompRotateStartSpeed = FVector3f(0.0f, 0.0f, 0.0f);
	CompScaleStartSpeed = FVector3f(0.0f, 0.0f, 0.0f);

	//StartPosition
	StartPosition = FVector3f(0.0f, 0.0f, 0.0f);

	DelayTime = 0.0f;
	SinValue = 0.0f;
	Pi = 3.141592;
}

void ABasePad::SetActorPosition(float X, float Y, float Z)
{
	SetActorLocation(FVector(X, Y, Z));
}

void ABasePad::BeginPlay()
{
	Super::BeginPlay();
	GetStartPosition();
	GetStartSpeed();
}

void ABasePad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DelayTime += DeltaTime;
	SetActorMoving(DeltaTime);
	SetActorRotation(DeltaTime);
	SetActorScale(DeltaTime);
	SetComponentMoving(DeltaTime);
	SetComponentRotation(DeltaTime);	
	SetComponentScale(DeltaTime);
}

void ABasePad::SetActorMoving(float DeltaTime)
{
	float checkValue = MoveSpeed.X + MoveSpeed.Y + MoveSpeed.Z;

	if (!FMath::IsNearlyZero(checkValue))
	{
		if (MoveStartDelay <= DelayTime)
		{
			SetLoopValue(bIsMoveLoop.X, bIsMoveUseTimeLimit.X, IsMoveSmoothLoop.X, TotalDistance.X, TotalMoveTime.X, MoveSpeed.X, DeltaTime, MoveLoopDistance.X, MoveLoopTime.X, MoveStartSpeed.X, MoveDirection.X);
			SetLoopValue(bIsMoveLoop.Y, bIsMoveUseTimeLimit.Y, IsMoveSmoothLoop.Y, TotalDistance.Y, TotalMoveTime.Y, MoveSpeed.Y, DeltaTime, MoveLoopDistance.Y, MoveLoopTime.Y, MoveStartSpeed.Y, MoveDirection.Y);
			SetLoopValue(bIsMoveLoop.Z, bIsMoveUseTimeLimit.Z, IsMoveSmoothLoop.Z, TotalDistance.Z, TotalMoveTime.Z, MoveSpeed.Z, DeltaTime, MoveLoopDistance.Z, MoveLoopTime.Z, MoveStartSpeed.Z, MoveDirection.Z);

			AddActorLocalOffset(FVector(MoveSpeed.X * DeltaTime, MoveSpeed.Y * DeltaTime, MoveSpeed.Z * DeltaTime));

		}
	}
}

void ABasePad::SetActorRotation(float DeltaTime)
{
	float checkValue = RotateSpeed.X + RotateSpeed.Y + RotateSpeed.Z;
	
	if (!FMath::IsNearlyZero(checkValue))
	{
		if (RotationStartDelay <= DelayTime)
		{
			SetLoopValue(bIsRotateLoop.X, bIsRotateUseTimeLimit.X, IsRotateSmoothLoop.X, TotalDegree.X, TotalRotateTime.X, RotateSpeed.X, DeltaTime, RotateLoopDegree.X, RotationLoopTime.X, RotateStartSpeed.X, RotateDirection.X);
			SetLoopValue(bIsRotateLoop.Y, bIsRotateUseTimeLimit.Y, IsRotateSmoothLoop.Y, TotalDegree.Y, TotalRotateTime.Y, RotateSpeed.Y, DeltaTime, RotateLoopDegree.Y, RotationLoopTime.Y, RotateStartSpeed.Y, RotateDirection.Y);
			SetLoopValue(bIsRotateLoop.Z, bIsRotateUseTimeLimit.Z, IsRotateSmoothLoop.Z, TotalDegree.Z, TotalRotateTime.Z, RotateSpeed.Z, DeltaTime, RotateLoopDegree.Z, RotationLoopTime.Z, RotateStartSpeed.Z, RotateDirection.Z);
			
			AddActorLocalRotation(FRotator(RotateSpeed.Y * DeltaTime, RotateSpeed.Z * DeltaTime, RotateSpeed.X * DeltaTime));

		}
	}	
}

void ABasePad::SetActorScale(float DeltaTime)
{
	float checkValue = ScaleSpeed.X + ScaleSpeed.Y + ScaleSpeed.Z;

	if (!FMath::IsNearlyZero(checkValue))
	{
		if (ScaleStartDelay <= DelayTime)
		{
			if (bIsScaleLoop.X)
			{
				TotalScaleTime.X += DeltaTime;

				if (!bIsScaleUseTimeLimit.X)
				{
					
					float CurrentScaleX = GetActorScale3D().X;
					TotalScale.X += CurrentScaleX * DeltaTime;
					float ScaleRange = ScaleLoopMaxValue.X - ScaleLoopMinValue.X;
					if (IsScaleSmoothLoop.X)
					{
						ScaleSpeed.X = (ScaleStartSpeed.X * (sin(TotalScale.X / ScaleRange) * Pi));
					}
					if (CurrentScaleX > ScaleLoopMaxValue.X || CurrentScaleX < ScaleLoopMinValue.X)
					{
						ScaleDirection.X *= -1.0f;
						TotalScaleTime.X = 0.0f;

						if (!IsScaleSmoothLoop.X)
						{
							ScaleSpeed.X *= ScaleDirection.X;

						}
					}
				}

				else if (bIsScaleUseTimeLimit.X)
				{					
					if (ScaleLoopTime.X < TotalScaleTime.X)
					{
						ScaleSpeed.X *= -1.0f;
						TotalScaleTime.X = 0.0f;
					}
				}
			}

			if (bIsScaleLoop.Y)
			{
				TotalScaleTime.Y += DeltaTime;

				if (!bIsScaleUseTimeLimit.Y)
				{
					float CurrentScaleY = GetActorScale3D().Y;
					TotalScale.Y += CurrentScaleY * DeltaTime;
					float ScaleRange = ScaleLoopMaxValue.Y - ScaleLoopMinValue.Y;

					if (IsScaleSmoothLoop.Y)
					{
						ScaleSpeed.Y = (ScaleStartSpeed.Y * (sin(TotalScale.Y / ScaleRange) * Pi));
					}
					if (CurrentScaleY > ScaleLoopMaxValue.Y || CurrentScaleY < ScaleLoopMinValue.Y)
					{
						ScaleDirection.Y *= -1.0f;
						TotalScaleTime.Y = 0.0f;

						if (!IsScaleSmoothLoop.Y)
						{
							ScaleSpeed.Y *= ScaleDirection.Y;
						}
					}
				}

				else if (bIsScaleUseTimeLimit.Y)
				{					
					if (ScaleLoopTime.Y < TotalScaleTime.Y)
					{
						ScaleSpeed.Y *= -1.0f;
						TotalScaleTime.Y = 0.0f;
					}
				}
			}

			if (bIsScaleLoop.Z)
			{
				TotalScaleTime.Z += DeltaTime;

				if (!bIsScaleUseTimeLimit.Z)
				{
					float CurrentScaleZ = GetActorScale3D().Z;
					TotalScale.Z += CurrentScaleZ * DeltaTime;
					float ScaleRange = ScaleLoopMaxValue.Z - ScaleLoopMinValue.Z;

					if (IsScaleSmoothLoop.Z)
					{
						ScaleSpeed.Z = (ScaleStartSpeed.Z * (sin(TotalScale.Z / ScaleRange) * Pi));
					}
					if (CurrentScaleZ > ScaleLoopMaxValue.Z || CurrentScaleZ < ScaleLoopMinValue.Z)
					{
						ScaleDirection.Z *= -1.0f;
						TotalScaleTime.Z = 0.0f;

						if (!IsScaleSmoothLoop.Z)
						{
							ScaleSpeed.Z *= ScaleDirection.Z;
						}
					}
				}

				else if (bIsScaleUseTimeLimit.Z)
				{					
					if (ScaleLoopTime.Z < TotalScaleTime.Z)
					{
						ScaleSpeed.Z *= -1.0f;
						TotalScaleTime.Z = 0.0f;
					}
				}
			}
			         
			FVector CurrentScale = GetActorScale3D();
			FVector NewScale = CurrentScale * FVector(1.0f + ScaleSpeed.X * DeltaTime, 1.0f + ScaleSpeed.Y * DeltaTime, 1.0f + ScaleSpeed.Z * DeltaTime);
			SetActorScale3D(NewScale);

		}
	}
}

void ABasePad::SetComponentMoving(float DeltaTime)
{
	float checkValue = CompMoveSpeed.X + CompMoveSpeed.Y + CompMoveSpeed.Z;

	if (!FMath::IsNearlyZero(checkValue))
	{
		if (CompMoveStartDelay <= DelayTime)
		{
			SetLoopValue(bIsCompMoveLoop.X, bIsCompMoveUseTimeLimit.X, IsCompMoveSmoothLoop.X, CompTotalDistance.X, CompTotalMoveTime.X, CompMoveSpeed.X, DeltaTime, CompMoveLoopDistance.X, CompMoveLoopTime.X, CompMoveStartSpeed.X, CompMoveDirection.X);
			SetLoopValue(bIsCompMoveLoop.Y, bIsCompMoveUseTimeLimit.Y, IsCompMoveSmoothLoop.Y, CompTotalDistance.Y, CompTotalMoveTime.Y, CompMoveSpeed.Y, DeltaTime, CompMoveLoopDistance.Y, CompMoveLoopTime.Y, CompMoveStartSpeed.Y, CompMoveDirection.Y);
			SetLoopValue(bIsCompMoveLoop.Z, bIsCompMoveUseTimeLimit.Z, IsCompMoveSmoothLoop.Z, CompTotalDistance.Z, CompTotalMoveTime.Z, CompMoveSpeed.Z, DeltaTime, CompMoveLoopDistance.Z, CompMoveLoopTime.Z, CompMoveStartSpeed.Z, CompMoveDirection.Z);

			StaticMeshComp->AddRelativeLocation(FVector(CompMoveSpeed.X * DeltaTime, CompMoveSpeed.Y * DeltaTime, CompMoveSpeed.Z * DeltaTime));

		}
	}
}

void ABasePad::SetComponentRotation(float DeltaTime)
{
	float checkValue = CompRotateSpeed.X + CompRotateSpeed.Y + CompRotateSpeed.Z;

	if (!FMath::IsNearlyZero(checkValue))
	{
		if (CompRotationStartDelay <= DelayTime)
		{
			SetLoopValue(bIsCompRotateLoop.X, bIsCompRotateUseTimeLimit.X, IsCompRotateSmoothLoop.X, CompTotalDegree.X, CompTotalRotateTime.X, CompRotateSpeed.X, DeltaTime, CompRotateLoopDegree.X, CompRotationLoopTime.X, CompRotateStartSpeed.X, CompRotateDirection.X);
			SetLoopValue(bIsCompRotateLoop.Y, bIsCompRotateUseTimeLimit.Y, IsCompRotateSmoothLoop.Y, CompTotalDegree.Y, CompTotalRotateTime.Y, CompRotateSpeed.Y, DeltaTime, CompRotateLoopDegree.Y, CompRotationLoopTime.Y, CompRotateStartSpeed.Y, CompRotateDirection.Y);
			SetLoopValue(bIsCompRotateLoop.Z, bIsCompRotateUseTimeLimit.Z, IsCompRotateSmoothLoop.Z, CompTotalDegree.Z, CompTotalRotateTime.Z, CompRotateSpeed.Z, DeltaTime, CompRotateLoopDegree.Z, CompRotationLoopTime.Z, CompRotateStartSpeed.Z, CompRotateDirection.Z);

			StaticMeshComp->AddRelativeRotation(FRotator(CompRotateSpeed.Y * DeltaTime, CompRotateSpeed.Z * DeltaTime, CompRotateSpeed.X * DeltaTime));

		}
	}
}

void ABasePad::SetComponentScale(float DeltaTime)
{
	float checkValue = CompScaleSpeed.X + CompScaleSpeed.Y + CompScaleSpeed.Z;

	if (!FMath::IsNearlyZero(checkValue))
	{
		if (CompScaleStartDelay <= DelayTime)
		{
			if (bIsCompScaleLoop.X)
			{
				CompTotalScaleTime.X += DeltaTime;

				if (!bIsCompScaleUseTimeLimit.X)
				{
					float CurrentCompScaleX = StaticMeshComp->GetRelativeScale3D().X;
					CompTotalScale.X += CurrentCompScaleX * DeltaTime;
					float ScaleRange = CompScaleLoopMaxValue.X - CompScaleLoopMinValue.X;
					if (IsCompScaleSmoothLoop.X)
					{
						CompScaleSpeed.X = (CompScaleStartSpeed.X * (sin( CompTotalScale.X / ScaleRange) * Pi));
					}
					if (CurrentCompScaleX > CompScaleLoopMaxValue.X || CurrentCompScaleX < CompScaleLoopMinValue.X)
					{
						CompScaleDirection.X *= -1.0f;
						CompTotalScaleTime.X = 0.0f;

						if (!IsCompScaleSmoothLoop.X)
						{
							CompScaleSpeed.X *= CompScaleDirection.X;
						}
					}
				}

				else if (bIsCompScaleUseTimeLimit.X)
				{					
					if (CompScaleLoopTime.X < CompTotalScaleTime.X)
					{
						CompScaleSpeed.X *= -1.0f;
						CompTotalScaleTime.X = 0.0f;
					}
				}
			}

			if (bIsCompScaleLoop.Y)
			{
				CompTotalScaleTime.Y += DeltaTime;

				if (!bIsCompScaleUseTimeLimit.Y)
				{
					float CurrentCompScaleY = StaticMeshComp->GetRelativeScale3D().Y;
					CompTotalScale.Y += CurrentCompScaleY * DeltaTime;
					float ScaleRange = CompScaleLoopMaxValue.Y - CompScaleLoopMinValue.Y;

					if (IsCompScaleSmoothLoop.Y)
					{
						CompScaleSpeed.Y = (CompScaleStartSpeed.Y * (sin(CompTotalScale.Y / ScaleRange) * Pi));
					}
					if (CurrentCompScaleY > CompScaleLoopMaxValue.Y || CurrentCompScaleY < CompScaleLoopMinValue.Y)
					{
						CompScaleDirection.Y *= -1.0f;
						CompTotalScaleTime.Y = 0.0f;

						if (!IsCompScaleSmoothLoop.Y)
						{
							CompScaleSpeed.Y *= CompScaleDirection.Y;
						}
					}
				}

				else if (bIsCompScaleUseTimeLimit.Y)
				{
					if (CompScaleLoopTime.Y < CompTotalScaleTime.Y)
					{
						CompScaleSpeed.Y *= -1.0f;
						CompTotalScaleTime.Y = 0.0f;
					}
				}
			}

			if (bIsCompScaleLoop.Z)
			{
				CompTotalScaleTime.Z += DeltaTime;

				if (!bIsCompScaleUseTimeLimit.Z)
				{
					float CurrentCompScaleZ = StaticMeshComp->GetRelativeScale3D().Z;
					CompTotalScale.Z = CurrentCompScaleZ * DeltaTime;
					float ScaleRange = CompScaleLoopMaxValue.Z - CompScaleLoopMinValue.Z;

					if (IsCompScaleSmoothLoop.Z)
					{
						CompScaleSpeed.Z = (CompScaleStartSpeed.Z * (sin(CompTotalScale.Z / ScaleRange) * Pi));
					}
					if (CurrentCompScaleZ > CompScaleLoopMaxValue.Z || CurrentCompScaleZ < CompScaleLoopMinValue.Z)
					{
						CompScaleDirection.Z *= -1.0f;
						CompTotalScaleTime.Z = 0.0f;

						if (!IsCompScaleSmoothLoop.Z)
						{
							CompScaleSpeed.Z *= CompScaleDirection.Z;
						}
					}
				}

				else if (bIsCompScaleUseTimeLimit.Z)
				{
					CompTotalScaleTime.Z += DeltaTime;
					if (CompScaleLoopTime.Z < CompTotalScaleTime.Z)
					{
						CompScaleSpeed.Z *= -1.0f;
						CompTotalScaleTime.Z = 0.0f;
					}
				}
			}

			FVector CurrentScale = StaticMeshComp->GetRelativeScale3D();
			FVector NewScale = CurrentScale * FVector(1.0f + CompScaleSpeed.X * DeltaTime, 1.0f + CompScaleSpeed.Y * DeltaTime, 1.0f + CompScaleSpeed.Z * DeltaTime);
			StaticMeshComp->SetRelativeScale3D(NewScale);

		}
	}
}

void ABasePad::GetStartPosition()
{
	StartPosition = (FVector3f)GetActorLocation();
}

void ABasePad::GetStartSpeed()
{
	MoveStartSpeed = MoveSpeed;
	RotateStartSpeed = RotateSpeed;
	ScaleStartSpeed = ScaleSpeed;
	CompMoveStartSpeed = CompMoveSpeed;
	CompRotateStartSpeed = CompRotateSpeed;
	CompScaleStartSpeed = CompScaleSpeed;
}

void ABasePad::SetLoopValue(bool IsLoopAxis, bool IsTimeLimit, bool IsSmoothLoop, float& TotalValue, float& TotalTime, float& CurrentSpeed, float DeltaTime, float LoopValue, float LoopTime, float StartSpeed, float& Direction)
{
	if (IsLoopAxis)
	{
		if (!IsTimeLimit)
		{
			TotalValue += abs(StartSpeed * DeltaTime);
						
			if (IsSmoothLoop)
			{
				CurrentSpeed = (StartSpeed * (sin(TotalValue / LoopValue * Pi))) * Direction ;
			}			

			if (LoopValue <= TotalValue)
			{
				Direction *= -1.0f;				
				if (!IsSmoothLoop)
				{
					CurrentSpeed *= Direction;
				}
				TotalValue = 0.0f;
			}
			

		}

		else if (IsTimeLimit)
		{
			TotalTime += DeltaTime;

			if (LoopTime <= TotalTime)
			{
				CurrentSpeed *= -1.0f;
				TotalTime = 0.0f;
			}
		}
	}
}