﻿// Copyright (C) Varian Daemon. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "O_TagMetadata.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, meta=(ShowWorldContextPin), EditInlineNew, DefaultToInstanced, CollapseCategories)
class TAGMETADATA_API UO_TagMetadata : public UObject
{
	GENERATED_BODY()
};
