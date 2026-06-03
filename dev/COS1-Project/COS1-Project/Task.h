#pragma once
#include <string>
class Task
{
private:
	std::string title = "";
	bool isCompleted = false;
public:
	Task(std::string taskTitle);
	
	std::string GetTitle() const;
	bool IsCompleted() const;

	void CompleteTask();
};

/*
.h = what the class can do
.cpp = how the class does it
private = protected data
public = usable behavior
*/