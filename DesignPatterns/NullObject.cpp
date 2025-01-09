#include "NullObject.h"
#include <iostream>

using namespace std;

void ConsoleLogger::log(const string& message)
{
	cout << message << "\n";
}

void FileLogger::log(const string& message)
{
	cout << filePath << ": " << message << "\n";
}

void ApiLogger::log(const string& message)
{
	cout << url << ": " << message << "\n";
}

SomeTask::~SomeTask()
{
	delete logger;
}

void SomeTask::execute()
{
		logger->log("Did some stuff");
		logger->log("Did some other stuff");
		logger->log("Task complete.");
}
