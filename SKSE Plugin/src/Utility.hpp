#pragma once

namespace utility
{
	inline void UpdateItemList()
	{
		if(const auto ui = RE::UI::GetSingleton(); ui && ui->IsMenuOpen("InventoryMenu"))
		{
			ui->GetMenu<RE::InventoryMenu>()->GetRuntimeData().itemList->Update();
		}
	}

	/**
	 * \brief Returns a poniter to Form based on mod name and record FromID.
	 * \param pluginName    - Name of the mod with extension.
	 * \param local_form_id - Local FormID of the record.
	 * \return              - Form (TESForm) pointer or nullptr if not found.
	 */
	inline RE::TESForm* GetTesForm(const std::string& pluginName, const std::uint32_t local_form_id)
	{
		static const auto data_handler = RE::TESDataHandler::GetSingleton();
		return data_handler ? data_handler->LookupForm(local_form_id, pluginName) : nullptr;
	}

	inline void SetSpell()
	{
		if(!RE::Main::GetSingleton()->gameActive)
		{
			logger::error("Game is not active.");
			return;
		}

		if(!Settings::GetSingleton()->spell)
		{
			logger::warn("Spell is nullptr.");
			return;
		}

		const auto player_ref = RE::PlayerCharacter::GetSingleton();
		const auto spell = Settings::GetSingleton()->spell->As<RE::SpellItem>();

		if(spell)
		{
			logger::debug("Setting spell: {}.", spell->GetFullName());
			if(Settings::add_spell && !player_ref->HasSpell(spell))
			{
				player_ref->AddSpell(spell);
				logger::debug("Added spell: {}.", spell->GetFullName());
			}
			else if(!Settings::add_spell && player_ref->HasSpell(spell))
			{
				player_ref->RemoveSpell(spell);
				logger::debug("Removed spell: {}.", spell->GetFullName());
			}
		}
		else
			logger::error("Spell is nullptr.");
	}
}
