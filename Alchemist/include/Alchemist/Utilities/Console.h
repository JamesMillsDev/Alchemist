#pragma once

#include "Alchemist/Alchemist.h"

using std::exception;

enum class ELogLevel : byte
{
	INFO,
	WARNING,
	ERROR,
	EXCEPTION
};

class DLL Console
{
public:
	static void Log(const string& message);
	static void LogWarning(const string& message);
	static void LogError(const string& message);
	static void LogException(const exception* exception);

private:
	static void PrintMessage(const string& message, ELogLevel level);

	static string MakePrefix(ELogLevel level);
	static string GetMessageColor(ELogLevel level);
	static string GetTimeString();
	static string GetLevelString(ELogLevel level);

	static void ResetColor();

};