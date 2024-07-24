#include "Alchemist/Utilities/Console.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

using std::stringstream;

void Console::Log(const string& message)
{
	PrintMessage(message, ELogLevel::INFO);
}

void Console::LogWarning(const string& message)
{
	PrintMessage(message, ELogLevel::WARNING);
}

void Console::LogError(const string& message)
{
	PrintMessage(message, ELogLevel::ERROR);
}

void Console::LogException(const exception* exception)
{
	PrintMessage(exception->what(), ELogLevel::EXCEPTION);
}

void Console::PrintMessage(const string& message, const ELogLevel level)
{
	std::cout << MakePrefix(level) << message;

	ResetColor();
}

string Console::MakePrefix(const ELogLevel level)
{
	stringstream stream;

	stream << GetMessageColor(level);
	stream << "[";

	stream << GetTimeString();
	stream << "] [";
	stream << GetLevelString(level);
	stream << "] ";

	return stream.str();
}

string Console::GetMessageColor(const ELogLevel level)
{
	switch (level)
	{
	case ELogLevel::INFO:
		return "\x1B[37m";
	case ELogLevel::WARNING:
		return "\x1B[33m";
	case ELogLevel::ERROR:
		return "\x1B[31m";
	case ELogLevel::EXCEPTION:
		return "\x1B[35m";
	default:   // NOLINT(clang-diagnostic-covered-switch-default)
		return "\x1B[37m";
	}
}

string Console::GetTimeString()
{
	const time_t t = std::time(nullptr);
	tm buf;

	(void)localtime_s(&buf, &t);

	stringstream stream;

	stream << std::put_time(&buf, "%H:%M:%S");

	return stream.str();
}

string Console::GetLevelString(const ELogLevel level)
{
	switch (level)
	{
	case ELogLevel::INFO:
		return "Inf";
	case ELogLevel::WARNING:
		return "War";
	case ELogLevel::ERROR:
		return "Err";
	case ELogLevel::EXCEPTION:
		return "Exc";
	default:   // NOLINT(clang-diagnostic-covered-switch-default)
		return "Non";
	}
}

void Console::ResetColor()
{
	std::cout << "\x1B[37m\n";
}
