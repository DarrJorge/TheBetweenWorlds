// DarrJorge All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Types/TBW_Enums.h"
#include "TBW_MainLayoutWidget.generated.h"

class UCommonActivatableWidgetStack;

UCLASS()
class TBW_API UTBW_MainLayoutWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void PushDefaultHUD();

	UFUNCTION(BlueprintImplementableEvent)
	void PushGameInventoryHUD();

	void SelectWidget(ETBWGameState InGameState);

protected:

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> GameHUDStack;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> GameInventoryStack;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UCommonActivatableWidgetStack> GameMenuStack;

	UPROPERTY(BlueprintReadWrite)
	bool bGameDefaultLayoutActive = false;

	UPROPERTY(BlueprintReadWrite)
	bool bGameInventoryLayoutActive = false;

	UPROPERTY(BlueprintReadWrite)
	bool bGameMenuLayoutActive = false;
};
