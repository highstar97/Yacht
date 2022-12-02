#pragma once

#include "Blueprint/UserWidget.h"
#include "YachtSlotWidget.generated.h"

class UTextBlock;
class UButton;

UCLASS()
class YACHT_API UYachtSlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void Roll(int32 DiceNumber);

	UFUNCTION(BlueprintCallable)
	void KeepDice(int32 i);

	TMap<int32, int32> GetDiceMap();

protected:
	virtual void NativeConstruct() override;

private:
	void InitKeepDiceArray();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UTextBlock* TEXT_Dice1;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UTextBlock* TEXT_Dice2;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UTextBlock* TEXT_Dice3;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UTextBlock* TEXT_Dice4;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UTextBlock* TEXT_Dice5;

private:
	UPROPERTY(BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = true))
		TArray<UTextBlock*> DiceArray;

	UPROPERTY(BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = true))
		TArray<bool> KeepDiceArray;
};