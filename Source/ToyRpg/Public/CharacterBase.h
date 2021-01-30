// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TOYRPG_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnRight(float Value);

	/** Skill A ~ D (for key mapping) **/
	void Skill_A();
	void Skill_B();
	void Skill_C();
	void Skill_D();

	/** implement skill in sub class **/
	virtual void Activate_Skill_A() {};
	virtual void Activate_Skill_B() {};
	virtual void Activate_Skill_C() {};
	virtual void Activate_Skill_D() {};
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Variable for Agent State
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="State")
	float CharacterHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float MyTeamHP1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float MyTeamHP2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float MonsterHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float DistanceMeToMonster;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float DistanceMeToTeam1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float DistanceMeToTeam2;


};
