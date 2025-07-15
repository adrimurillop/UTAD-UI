// Fill out your copyright notice in the Description page of Project Settings.


#include "WSkill.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "PracticaFinal_UICharacter.h"
#include "Components/TextBlock.h"

void UWSkill::NativeConstruct()
{
	Super::NativeConstruct();
	Character = Cast<APracticaFinal_UICharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (!Character)
	{
		return;
	}
	
	Button->OnPressed.AddDynamic(this, &UWSkill::OnButtonPressed);
	Button->OnReleased.AddDynamic(this, &UWSkill::OnButtonReleased);

	if (bSkillUnlocked)
	{
		FButtonStyle NewButtonStyle = Button->GetStyle();

		NewButtonStyle.Normal.TintColor = FSlateColor(FLinearColor::Green);
		NewButtonStyle.Hovered.TintColor = FSlateColor(FLinearColor::Green);
	
		Button->SetStyle(NewButtonStyle);
		Button->SetIsEnabled(false);
	}
	
	CostText->SetText(FText::FromString(FString::FromInt(Cost)));
}

void UWSkill::UnlockAbility()
{
	switch (SkillType)
	{
	case ESkillType::Damage:
		break;
	case ESkillType::Health:
		break;
	case ESkillType::Speed:
		break;
	default:
		break;
	}
	bSkillUnlocked = true;
}

void UWSkill::UnlockSkill()
{
	Character->SetSkillPoints(Character->GetSkillPoints() - Cost);
	
	FButtonStyle NewButtonStyle = Button->GetStyle();

	NewButtonStyle.Normal.TintColor = FSlateColor(FLinearColor::Green);
	NewButtonStyle.Hovered.TintColor = FSlateColor(FLinearColor::Green);
	
	Button->SetStyle(NewButtonStyle);
	Button->SetIsEnabled(false);
}

void UWSkill::OnHoldComplete()
{
	UnlockAbility();
	UnlockSkill();
}

void UWSkill::OnButtonPressed()
{
	if (bSkillUnlocked)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Skill already unlocked");
		return;
	}
	if (Character->GetSkillPoints() < Cost)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "You don't have enough points to unlock this skill");
		return;
	}

	bool CanUnlock = PreviousSkills.Num() == 0;
	for (UWSkill* Skill : PreviousSkills)
	{
		if (IsValid(Skill) && Skill->IsSkillUnlocked())
		{
			CanUnlock = true;
		}
		else
		{
			CanUnlock = false;
			break;
		}
	}

	if (CanUnlock)
	{
		bIsHolding = true;
		GetWorld()->GetTimerManager().SetTimer(HoldTimer, this, &UWSkill::OnHoldComplete, 1.0f, false);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Previous skill not unlocked ");
	}
}

void UWSkill::OnButtonReleased()
{
	if (bIsHolding)
	{
		GetWorld()->GetTimerManager().ClearTimer(HoldTimer);
		bIsHolding = false;
	}
}
