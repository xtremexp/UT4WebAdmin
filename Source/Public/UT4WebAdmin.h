#pragma once

#include <iostream>
#include "Core.h"
#include "UnrealTournament.h"
#include "UTGameMode.h"
#include "UTGameSession.h"
#include "UTMutator.h"
#include "UT4WebAdminHttpServer.h"

#include "UT4WebAdmin.generated.h"

// Log messages
DEFINE_LOG_CATEGORY_STATIC(UT4WebAdmin, Log, All);


UCLASS(Config=UT4WebAdmin)
class AUT4WebAdmin : public AUTMutator
{

	GENERATED_UCLASS_BODY()

	void Start();
	void Stop();

	// Main administrator username
	UPROPERTY(Config)
		FString HeadAdminUsername;

	// Main administrator password
	UPROPERTY(Config)
		FString HeadAdminPassword;

	/* If true player won't know which admin have kicked/banned/muted him*/
	UPROPERTY(Config)
		bool bAnonymousAdmin;

	// Reference to http server
	UUT4WebAdminHttpServer* _HttpServer;

private:
	AUTGameMode* GameMode;
};