// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCamera.h"

// Sets default values
AMyCamera::AMyCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetRelativeRotation(RotationCamera);

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	SplineComponent->SetupAttachment(GetRootComponent());
	SplineComponent->SetRelativeRotation(FRotator(0,0,90));

}

// Called when the game starts or when spawned
void AMyCamera::BeginPlay()
{
	Super::BeginPlay();
	MyCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}

// Called every frame
void AMyCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MovmentCamera)
	{
		CameraLocation = SplineComponent->FindLocationClosestToWorldLocation(MyCharacter->GetActorLocation(), ESplineCoordinateSpace::World);
		
		CameraLocation = FVector(CameraLocation.X, CameraLocation.Y, MyCharacter->GetActorLocation().Z);

		CameraComponent->SetWorldLocation(CameraLocation + OffsetCamera);
	}

}

