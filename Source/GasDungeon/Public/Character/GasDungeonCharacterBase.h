// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Character/Abilities/CharacterGameplayAbility.h"
#include "GameFramework/Character.h"
#include "GasDungeon/GasDungeon.h"
#include "GasDungeonCharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDiedDelegate, AGasDungeonCharacterBase*, Character);

UCLASS()
class GASDUNGEON_API AGasDungeonCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGasDungeonCharacterBase(const FObjectInitializer& ObjectInitializer);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(BlueprintAssignable, Category= "GasDungeon|Character")
	FCharacterDiedDelegate OnCharacterDied;

	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character")
	virtual bool IsAlive() const;

	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character")
	virtual int32 GetAbilityLevel(GasDungeonAbilityID AbilityID) const;

	virtual void RemoveCharacterAbilities();

	virtual void Die();

	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character")
	virtual void FinishDying();

	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character|Attributes")
	float GetHealth() const;
	
	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character|Attributes")
	float GetMaxHealth() const;
	
	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character|Attributes")
	float GetMana() const;
	
	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character|Attributes")
	float GetMaxMana() const;

	UFUNCTION(BlueprintCallable, Category= "GasDungeon|Character|Attributes")
	float GetCharacterLevel() const;
	
protected:
	TWeakObjectPtr<class UCharacterAbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<class UCharacterAttributeSetBase> AttributeSetBase;

	FGameplayTag DeadTag;
	FGameplayTag EffectRemoveOnDeathTag;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "GasDungeon|Character")
	FText CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "GasDungeon|Animatin")
	UAnimMontage* DeathMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "GasDungeon|Abilities")
	TArray<TSubclassOf<class UCharacterGameplayAbility>> CharacterAbilities;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "GasDungeon|Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category= "GasDungeon|Abilities")
	TArray<TSubclassOf<class UGameplayEffect>> StartupEffects;

	virtual void AddCharacterAbilities();

	virtual void InitializeAttributes();

	virtual void AddStartupEffects();

	virtual void SetHealth(float Health);

	virtual void SetMana(float Mana);
	
};
