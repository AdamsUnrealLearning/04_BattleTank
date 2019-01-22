// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto tank = GetAITank();

	auto player = GetPlayerTank();

	if (!tank) {
		UE_LOG(LogTemp, Warning, TEXT("Not possesing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank %s calling for duty!"), *tank->GetName())
	}

	if (!player) {
		UE_LOG(LogTemp, Warning, TEXT("\nPlayer not found"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("\nPlayers tank %s!"), *player->GetName())
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {



		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!playerPawn) {
		return nullptr;
	}
	else {
		return Cast<ATank>(playerPawn);
	}
}
