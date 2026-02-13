
#include "TwitchComponent.h"
#include "TwitchSDK.h"
// Sets default values for this component's properties
UTwitchComponent::UTwitchComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTwitchComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get the Twitch SDK Core module
	auto core = FModuleManager::GetModuleChecked<FTwitchSDKModule>("TwitchSDK").Core;

}


// Called every frame
void UTwitchComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


