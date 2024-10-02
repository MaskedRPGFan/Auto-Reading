#pragma once

namespace event
{
	class KeyEventManager final : public RE::BSTEventSink<RE::InputEvent*>
	{
		public:
			KeyEventManager() noexcept = default;
			~KeyEventManager() noexcept override = default;

			KeyEventManager(const KeyEventManager&) = delete;
			KeyEventManager(KeyEventManager&&) = delete;
			KeyEventManager& operator=(const KeyEventManager&) = delete;
			KeyEventManager& operator=(KeyEventManager&&) = delete;

			[[nodiscard]] static auto GetSingleton() noexcept
			{
				static KeyEventManager singleton;
				return std::addressof(singleton);
			}

			static void Register() noexcept
			{
				RE::BSInputDeviceManager::GetSingleton()->AddEventSink<RE::InputEvent*>(GetSingleton());
			}

			RE::BSEventNotifyControl ProcessEvent(RE::InputEvent* const* event_ptr, RE::BSTEventSource<RE::InputEvent*>*) override;
	};
}
