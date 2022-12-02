#include "YachtGameModeBase.h"
#include "YachtMainWidget.h"

AYachtGameModeBase::AYachtGameModeBase()
{
	Player = 1;
	TurnLeft = 4;
}

void AYachtGameModeBase::NextPlayer()
{
	TurnLeft = 3;
	OnTurnLeftChanged.Broadcast();
	Player == 1 ? Player = 2 : Player = 1;
	OnPlayerChanged.Broadcast();
}

void AYachtGameModeBase::NextTurn()
{
	--TurnLeft;
	if (TurnLeft == -1)
	{
		NextPlayer();
	}
	OnTurnLeftChanged.Broadcast();
}