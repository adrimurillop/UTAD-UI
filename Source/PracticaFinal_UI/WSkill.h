// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WSkill.generated.h"

class UButton;
class APracticaFinal_UICharacter;
class UTextBlock;


UENUM(BlueprintType)
enum class ESkillType : uint8
{
	Speed UMETA(DisplayName = "Speed"),
	Health UMETA(DisplayName = "Health"),
	Damage UMETA(DisplayName = "Damage"),
};

UCLASS()
class PRACTICAFINAL_UI_API UWSkill : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	APracticaFinal_UICharacter* Character;

	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	UButton* Button;
	
	UPROPERTY(VisibleAnywhere, Category = "UI", meta = (BindWidget))
	UTextBlock* CostText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills | Cost")
	int Cost;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills | SkillType")
	ESkillType SkillType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	TArray<UWSkill*> PreviousSkills;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	bool bSkillUnlocked = false;
	
	UFUNCTION()
	void UnlockAbility();

	UFUNCTION()
	void UnlockSkill();
	
	FTimerHandle HoldTimer;
	bool bIsHolding = false;

	UFUNCTION()
	void OnHoldComplete();

	UFUNCTION()
	void OnButtonPressed();

	UFUNCTION()
	void OnButtonReleased();

public:
	FORCEINLINE bool IsSkillUnlocked() const { return bSkillUnlocked; }
	
};
