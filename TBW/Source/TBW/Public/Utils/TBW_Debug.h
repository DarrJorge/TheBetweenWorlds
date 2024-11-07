#pragma once

namespace Debug
{
	DEFINE_LOG_CATEGORY_STATIC(LogTBW_Debug, All, All);

	static void Print(const FString& Msg, const FColor& Color = FColor::MakeRandomColor(), float TimeToDisplay = 1.f, int32 Key = -1)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, TimeToDisplay, Color, Msg);
		}
		UE_LOG(LogTBW_Debug, Warning, TEXT("%s"), *Msg);
	}

	static void Print(const FString& FloatTitle, float FloatValue, const FColor& Color = FColor::MakeRandomColor(),
		float TimeToDisplay = 2.f, int32 Key = -1 )
	{
		const FString FinalMsg = FloatTitle + TEXT(": ") + FString::SanitizeFloat(FloatValue);
		
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, TimeToDisplay, Color, FinalMsg);
		}

		UE_LOG(LogTBW_Debug, Warning, TEXT("%s"), *FinalMsg);
	}

	static void Print(const FString& DoubleTitle, double DoubleValue, const FColor& Color = FColor::MakeRandomColor(),
		float TimeToDisplay = 2.f, int32 Key = -1 )
	{
		const FString FinalMsg = DoubleTitle + TEXT(": ") + FString::SanitizeFloat(static_cast<float>(DoubleValue));
		
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(Key, TimeToDisplay, Color, FinalMsg);
		}

		UE_LOG(LogTBW_Debug, Warning, TEXT("%s"), *FinalMsg);
	}
}
