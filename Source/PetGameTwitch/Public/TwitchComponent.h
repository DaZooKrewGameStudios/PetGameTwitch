

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TwitchSDK.h"
#include "TwitchComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PETGAMETWITCH_API UTwitchComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTwitchComponent();

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
