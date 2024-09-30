#pragma once

class Settings
{
	public:
		constexpr Settings(const Settings&) = delete;
		constexpr Settings(Settings&&) = delete;
		constexpr auto operator=(const Settings&) = delete;
		constexpr auto operator=(Settings&&) = delete;

		[[nodiscard]] static Settings* GetSingleton() noexcept
		{
			static Settings singleton;
			return std::addressof(singleton);
		}
		static void LoadSettings() noexcept;
		static void SaveSettings(bool stats_only = false) noexcept;
		inline static bool read_normal_books = true;
		inline static bool read_skill_books = true;
		inline static bool read_spell_books = true;

		inline static bool eat_spell_book = true;

		inline static bool has_spell = true;

		inline static bool notifications = true;

		inline static int hotkey = -1;

		inline static bool debug_mode = true;

		inline static unsigned int normal_books_counter = 0;
		inline static unsigned int skill_books_counter = 0;
		inline static unsigned int spell_books_counter = 0;

		RE::TESForm* spell = nullptr;

	private:
		constexpr Settings() noexcept = default;
		constexpr ~Settings() noexcept = default;

		static void LoadSettingsFromFile(const char* ini_path);
		static constexpr auto global_ini = R"(.\Data\MCM\Config\Auto Reading\settings.ini)";
		static constexpr auto user_ini = R"(.\Data\MCM\Settings\Auto Reading.ini)";
};
