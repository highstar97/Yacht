#pragma once

#include "Blueprint/UserWidget.h"
#include "YachtMainWidget.generated.h"

class UTextBlock;
class UButton;
class UYachtScoreChartWidget;
class UYachtSlotWidget;

UCLASS()
class YACHT_API UYachtMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void Roll();

protected:
	virtual void NativeConstruct() override;

private:
	void UpdateTextPlayer();

	void UpdateTextLeft();

	void PredictScore();
	void UnPredictScore();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UTextBlock* TEXT_Player;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UTextBlock* TEXT_Lefts;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UButton* Button_Roll;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UYachtScoreChartWidget* ScoreChartWidget;

	UPROPERTY(VisibleAnywhere, Category = "Playing", meta = (BindWidget))
		UYachtSlotWidget* SlotWidget;

private:
	int32 Player;
	int32 LeftTurn;
};
