#pragma once

namespace utility
{
	inline void UpdateItemList()
	{
		const auto UI = RE::UI::GetSingleton();

		if(!UI)
			return;

		if(UI->IsMenuOpen("InventoryMenu"))
		{
			UI->GetMenu<RE::InventoryMenu>()->GetRuntimeData().itemList->Update();
			return;
		}

		if(UI->IsMenuOpen("ContainerMenu"))
		{
			UI->GetMenu<RE::ContainerMenu>()->GetRuntimeData().itemList->Update();
			return;
		}

		if(UI->IsMenuOpen("BarterMenu"))
		{
			UI->GetMenu<RE::BarterMenu>()->GetRuntimeData().itemList->Update();
			return;
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

		const auto player_ref = RE::PlayerCharacter::GetSingleton();
		const auto spell = Settings::GetSingleton()->spell->As<RE::SpellItem>();

		if(spell)
		{
			logger::debug("Setting spell: {}.", spell->GetFullName());
			if(Settings::has_spell && !player_ref->HasSpell(spell))
			{
				player_ref->AddSpell(spell);
				logger::debug("Added spell: {}.", spell->GetFullName());
			}
			else if(!Settings::has_spell && player_ref->HasSpell(spell))
			{
				player_ref->RemoveSpell(spell);
				logger::debug("Removed spell: {}.", spell->GetFullName());
			}
		}
		else
			logger::error("Spell is nullptr.");
	}
}
