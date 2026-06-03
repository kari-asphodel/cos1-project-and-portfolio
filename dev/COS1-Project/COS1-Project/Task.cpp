#include "Task.h"

Task::Task(std::string taskTitle)
{
	title = taskTitle;
	isCompletd = false;
}

std::string Title::GetTitle() const
{
	return title;
}

bool Task::IsCompleted() const
{
	return isCompletd;
}

void Task::CompleteTask()
{
	isCompletd = true;
}