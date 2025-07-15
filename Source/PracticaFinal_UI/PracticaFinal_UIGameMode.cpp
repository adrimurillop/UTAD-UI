// Copyright Epic Games, Inc. All Rights Reserved.

#include "PracticaFinal_UIGameMode.h"
#include "PracticaFinal_UICharacter.h"
#include "UObject/ConstructorHelpers.h"

APracticaFinal_UIGameMode::APracticaFinal_UIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
