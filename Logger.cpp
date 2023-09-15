// 
// Logger.h
//
// Defines a log function to handle console logging
//
#include "Logger.h"


const string Logger::logNames[] = {
	"DEBUG",
	"WARNING",
	"FATAL"
};


// log
// Logs a message if within the defined LOG_LEVEL
//
void Logger::log(LogLevel logLevel, string message) {
	if (logLevel < LOG_LEVEL || logLevel > FATAL) return;
	cout << "[" << logNames[logLevel] << "] " << message << endl;

	if (logLevel == FATAL) exit(1);
}

// getLogLevel
// Returns the defined log level
//
Logger::LogLevel Logger::getLogLevel() {
	return LOG_LEVEL;
}