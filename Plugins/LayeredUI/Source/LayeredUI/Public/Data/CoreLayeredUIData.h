﻿#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CoreLayeredUIData.generated.h"

USTRUCT(BlueprintType)
struct FWidgetLayer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Categories = "Layer"))
	FGameplayTag Layer;

	//Delta is set to 100, and is recommended to keep every layer be 100
	//integer away from each other. This should leave plenty of space
	//for designers, if for whatever reason they want to add a widget
	//and not incorporate it into the widget layering system, to decide
	//on their own ZOrder.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Delta = 100))
	int32 ZOrder;

	bool operator==(const FWidgetLayer& Argument) const
	{
		return Argument.Layer == Layer;
	}
};
FORCEINLINE uint32 GetTypeHash(const FWidgetLayer& Thing)
{
	uint32 Hash = FCrc::MemCrc32(&Thing.Layer, sizeof(FWidgetLayer));
	return Hash;
}

USTRUCT(BlueprintType)
struct FLayeredWidget
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	UUserWidget* Widget = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Categories = "UI.Layer"))
	FGameplayTag Layer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ZOrder = -1;

	//Used for finding out what is the latest widget on a layer.
	//This is set by getting the length of an array of all the
	//widgets in that layer.
	//Higher the number, the more recent is the widget.
	//NOTE this might be removed.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LayerPriority = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HideCursor = false;

	void ResetStruct();
};

