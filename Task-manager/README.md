# Task Manager CLI (C++)

A simple Command-Line Interface (CLI) Task Manager built using C++. This program allows users to manage tasks with options to add, list, mark as complete, and remove tasks. Tasks are stored in a file, and the data is persisted across program runs.

## Features

* **List Tasks**: Displays all tasks with their descriptions and status.
* **Add Task**: Add new tasks with titles and descriptions.
* **Mark Task as Completed**: Mark a task as completed.
* **Remove Task**: Remove a task from the list.
* **Data Persistence**: Tasks are saved in a text file (`tasks.txt`) and are loaded when the program restarts.

## Requirements

* **C++ Compiler**: A C++ compiler such as `g++` or `clang++`.
* **Standard C++ Library**: The program uses standard C++ libraries like `iostream`, `fstream`, and `vector`.

## How to Compile and Run

### 1. Clone the Repository

```bash
git clone https://github.com/Xyt564/cpp-projects.git
```

```bash
cd cpp-projects/Task-manager/
```

### 2. Compile the Program

Using `g++` (or your preferred C++ compiler), compile the program:

```bash
g++ main.cpp -o task
```

### 3. Run the Program

Execute the compiled binary to start the task manager:

```bash
./task
```

## Usage

Upon running the program, the user will be presented with the following menu:

```
==== Task Manager ====
1. List Tasks
2. Add Task
3. Mark Task as Completed
4. Remove Task
5. Exit
Choose an option:
```

### 1. List Tasks

Displays all tasks with their titles, descriptions, and current status (completed or not).

### 2. Add Task

Prompts the user to enter a title and description for a new task. The task will be saved as not completed.

### 3. Mark Task as Completed

Allows the user to mark a task as completed. The user is prompted to select a task by its number.

### 4. Remove Task

Allows the user to remove a task from the list. The user is prompted to select a task by its number.

### 5. Exit

Exits the program and saves all tasks to `tasks.txt`.

## File Storage

The tasks are stored in a text file called `tasks.txt` in the following format:

```
Title: Task 1
Description: This is a task description
Status: not completed
---
Title: Task 2
Description: This is another task description
Status: completed
---
```

The program will automatically load and save tasks to this file whenever it is run.

## Troubleshooting

* **Invalid input**: If you enter invalid input (e.g., a non-number when prompted for a task number), the program will ask you to enter a valid input.
* **Empty Task List**: If there are no tasks in the `tasks.txt` file, the program will inform you that there are no tasks to list.
* **auto creates txt file**: if theres no txt file dont worry just run the file and it auto creates a txt file for you

## License

This project is open source and available under the MIT License. See the [LICENSE](LICENSE) file for more information.

---
