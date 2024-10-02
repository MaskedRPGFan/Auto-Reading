#pragma once

#include "AutoReading.hpp"
#include "Utility.hpp"

namespace papyrus
{
	inline unsigned int functions_counter = 0;

	/**
	 * \brief Returns version of the dll.
	 * \return                  - Version of the dll.
	 */
	static std::string Version(RE::StaticFunctionTag*)
	{
		const auto plugin{ SKSE::PluginDeclaration::GetSingleton() };
		return plugin->GetVersion().string("."sv);
	}

	/**
	 * \brief Returns debug mode state.
	 * \return                  - Debug mode state.
	 */
	static bool DebugMode(RE::StaticFunctionTag*)
	{
		return Settings::debug_mode;
	}

	/**
	 * \brief Sets debug mode state.
	 * \param mode              - New debug mode state.
	 */
	static void SetDebugMode(RE::StaticFunctionTag*, const bool mode)
	{
		Settings::debug_mode = mode;
		Settings::SaveSettings();
	}

	static void LoadSettings(RE::StaticFunctionTag*)
	{
		Settings::LoadSettings();
	}

	static void AutoReading(RE::StaticFunctionTag*)
	{
		auto_reading::Read();
	}

	static int GetNormalBooks(RE::StaticFunctionTag*)
	{
		return static_cast<int>(Settings::normal_books_counter);
	}

	static int GetSkillBooks(RE::StaticFunctionTag*)
	{
		return static_cast<int>(Settings::skill_books_counter);
	}

	static int GetSpellBooks(RE::StaticFunctionTag*)
	{
		return static_cast<int>(Settings::spell_books_counter);
	}

	static void SetSpell(RE::StaticFunctionTag*)
	{
		Settings::LoadSettings();
		utility::SetSpell();
	}

	/**
	 * \brief Register functions for Papyrus scripts.
	 * \param aVirtualMachine   - Papyrus virtual machine.
	 * \return                  - True, if everything went fine.
	 */
	inline bool RegisterFunctions(RE::BSScript::IVirtualMachine* aVirtualMachine) noexcept
	{
		const auto plugin{ SKSE::PluginDeclaration::GetSingleton() };
		const auto name{ plugin->GetName() };

		aVirtualMachine->RegisterFunction("Version", name, Version);
		functions_counter++;
		aVirtualMachine->RegisterFunction("DebugMode", name, DebugMode);
		functions_counter++;
		aVirtualMachine->RegisterFunction("SetDebugMode", name, SetDebugMode);
		functions_counter++;
		aVirtualMachine->RegisterFunction("LoadSettings", name, LoadSettings);
		functions_counter++;
		aVirtualMachine->RegisterFunction("AutoReading", name, AutoReading);
		functions_counter++;
		aVirtualMachine->RegisterFunction("GetNormalBooks", name, GetNormalBooks);
		functions_counter++;
		aVirtualMachine->RegisterFunction("GetSkillBooks", name, GetSkillBooks);
		functions_counter++;
		aVirtualMachine->RegisterFunction("GetSpellBooks", name, GetSpellBooks);
		functions_counter++;
		aVirtualMachine->RegisterFunction("SetSpell", name, SetSpell);

		logger::info("Registered {} Papyrus functions.", functions_counter);
		return true;
	}

	inline void Register() noexcept
	{
		SKSE::GetPapyrusInterface()->Register(RegisterFunctions);
	}
}
