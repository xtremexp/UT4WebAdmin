#include "UT4WebAdmin.h"

#include "Core.h"
#include "Engine.h"
#include "ModuleManager.h"
#include "ModuleInterface.h"

class FUT4WebAdminPlugin : public IModuleInterface
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	AUT4WebAdmin* _WebAdmin;
};

IMPLEMENT_MODULE(FUT4WebAdminPlugin, UT4WebAdmin)

void FUT4WebAdminPlugin::StartupModule()
{
	_WebAdmin = NewObject<AUT4WebAdmin>();
	_WebAdmin->Start();
}


void FUT4WebAdminPlugin::ShutdownModule()
{
	if (_WebAdmin) {
		_WebAdmin->Stop();
	}
}
