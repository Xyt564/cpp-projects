#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits> 

using namespace std;

struct Task {
    string title;
    string description;
    bool complete;
};

const string TASK_FILE = "tasks.txt";

void saveTasks(const vector<Task>& tasks) {
    ofstream file(TASK_FILE);
    for (const auto& t : tasks) {
        file << "Title: " << t.title << "\n";
        file << "Description: " << t.description << "\n";
        file << "Status: " << (t.complete ? "completed" : "not completed") << "\n";
        file << "---\n";
    }
}

vector<Task> loadTasks() {
    vector<Task> tasks;
    ifstream file(TASK_FILE);
    if (!file) return tasks;

    string line;
    Task task;
    while (getline(file, line)) {
        if (line.rfind("Title:", 0) == 0) {
            task.title = line.substr(7);
        } else if (line.rfind("Description:", 0) == 0) {
            task.description = line.substr(13);
        } else if (line.rfind("Status:", 0) == 0) {
            string status = line.substr(8);
            while (!status.empty() && status.front() == ' ') status.erase(status.begin());
            while (!status.empty() && status.back() == ' ') status.pop_back();
            task.complete = (status == "completed");
        } else if (line == "---") {
            tasks.push_back(task);
            task = Task();
        }
    }


    if (!task.title.empty()) tasks.push_back(task);

    return tasks;
}

void listTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet.\n";
        return;
    }
    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].title << "\n";
        cout << "   Description: " << tasks[i].description << "\n";
        cout << "   Status: " << (tasks[i].complete ? "completed" : "not completed") << "\n\n";
    }
}

void addTask(vector<Task>& tasks) {
    Task t;
    cout << "Enter title: ";
    getline(cin, t.title);
    cout << "Enter description: ";
    getline(cin, t.description);
    t.complete = false;
    tasks.push_back(t);
    cout << "Task added.\n";
}

void markComplete(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark.\n";
        return;
    }
    listTasks(tasks);
    cout << "Enter task number to mark as complete: ";
    int num;
    if (!(cin >> num)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore();
    if (num > 0 && num <= (int)tasks.size()) {
        tasks[num - 1].complete = true;
        cout << "Task marked as complete.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove.\n";
        return;
    }
    listTasks(tasks);
    cout << "Enter task number to remove: ";
    int num;
    if (!(cin >> num)) {
        cout << "Invalid input.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore();
    if (num > 0 && num <= (int)tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number. Remove failed.\n";
    }
}

void showMenu() {
    cout << "\n==== Task Manager ====\n";
    cout << "1. List Tasks\n";
    cout << "2. Add Task\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<Task> tasks = loadTasks();
    int choice;

    while (true) {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        cin.ignore(); 

        switch (choice) {
            case 1: listTasks(tasks); break;
            case 2: addTask(tasks); break;
            case 3: markComplete(tasks); break;
            case 4: removeTask(tasks); break;
            case 5:
                saveTasks(tasks);
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option, please try again.\n";
        }

        saveTasks(tasks);
    }
}
