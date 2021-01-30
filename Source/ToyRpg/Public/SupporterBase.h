// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "SupporterBase.generated.h"

/**
 * 
 */
UCLASS()
class TOYRPG_API ASupporterBase : public ACharacterBase
{
	GENERATED_BODY()

public:
	ASupporterBase();

protected:
	virtual void BeginPlay() override;

	/** implement skill in blueprint **/
	UFUNCTION(BlueprintImplementableEvent, Category = MainMenu)
	void Activate_Skill_A();

	UFUNCTION(BlueprintImplementableEvent, Category = MainMenu)
	void Activate_Skill_B();

	UFUNCTION(BlueprintImplementableEvent, Category = MainMenu)
	void Activate_Skill_C();

	UFUNCTION(BlueprintImplementableEvent, Category = MainMenu)
	void Activate_Skill_D();
};
