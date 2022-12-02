#include "YachtMainWidget.h"
#include "YachtGameModeBase.h"
#include "YachtScoreChartWidget.h"
#include "YachtSlotWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UYachtMainWidget::Roll()
{
	UnPredictScore();
	for (int32 i = 1; i <= 5; ++i)
	{
		SlotWidget->Roll(i);
	}
	PredictScore();

	Cast<AYachtGameModeBase>(GetWorld()->GetAuthGameMode())->NextTurn();
}

void UYachtMainWidget::NativeConstruct()
{
	auto GameMode = Cast<AYachtGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->OnPlayerChanged.AddUObject(this, &UYachtMainWidget::UpdateTextPlayer);
		GameMode->OnTurnLeftChanged.AddUObject(this, &UYachtMainWidget::UpdateTextLeft);
	}
}

void UYachtMainWidget::UpdateTextPlayer()
{
	FString TempString = TEXT("Player");
	auto GameMode = Cast<AYachtGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		switch (GameMode->GetPlayer())
		{
		case(1):
		{
			TempString.Append(TEXT("1"));
			break;
		}
		case(2):
		{
			TempString.Append(TEXT("2"));
			break;
		}
		default:
		{
			UE_LOG(LogTemp, Warning, TEXT("MainWidget->UpdateTextPlayer : Wrong Player"));
			break;
		}
		}
	}
	TEXT_Player->SetText(FText::FromString(TempString));
}

void UYachtMainWidget::UpdateTextLeft()
{
	FString TempString = TEXT("Turn ");
	auto GameMode = Cast<AYachtGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		switch (GameMode->GetTurnLeft())
		{
		case(0):
		{
			TempString.Append(TEXT("0"));
			break;
		}
		case(1):
		{
			TempString.Append(TEXT("1"));
			break;
		}
		case(2):
		{
			TempString.Append(TEXT("2"));
			break;
		}
		case(3):
		{
			TempString.Append(TEXT("3"));
			break;
		}
		default:
		{
			UE_LOG(LogTemp, Warning, TEXT("MainWidget->UpdateTextLeft : Wrong Player"));
			break;
		}
		}
	}
	TempString.Append(TEXT(" Lefts"));
	TEXT_Lefts->SetText(FText::FromString(TempString));
}

void UYachtMainWidget::PredictScore()
{
	ScoreChartWidget->PredictScore(SlotWidget->GetDiceMap());
}

void UYachtMainWidget::UnPredictScore()
{
	ScoreChartWidget->UnPredictScore();
}