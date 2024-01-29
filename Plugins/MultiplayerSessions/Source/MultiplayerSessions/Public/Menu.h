// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Menu.generated.h"

class UMultiplayerSessionsSubsystem;
class UButton;
/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FFA")));

protected:
	virtual bool Initialize() override;
	virtual void NativeDestruct() override;
	
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> HostButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> JoinButton;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();
	
	UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	int32 NumPublicConnections{4};
	FString MatchType{TEXT("FFA")};
};
