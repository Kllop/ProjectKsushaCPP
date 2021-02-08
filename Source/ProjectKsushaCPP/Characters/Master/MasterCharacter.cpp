// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterCharacter.h"


// Sets default values
AMasterCharacter::AMasterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMasterCharacter::MoveForward(float Axis)
{
	AddMovementInput(FVector(1, 0, 0), Axis);
}

void AMasterCharacter::MoveRight(float Axis)
{
	AddMovementInput(FVector(0, 1, 0), Axis);
}

// Called when the game starts or when spawned
void AMasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMasterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMasterCharacter::MoveRight);

}

