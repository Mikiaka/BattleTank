// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT("AIController not posessing a tank")); }
	else { UE_LOG(LogTemp, Warning, TEXT("AIController posessing: %s"), *(ControlledTank->GetName())); }

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) { UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found")); }
	else { UE_LOG(LogTemp, Warning, TEXT("AIController found PlayerTank: %s"), *(PlayerTank->GetName())); }
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


