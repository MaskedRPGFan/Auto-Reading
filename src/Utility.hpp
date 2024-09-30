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
}
