
#include "TwitchComponent.h"
#include "TwitchSDK.h"
#include "Engine.h"
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

	auto core = FModuleManager::LoadModuleChecked<FTwitchSDKModule>("TwitchSDK").Core;	
	core->GetAuthenticationInfo(
		TwitchSDK::BuildOAuthScopes({ FTwitchSDKOAuthScope::ChannelManageRedemptions, FTwitchSDKOAuthScope::ChannelReadHype_Train }),
		[](const TwitchSDK::AuthenticationInfo& info) {
			if (info.UserCode.size() == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("The user is already authenticated"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("The user should authenticate at %s with code %s"), info.Uri.data(), info.UserCode.data());
			}
		},
		[](const std::exception& e) {
			UE_LOG(LogTemp, Warning, TEXT("GetAuthenticationInfo failed: %s"), UTF8_TO_TCHAR(e.what()));
		}
	);


	auto stream = core->SubscribeToCustomRewardEvents();
	stream.WaitForEvent([](const TwitchSDK::CustomRewardEvent& e)
	{
		
		
	});

}


// Called every frame
void UTwitchComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TwitchSDK::CustomRewardEvent UTwitchComponent::handleCustomRewardEvent(
	const TwitchSDK::CustomRewardEvent& e)
{
	return e;
}


//hComponent::handleCustomRewardEvent(const TwitchSDK::CustomRewardEvent& e)
//{
//	auto UserName = TwitchSDK::ToFString(e.RedeemerName);
//	auto RewardName = TwitchSDK::ToFString(e.CustomRewardTitle);
//	auto message = FString::Printf(TEXT("%s just purchased %s!"), *UserName, *RewardName);
//
//	//print message to screen or do something interesting
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, message);
//	
//	 
//}


