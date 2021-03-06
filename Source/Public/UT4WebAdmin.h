#pragma once

#include <iostream>
#include "Core.h"
#include "UnrealTournament.h"
#include "UTGameMode.h"
#include "UTGameSession.h"
#include "UTMutator.h"
#include "UT4WebAdminHttpServer.h"
#include "UT4WebAdminSQLite.h"

#include "UT4WebAdmin.generated.h"

#define UT4WA_PLUGIN_FOLDER "UT4WebAdmin"
#define UT4WA_VERSION "0.0.1"

// Log messages
DEFINE_LOG_CATEGORY_STATIC(UT4WebAdmin, Log, All);

UCLASS(Config=UT4WebAdmin, Blueprintable, Meta = (ChildCanTick))
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

	/* Override for ticking/poll http server */
	virtual void Tick(float DeltaTime) override;

	// Reference to http server
	UUT4WebAdminHttpServer* _HttpServer;

	// Reference to SQLite server
	UUT4WebAdminSQLite* _SQLiteServer;

	/* For chat history purpose */
	bool AllowTextMessage_Implementation(FString& Msg, bool bIsTeamMessage, AUTBasePlayerController* Sender) override;

	void PostPlayerInit_Implementation(AController* C) override;

	/* For log player exit info */
	void NotifyLogout_Implementation(AController* C) override;

	void ModifyLogin_Implementation(UPARAM(ref) FString& Portal, UPARAM(ref) FString& Options) override;

	/* Chat history for current session */
	TArray<FChatRow> ChatRows;

private:
	AUTGameMode* GameMode;
};