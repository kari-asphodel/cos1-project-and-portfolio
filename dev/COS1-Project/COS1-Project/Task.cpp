#include "Task.h"

Task::Task(std::string taskTitle)
{
	title = taskTitle;
	isCompleted = false;
}

std::string Title::GetTitle() const
{
	return title;
}

bool Task::IsCompleted() const
{
	return isCompleted;
}

void Task::CompleteTask()
{
	isCompleted = true;
}