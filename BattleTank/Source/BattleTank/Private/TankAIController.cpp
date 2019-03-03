// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"



ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto player = GetPlayerTank();

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
