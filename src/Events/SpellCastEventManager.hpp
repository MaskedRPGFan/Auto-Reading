#pragma once

namespace event
{
	class SpellCastEventManager final : public RE::BSTEventSink<RE::TESSpellCastEvent>
	{
		public:
			SpellCastEventManager() noexcept = default;
			~SpellCastEventManager() noexcept override = default;

			SpellCastEventManager(const SpellCastEventManager&) = delete;
			SpellCastEventManager(SpellCastEventManager&&) = delete;
			SpellCastEventManager& operator=(const SpellCastEventManager&) = delete;
			SpellCastEventManager& operator=(SpellCastEventManager&&) = delete;

			[[nodiscard]] static auto GetSingleton() noexcept
			{
				static SpellCastEventManager singleton;
				return std::addressof(singleton);
			}

			static void Register() noexcept
			{
				RE::ScriptEventSourceHolder::GetSingleton()->AddEventSink<RE::TESSpellCastEvent>(GetSingleton());
			}

			RE::BSEventNotifyControl ProcessEvent(const RE::TESSpellCastEvent* event, RE::BSTEventSource<RE::TESSpellCastEvent>*) override;
	};
}
