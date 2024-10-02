#pragma once

void InitializeLog() noexcept;

static std::string_view GetRuntimeString()
{
	switch(REL::Module::GetRuntime())
	{
		case REL::Module::Runtime::AE:
			return "Anniversary Edition"sv;
		case REL::Module::Runtime::SE:
			return "Special Edition"sv;
		case REL::Module::Runtime::VR:
			return "VR"sv;
		default:;
	}
	return "Unknown"sv;
}

inline void InitializeLog() noexcept
{
	auto path{ SKSE::log::log_directory() };
	if(!path)
	{
		SKSE::stl::report_and_fail("Unable to lookup SKSE logs directory.");
	}
	*path /= SKSE::PluginDeclaration::GetSingleton()->GetName();
	*path += L".log";

	std::shared_ptr<spdlog::logger> log{};
	if(REX::W32::IsDebuggerPresent())
	{
		log = std::make_shared<spdlog::logger>("Global", std::make_shared<spdlog::sinks::msvc_sink_mt>());
	}
	else
	{
		log = spdlog::basic_logger_mt("Global", path->string(), true);
	}

	log->set_level(spdlog::level::info);
	log->flush_on(spdlog::level::trace);

	set_default_logger(std::move(log));

	spdlog::set_pattern("[%Y-%m-%d %H-%M-%S.%e] [%L] %v");
}
