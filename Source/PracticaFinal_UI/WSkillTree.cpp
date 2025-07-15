// Fill out your copyright notice in the Description page of Project Settings.


#include "WSkillTree.h"

#include "PracticaFinal_UICharacter.h"
#include "WSkill.h"
#include "Components/TextBlock.h"

void UWSkillTree::NativeConstruct()
{
	Super::NativeConstruct();
	APracticaFinal_UICharacter::OnSkillPointsChanged.AddUObject(this, &UWSkillTree::UpdateSkillPoints);
}

FReply UWSkillTree::NativeOnMouseButtonDown(const FGeometry& Geometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}

void UWSkillTree::UpdateSkillPoints(int NewSkillPoints)
{
	SkillPoints->SetText(FText::FromString(FString::FromInt(NewSkillPoints)));
}
