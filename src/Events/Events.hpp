#pragma once

#include "Constants.hpp"
#include "KeyEventManager.hpp"
#include "Settings.hpp"
#include "SpellCastEventManager.hpp"
#include "Utility.hpp"

namespace event
{
	/**
	 * \brief Sink to capture SKSE events.
	 * \param event - Submitted event.
	 */
	inline void OnEvent(SKSE::MessagingInterface::Message* event) noexcept
	{
		switch(event->type)
		{
			case SKSE::MessagingInterface::kDataLoaded:
				Settings::GetSingleton()->spell = utility::GetTesForm(constants::PluginName.data(), constants::SpellRawID);
				SpellCastEventManager::Register();
				break;
			case SKSE::MessagingInterface::kPostLoad:
				break;
			case SKSE::MessagingInterface::kPostLoadGame:
				Settings::GetSingleton()->LoadSettings();
				utility::SetSpell();
				break;
			case SKSE::MessagingInterface::kNewGame:
				Settings::GetSingleton()->LoadSettings();
				utility::SetSpell();
				break;
			case(SKSE::MessagingInterface::kInputLoaded):
				KeyEventManager::Register();
				break;
			case(SKSE::MessagingInterface::kPostPostLoad):
				break;
			default:;
		}
	}
}
