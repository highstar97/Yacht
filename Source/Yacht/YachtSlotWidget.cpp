#include "YachtSlotWidget.h"
#include "YachtGameModeBase.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Styling/SlateColor.h"

void UYachtSlotWidget::KeepDice(int32 i)
{
	FSlateColor Keeping = FSlateColor(FColor::Red);
	FSlateColor UnKeeping = FSlateColor(FColor::White);
	
	switch (i)
	{
	case(1):
	{
		KeepDiceArray[i - 1] ? TEXT_Dice1->SetColorAndOpacity(UnKeeping) : TEXT_Dice1->SetColorAndOpacity(Keeping);
		break;
	}
	case(2):
	{
		KeepDiceArray[i - 1] ? TEXT_Dice2->SetColorAndOpacity(UnKeeping) : TEXT_Dice2->SetColorAndOpacity(Keeping);
		break;
	}
	case(3):
	{
		KeepDiceArray[i - 1] ? TEXT_Dice3->SetColorAndOpacity(UnKeeping) : TEXT_Dice3->SetColorAndOpacity(Keeping);
		break;
	}
	case(4):
	{
		KeepDiceArray[i - 1] ? TEXT_Dice4->SetColorAndOpacity(UnKeeping) : TEXT_Dice4->SetColorAndOpacity(Keeping);
		break;
	}
	case(5):
	{
		KeepDiceArray[i - 1] ? TEXT_Dice5->SetColorAndOpacity(UnKeeping) : TEXT_Dice5->SetColorAndOpacity(Keeping);
		break;
	}
	default:
	{
		UE_LOG(LogTemp, Warning, TEXT("SlotWidget->KeepDice : Input Error"));
		break;
	}
	}
	KeepDiceArray[i-1] = !KeepDiceArray[i-1];
}

TMap<int32, int32> UYachtSlotWidget::GetDiceMap()
{
	TMap<int32, int32> TempMap;
	for (int32 i = 1; i <= 6; ++i)
	{
		TempMap.Emplace(i, 0);
	}

	for (int32 i = 0; i < 5; ++i)
	{
		int32 Elem = FCString::Atoi(*(DiceArray[i]->GetText()).ToString());
		if (TempMap.Contains(Elem))
		{
			++TempMap[Elem];
		}
	}

	return TempMap;
}

void UYachtSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AYachtGameModeBase* GameMode = Cast<AYachtGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->OnPlayerChanged.AddUObject(this, &UYachtSlotWidget::InitKeepDiceArray);
	}

	KeepDiceArray.Init(false, 5);
	DiceArray.Emplace(TEXT_Dice1);
	DiceArray.Emplace(TEXT_Dice2);
	DiceArray.Emplace(TEXT_Dice3);
	DiceArray.Emplace(TEXT_Dice4);
	DiceArray.Emplace(TEXT_Dice5);
}

void UYachtSlotWidget::InitKeepDiceArray()
{
	for (int32 i = 1; i <= 5; ++i)
	{
		if (KeepDiceArray[i-1])
		{
			KeepDice(i);
		}
	}
}

void UYachtSlotWidget::Roll(int32 DiceNumber)
{
	if (KeepDiceArray[DiceNumber-1])
	{
		return;
	}
	
	int32 NewDiceNumber = FMath::RandRange(1,6);

	switch (DiceNumber)
	{
	case(1):
	{
		TEXT_Dice1->SetText(FText::FromString(FString::FromInt(NewDiceNumber)));
		break;
	}
	case(2):
	{
		TEXT_Dice2->SetText(FText::FromString(FString::FromInt(NewDiceNumber)));
		break;
	}
	case(3):
	{
		TEXT_Dice3->SetText(FText::FromString(FString::FromInt(NewDiceNumber)));
		break;
	}
	case(4):
	{
		TEXT_Dice4->SetText(FText::FromString(FString::FromInt(NewDiceNumber)));
		break;
	}
	case(5):
	{
		TEXT_Dice5->SetText(FText::FromString(FString::FromInt(NewDiceNumber)));
		break;
	}
	default:
	{
		UE_LOG(LogTemp, Warning, TEXT("SlotWidget->Roll : Input Error"));
		break;
	}
	}
}