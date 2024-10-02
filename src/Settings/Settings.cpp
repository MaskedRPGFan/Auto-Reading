#include "Settings.hpp"

void Settings::LoadSettings() noexcept
{
	LoadSettingsFromFile(global_ini);

	if(std::filesystem::exists(user_ini))
		LoadSettingsFromFile(user_ini);

	if(debug_mode)
	{
		spdlog::set_level(spdlog::level::debug);
		logger::debug("Debug Mode enabled.");
	}

	logger::debug("Loading settings...");

	logger::debug("Read books that does not have skill or spell: {}.", read_normal_books);
	logger::debug("Read books that improves skills: {}.", read_skill_books);
	logger::debug("Read books that teaches a spell: {}.", read_spell_books);
	logger::debug("Eat spell books: {}.", eat_spell_book);
	logger::debug("Add spell: {}.", add_spell);
	logger::debug("Show notifications when a spell book or skill is read: {}.", notifications);
	logger::debug("Hotkey: {}.", hotkey);
	logger::debug("Hotkey restricted: {}.", hotkey_restricted);
	logger::debug("Normal books: {}.", normal_books_counter);
	logger::debug("Skill books: {}.", skill_books_counter);
	logger::debug("Spell books: {}.", spell_books_counter);

	logger::debug("Settings loaded!");
}

void Settings::SaveSettings(bool stats_only) noexcept
{
	logger::debug("Saving settings...");

	CSimpleIniA ini;
	ini.SetUnicode();

	auto rc = ini.LoadFile(user_ini);
	if(rc < 0)
	{
		logger::error("Failed to load settings!");
		return;
	}

	if(!stats_only)
	{
		ini.SetLongValue("General", "bNormalBook", read_normal_books);
		ini.SetLongValue("General", "bSkillBook", read_skill_books);
		ini.SetLongValue("General", "bSpellBook", read_spell_books);
		ini.SetLongValue("General", "bEatSpellBook", eat_spell_book);
		ini.SetLongValue("General", "bAddSpell", add_spell);
		ini.SetLongValue("General", "bNotifications", notifications);

		ini.SetLongValue("General", "iHotkey", hotkey);
		ini.SetLongValue("General", "bHotkeyRestricted", hotkey_restricted);

		ini.SetLongValue("General", "bDebugMode", debug_mode);
	}

	ini.SetLongValue("Stats", "iNormalBooksCounter", normal_books_counter);
	ini.SetLongValue("Stats", "iSkillBooksCounter", skill_books_counter);
	ini.SetLongValue("Stats", "iSpellBooksCounter", spell_books_counter);

	const auto result = ini.SaveFile(user_ini);

	if(result == SI_OK)
		logger::debug("Settings saved!");
	else
		logger::error("Failed to save settings!");
}

void Settings::LoadSettingsFromFile(const char* ini_path)
{
	CSimpleIniA ini;

	ini.SetUnicode();
	auto rc = ini.LoadFile(ini_path);
	if(rc < 0)
	{
		logger::error("Failed to load settings!");
		return;
	}

	read_normal_books = ini.GetLongValue("General", "bNormalBook", read_normal_books);
	read_skill_books = ini.GetLongValue("General", "bSkillBook", read_skill_books);
	read_spell_books = ini.GetLongValue("General", "bSpellBook", read_spell_books);
	eat_spell_book = ini.GetLongValue("General", "bEatSpellBook", eat_spell_book);
	add_spell = ini.GetLongValue("General", "bHasSpell", add_spell);
	notifications = ini.GetLongValue("General", "bNotifications", notifications);

	hotkey = ini.GetLongValue("General", "iHotkey", hotkey);
	hotkey_restricted = ini.GetLongValue("General", "bHotkeyRestricted", hotkey_restricted);

	debug_mode = ini.GetLongValue("Maintenance", "bDebugMode", debug_mode);

	normal_books_counter = ini.GetLongValue("Stats", "iNormalBooksCounter", normal_books_counter);
	skill_books_counter = ini.GetLongValue("Stats", "iSkillBooksCounter", skill_books_counter);
	spell_books_counter = ini.GetLongValue("Stats", "iSpellBooksCounter", spell_books_counter);
}
