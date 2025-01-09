#pragma once
#include <string>

class Logger
{
public:
	virtual ~Logger() {};
	virtual void log(const std::string& message) = 0;
};

class ConsoleLogger : public Logger
{
public:
	void log(const std::string& message) override;
};

class FileLogger : public Logger
{
	std::string filePath;
public:
	FileLogger(const std::string& filePath) : filePath(filePath) {};
	void log(const std::string& message) override;
};

class ApiLogger : public Logger
{
	std::string url;
public:
	ApiLogger(const std::string& url) : url(url) {};
	void log(const std::string& message) override;
};

class NullLogger : public Logger {
public:
	void log(const std::string& message) override {};
};

class SomeTask {
	Logger* logger = nullptr;
public:
	SomeTask() { logger = new NullLogger(); };
	SomeTask(Logger* logger) : logger(logger) {};
	~SomeTask();
	void execute();
};