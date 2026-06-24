#include "Task.h"
Task::Task() {
	title = "";
	priority = "Low";
	category = "General";
	isCompleted = false;
}
Task::Task(std::string taskTitle, std::string taskPriority, std::string taskCategory, bool isCompleted)
{
	title = taskTitle;
	priority = taskPriority;
	category = taskCategory;
	isCompleted = false;
}

std::string Task::GetTitle() const
{
	return title;
}
std::string Task::GetPriority() const
{
	return priority;
}
std::string Task::GetCategory() const
{
	return category;
}

bool Task::IsCompleted() const
{
	return isCompleted;
}

void Task::CompleteTask()
{
	isCompleted = true;
}

int Task::GetPriorityScore() const
{
	if (priority == "High" || priority == "HIGH" || priority == "high")
	{
		return 3;
	}
	else if (priority == "Medium" || priority == "MEDIUM" || priority == "medium")
	{
		return 2;
	}
	else if (priority == "Low" || priority == "LOW" || priority == "low")
	{
		return 1;
	}
	return 0;
}

std::string Task::ToTextLine() const
{
	std::string completedText = isCompleted ? "1" : "0";
	return title + "|" + priority + "|" + category + "|" + completedText;
}