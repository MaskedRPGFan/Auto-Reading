#pragma once
#include "Settings/Settings.hpp"
#include "Utility.hpp"

namespace auto_reading
{
	inline bool IsBook(const RE::TESBoundObject& object)
	{
		return object.IsBook();
	}

	inline void Read() noexcept
	{
		const auto player_ref = RE::PlayerCharacter::GetSingleton();
		auto books = player_ref->GetInventory(IsBook);

		std::set<RE::TESBoundObject*> read_books;
		std::set<RE::TESBoundObject*> books_to_eat;

		for(auto& [object, snd] : books)
		{
			const auto book = object->As<RE::TESObjectBOOK>();

			if(!book)
				continue;

			if(!book->IsRead() && !book->IsNoteScroll())
			{
				const auto name = book->GetName();
				if(Settings::read_normal_books && !book->TeachesSkill() && !book->TeachesSpell())
				{
					if(Settings::notifications)
						RE::DebugNotification(std::format("Reading normal book: {}", name).c_str());
					logger::debug("Reading book {}", name);
					book->Read(player_ref);
					Settings::normal_books_counter++;
				}
				if(book->TeachesSkill() && Settings::read_skill_books)
				{
					if(Settings::notifications)
						RE::DebugNotification(std::format("Reading skill book: {}", name).c_str());
					logger::debug("Reading skill book {}", name);
					book->Read(player_ref);
					Settings::skill_books_counter++;
				}
				if(Settings::read_spell_books && book->TeachesSpell() && !player_ref->HasSpell(book->GetSpell()))
				{
					if(Settings::notifications)
						RE::DebugNotification(std::format("Reading spell book: {}", name).c_str());
					logger::debug("Reading spell book {}", name);
					book->Read(player_ref);
					Settings::spell_books_counter++;
					if(Settings::eat_spell_book)
					{
						books_to_eat.insert(book);
						logger::debug("Eating spell book {}", name);
						if(Settings::notifications)
							RE::DebugNotification(std::format("Eating spell book: {}", name).c_str());
					}
				}
			}
		}

		utility::UpdateItemList();

		for(auto& book : books_to_eat)
			player_ref->RemoveItem(book, 1, RE::ITEM_REMOVE_REASON::kRemove, nullptr, nullptr);

		utility::UpdateItemList();

		Settings::SaveSettings(true);
	}
};
