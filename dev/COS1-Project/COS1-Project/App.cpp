#include "App.h"
#include <iostream>
#include <string>

App::App()
{
	isRunning = true;
}

void App::Run()
{
	std::cout << "Welcome to the Crytpe Keeper Productivity Program.\n";
	std::cout << "Let us organize the choas before it organizes us.\n";
	while (isRunning)
	{
		DisplayMenu();
		int choice = GetValidatedInputInRange(1, 8);
		HandleChoice(choice);
	}
	std::cout << "\nGoodbye. May your task list stay only midly cursed.\n";
}

void App::DisplayMenu() const
{
	std::cout << "\n========== CRYPT KEEPER ==========\n";
	std::cout << "1. Add Task\n";
	std::cout << "2. View Active Tasks\n";
	std::cout << "3. Complete Tasks\n";
	std::cout << "4. View Completed Tasks\n";
	std::cout << "5. View Progress Summary\n";
	std::cout << "6. Sort Active Tasks by Priority\n";
	std::cout << "7. Filter Active Tasks by Priority\n";
	std::cout << "8. Quit\n";
	std::cout << "Choose an option between 1 and 8: ";
}

int App::GetValidatedInputInRange(int min, int max)
{
	std::string input;
	int number;
	while (true)
	{
		std::getline(std::cin, input);
		try
		{
			number = std::stoi(input);
			if (number >= min && number <= max)
			{
				return number;
			}
			std::cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";
		}
		catch (...)
		{
			std::cout << "Invalid option. Please enter a number between " << min << " and " << max << ": ";
		}
	}
}

void App::HandleChoice(int choice)
{
	std::string title = "";
	std::string priority = "";
	std::string category = "";
	int taskNumber = 0;
	int filterChoice = 0;
	switch (choice)
	{
	case 1:
		std::cout << "\nEnter the task title: ";
		std::getline(std::cin, title);
		std::cout << "\nEnter the task priority: ";
		std::getline(std::cin, priority);
		std::cout << "\nEnter the task category: ";
		std::getline(std::cin, category);
		manager.AddTask(title, priority, category);
		break;
	case 2:
		manager.ViewActiveTasks();
		break;
	case 3:
		if (manager.GetActiveTaskCount() == 0)
		{
			std::cout << "\nThere are no active tasks to complete.\n";
			return;
		}
		manager.ViewActiveTasks();
			std::cout << "\nEnter the task number to complete: ";
			taskNumber = GetValidatedInputInRange(1, manager.GetActiveTaskCount());
		manager.CompleteTask(taskNumber - 1);
		break;
	case 4:
		manager.ViewCompletedTasks();
		break;
	case 5:
		manager.DisplaySummary();
		break;
	case 6:
		manager.SortActiveTasksByPriority();
		break;
	case 7:
		std::cout << "\nChoose priority to filter by:\n";
		std::cout << "1. High\n";
		std::cout << "2. Medium\n";
		std::cout << "3. Low\n";
		std::cout << "Choose an option between 1 and 3: ";
		filterChoice = GetValidatedInputInRange(1, 3);
		if (filterChoice == 1)
		{
			manager.ViewTasksByPriority("High");
		}
		else if (filterChoice == 2)
		{
			manager.ViewTasksByPriority("Medium");
		}
		else
		{
			manager.ViewTasksByPriority("Low");
		}
		break;
	case 8:
		isRunning = false;
		break;
	default:
		std::cout << "\nThat option does not exist in this crypt.\n";
		break;
	}

}

