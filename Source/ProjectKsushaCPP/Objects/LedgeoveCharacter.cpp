// Fill out your copyright notice in the Description page of Project Settings.


#include "LedgeoveCharacter.h"

// Sets default values
ALedgeoveCharacter::ALedgeoveCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SetRootComponent(SplineComponent);
	SplineComponent->SetLocationAtSplinePoint(0, FVector(Length_Y*(-50), Length_X*(50) - 10, Length_Z*(50) - 10), ESplineCoordinateSpace::Local);
	SplineComponent->SetLocationAtSplinePoint(1, FVector(Length_Y*(50), Length_X*(50) - 10, Length_Z*(50) - 10), ESplineCoordinateSpace::Local);
	
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(GetRootComponent());
	StaticMesh->SetRelativeScale3D(FVector(Length_X, Length_Y, Length_Z));


	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxCollision->SetupAttachment(GetRootComponent());
	BoxCollision->SetRelativeLocation(FVector(0, Length_X * 50, Length_Z * 50 - 11));
	BoxCollision->SetBoxExtent(FVector(BoxCollision->GetScaledBoxExtent().X, Length_Y * 50, BoxCollision->GetScaledBoxExtent().Z));

}

// Called when the game starts or when spawned
void ALedgeoveCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALedgeoveCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

