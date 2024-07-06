#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

void displayTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks, const string& desc);
void removeTask(vector<Task>& tasks, const string& desc);

int main() {
    vector<Task> tasks;
    int choice;
    string description;

    cout << "Welcome to the To-Do List Manager!" << endl;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                tasks.push_back(Task(description));
                cout << "Task added successfully!" << endl;
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                cout << "Enter task description to mark as completed: ";
                getline(cin, description);
                markTaskCompleted(tasks, description);
                break;
            case 4:
                cout << "Enter task description to remove: ";
                getline(cin, description);
                removeTask(tasks, description);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[Completed] ";
            } else {
                cout << "[Pending] ";
            }
            cout << tasks[i].description << endl;
        }
    }
}

void markTaskCompleted(vector<Task>& tasks, const string& desc) {
    auto it = find_if(tasks.begin(), tasks.end(), [&desc](const Task& task) {
        return task.description == desc;
    });

    if (it != tasks.end()) {
        it->completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Task not found. Check your input." << endl;
    }
}

void removeTask(vector<Task>& tasks, const string& desc) {
    auto it = find_if(tasks.begin(), tasks.end(), [&desc](const Task& task) {
        return task.description == desc;
    });

    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Task not found. Check your input." << endl;
    }
}
