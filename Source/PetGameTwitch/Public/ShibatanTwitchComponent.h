// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TwitchSDK.h"
#include "ShibatanTwitchComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PETGAMETWITCH_API UShibatanShibatanTwitchComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShibatanShibatanTwitchComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TwitchSDK::CustomRewardEvent handleCustomRewardEvent(const TwitchSDK::CustomRewardEvent& e);
	
	UPROPERTY(EditAnywhere)
	bool bDebug = false;
	
	UPROPERTY(EditAnywhere)
	bool bEnableRewardRedemption = true;

	UPROPERTY(EditAnywhere)
	bool bEnableHypeTrainSubscription = true;

	UPROPERTY(EditAnywhere)
	bool bEnableRaidSubscription = true;

};