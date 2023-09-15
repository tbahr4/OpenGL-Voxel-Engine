// 
// Logger.h
//
// Defines a log function to handle console logging
//
#pragma once
#include <iostream>
#include <string>
using namespace std;


class Logger {
public:
	Logger() = delete;

	enum LogLevel {
		DEBUG = 0,
		WARNING = 1,
		FATAL = 2
	};
	#define LOG_LEVEL DEBUG

	static void log(LogLevel logLevel, string message);		// Logs a message if within the defined LOG_LEVEL
	static LogLevel getLogLevel();		// Returns the defined log level

private:
	static const string logNames[];
};


