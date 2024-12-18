// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GasDungeon/GasDungeon.h"
#include "CharacterGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASDUNGEON_API UCharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UCharacterGameplayAbility();
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Ability")
	GasDungeonAbilityID AbilityInputID = GasDungeonAbilityID::None;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Ability")
	GasDungeonAbilityID AbilityID = GasDungeonAbilityID::None;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "Ability")
	bool ActiveAbilityOnGranted = false;

	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
