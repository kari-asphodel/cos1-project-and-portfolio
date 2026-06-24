#pragma once
#include <string>
class Task
{
private:
	std::string title = "";
	std::string priority = "";
	std::string category = "";
	bool isCompleted = false;
public:
	Task();
	Task(std::string taskTitle, std::string taskPriority, std::string taskCategory, bool isCompleted = false);
	
	std::string GetTitle() const;
	std::string GetPriority() const;
	std::string GetCategory() const;
	bool IsCompleted() const;

	int GetPriorityScore() const;

	void CompleteTask();

	std::string ToTextLine() const; 
};

/*
.h = what the class can do
.cpp = how the class does it
private = protected data
public = usable behavior
*/