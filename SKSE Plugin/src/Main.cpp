#include "Events/Events.hpp"
#include "LogInfo.hpp"
#include "Papyrus.hpp"

SKSEPluginLoad(const SKSE::LoadInterface* skse)
{
	InitializeLog();

	const auto plugin{ SKSE::PluginDeclaration::GetSingleton() };
	const auto name{ plugin->GetName() };
	const auto version{ plugin->GetVersion() };

	logger::info("{} v{}", name, version);
	logger::info("Runtime: {}", GetRuntimeString());

	Settings::LoadSettings();

	Init(skse);
	SKSE::GetMessagingInterface()->RegisterListener(event::OnEvent);
	papyrus::Register();

	return true;
}
