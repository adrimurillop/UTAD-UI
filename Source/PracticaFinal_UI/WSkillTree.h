// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WSkillTree.generated.h"

class UCanvasPanel;
class UImage;
class UTextBlock;
class UWSkill;

UCLASS()
class PRACTICAFINAL_UI_API UWSkillTree : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	UCanvasPanel* SkillTreeCanvas;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Skill Tree")
	TSubclassOf<UWSkill> SkillNodeWidgetClass;

	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	UImage* BackGround;
	
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	UTextBlock* Title;
	
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	UTextBlock* SkillPoints;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode1;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode3;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode4;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode5;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode6;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode7;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode8;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode9;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode10;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode11;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode12;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode13;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode14;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode16;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode17;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill Tree", meta = (BindWidget))
	UWSkill* SkillNode18;


	// Función para consumir el input
	FReply NativeOnMouseButtonDown(const FGeometry& Geometry, const FPointerEvent& MouseEvent) override;

	void UpdateSkillPoints(int NewSkillPoints);

};
