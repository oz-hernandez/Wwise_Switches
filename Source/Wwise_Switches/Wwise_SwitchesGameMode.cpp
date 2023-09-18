// Copyright Epic Games, Inc. All Rights Reserved.

#include "Wwise_SwitchesGameMode.h"
#include "Wwise_SwitchesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWwise_SwitchesGameMode::AWwise_SwitchesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
