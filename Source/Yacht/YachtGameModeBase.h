#pragma once

#include "GameFramework/GameModeBase.h"
#include "YachtGameModeBase.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPlayerChanged);
DECLARE_MULTICAST_DELEGATE(FOnTurnLeftChanged);

UCLASS()
class YACHT_API AYachtGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AYachtGameModeBase();

	int32 GetPlayer() { return Player; }
	int32 GetTurnLeft() { return TurnLeft; }

	void NextPlayer();
	void NextTurn();

public:
	FOnPlayerChanged OnPlayerChanged;
	FOnTurnLeftChanged OnTurnLeftChanged;

private:
	int32 Player;
	int32 TurnLeft;
};