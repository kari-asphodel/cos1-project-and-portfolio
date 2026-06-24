
**Project Overview**

The Crypt Keeper Productivity Program is a console-based task management application developed in C++. The program allows users to create tasks, assign priorities and categories, complete tasks, sort and filter active tasks, and save/load data using both text and binary files.

  

**Features Added This Week**

**Text Save and Load System**

Implemented a text-based save and load feature using ofstream and ifstream.

The system:

- Saves active tasks to a text file
- Saves completed tasks to a text file
- Stores task title, priority, category, and completion status
- Restores task data when the application is reopened

Example save format:

Record lecture|High|Teaching|0

Submit milestone|Medium|School|1

  

**Binary Save and Load System**

Implemented a binary save and load system using file streams opened with std::ios::binary.

The system:

- Stores task data as raw bytes
- Saves string lengths before string data
- Restores active and completed task lists
- Demonstrates an alternative to text-based serialization

  

**User Experience Improvements**

Improved overall usability by:

- Adding clearer success messages
- Adding file error messages
- Improving menu organization
- Improving task display formatting

  

**Refactoring Completed**

The following refactoring changes were made:

**DisplayTaskList()**

Created a reusable helper function to reduce duplicate code when displaying task lists.

Before:

- Active task display logic was duplicated
- Completed task display logic was duplicated

After:

- Both systems use a single helper function

Benefits:

- Less duplicated code
- Easier maintenance
- Easier future expansion

  

**Testing Performed**

**Text Save Testing**

|   |   |
|---|---|
|**Test**|**Result**|
|Save active tasks|Passed|
|Save completed tasks|Passed|
|Load active tasks|Passed|
|Load completed tasks|Passed|
|Missing file handling|Passed|

**Binary Save Testing**

|   |   |
|---|---|
|**Test**|**Result**|
|Save binary file|Passed|
|Load binary file|Passed|
|Restore task data|Passed|
|Restore completed tasks|Passed|
|Missing file handling|Passed|

**General Program Testing**

|   |   |
|---|---|
|**Test**|**Result**|
|Add task|Passed|
|Complete task|Passed|
|Sort tasks|Passed|
|Filter tasks|Passed|
|Input validation|Passed|
|Invalid menu options|Passed|

**Challenges Encountered**

**Challenge 1**

While implementing loading functionality, tasks duplicated when loading the same file multiple times.

Cause:

The vectors were not being cleared before loading.

Solution:

Added:

activeTasks.clear();

completedTasks.clear();

before loading task data.

  

**Challenge 2**

Binary file saving required additional planning because strings do not have a fixed size.

Solution:

Stored string lengths before writing string data to the file.

  

**Future Improvements**

If development continued, I would add:

- Search functionality
- Task due dates
- Task editing
- Save file selection
- Task statistics dashboard

  

**Reflection**

This week helped reinforce the importance of testing, refactoring, and documentation. While adding new features can be exciting, ensuring existing functionality remains stable is equally important. Implementing both text and binary save systems also provided experience working with file persistence and different approaches to storing data.