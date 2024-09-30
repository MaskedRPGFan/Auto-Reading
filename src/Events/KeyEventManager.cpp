#include "KeyEventManager.hpp"
#include "AutoReading.hpp"
#include "Utility.hpp"

namespace event
{
	RE::BSEventNotifyControl KeyEventManager::ProcessEvent(RE::InputEvent* const* event_ptr, RE::BSTEventSource<RE::InputEvent*>*)
	{
		if(!event_ptr || !*event_ptr || !RE::Main::GetSingleton()->gameActive)
		{
			return RE::BSEventNotifyControl::kContinue;
		}

		auto* event = *event_ptr;
		if(!event)
			return RE::BSEventNotifyControl::kContinue;

		if(event)
		{
			if(event->GetEventType() == RE::INPUT_EVENT_TYPE::kButton)
			{
				const auto* button_event = event->AsButtonEvent();
				const int key = static_cast<int>(button_event->GetIDCode());

				if(button_event->IsDown())
				{
					if(key > 0 && key == Settings::hotkey)
					{
						auto_reading::Read();
						utility::UpdateItemList();
					}
				}
			}
		}

		return RE::BSEventNotifyControl::kContinue;
	}
}
