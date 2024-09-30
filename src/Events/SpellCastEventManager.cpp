#include "SpellCastEventManager.hpp"
#include "AutoReading.hpp"

namespace event
{
	RE::BSEventNotifyControl SpellCastEventManager::ProcessEvent(const RE::TESSpellCastEvent* event, RE::BSTEventSource<RE::TESSpellCastEvent>*)
	{
		if(!event)
		{
			logger::trace("TESSpellCastEvent is nullptr");
			return RE::BSEventNotifyControl::kContinue;
		}

		if(!RE::Main::GetSingleton()->gameActive)
		{
			logger::trace("Game is not active.");
			return RE::BSEventNotifyControl::kContinue;
		}

		const auto caster = event->object;
		if(!caster || !caster->IsPlayerRef())
		{
			logger::trace("Caster is nullptr or not player");
			return RE::BSEventNotifyControl::kContinue;
		}

		const auto spell = RE::TESForm::LookupByID<RE::SpellItem>(event->spell);

		if(!spell)
			return RE::BSEventNotifyControl::kContinue;

		if(spell == Settings::GetSingleton()->spell)
			auto_reading::Read();

		return RE::BSEventNotifyControl::kContinue;
	}
}
