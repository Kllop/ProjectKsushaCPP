// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SceneComponent.h"
#include "MyCamera.generated.h"

UCLASS()
class PROJECTKSUSHACPP_API AMyCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCamera();
	ACharacter* MyCharacter;
	FVector CameraLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USplineComponent* SplineComponent;
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
	bool MovmentCamera = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
	FRotator RotationCamera = FRotator(0,0,0);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
	FVector OffsetCamera = FVector(0, 0, 200);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
