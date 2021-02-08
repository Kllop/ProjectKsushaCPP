// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SplineComponent.h"
#include "Components/BoxComponent.h"
#include "LedgeoveCharacter.generated.h"

UCLASS()
class PROJECTKSUSHACPP_API ALedgeoveCharacter : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ALedgeoveCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float Length_X = 0.2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float Length_Y = 0.2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		float Length_Z = 0.2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
	USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
	UBoxComponent* BoxCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
