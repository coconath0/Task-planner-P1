#include <iostream>
#include "task_planner.h"

using namespace std;

int main() {
    LinkedList taskPlanner;
    cout << "\n-------- TEST CASES --------\n";

    //Test Case 1: add and display tasks
    Task task1("Task1", "Class1", "2024-01-16", 1);
    Task task2("Task2", "Class2", "2024-02-24", 2);
    Task task3("Task3", "Class3", "2024-03-05", 3);

    taskPlanner.addNode(task1);
    taskPlanner.addNode(task2);
    taskPlanner.addNode(task3);

    cout << "\n Test 1: Adding and displaying all tasks:\n";
    taskPlanner.displayTasks();

    //Test Case 2: remove and mark tasks
    taskPlanner.removeNode("Task1");
    taskPlanner.markCompleted("Task2");

    cout << "\n Test 2: After removing and marking tasks as completed:\n";
    taskPlanner.displayTasks();

    //Test Case 3: prioritize task
    taskPlanner.addNode(Task("Task4", "Class4", "2024-04-25", 4));
    taskPlanner.prioritizeTask("Task2", 5);

    cout << "\n Test 3: After prioritizing Task 2:\n";
    taskPlanner.displayTasks();

    //Test Case 4: Error Testing
    cout << "\n Test 4: Error testing - using task that doesn't exist:\n";
    taskPlanner.removeNode("Homework 1");
    taskPlanner.markCompleted("Homework 2");
    taskPlanner.prioritizeTask("Homework 3", 5);
    cout << "\n-------- END OF TEST CASES --------\n";

    while (true) {
        cout << "\nTask Planner Menu:\n";
        cout << "1. Add task\n";
        cout << "2. Remove task\n";
        cout << "3. Mark task as Completed\n";
        cout << "4. Prioritize task\n";
        cout << "5. Display tasks\n";
        cout << "6. Exit\n";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, class_name, dueDate;
                int priority;

                cout << "Enter task information:\n";
                cout << "Title: ";
                cin >> title;
                cout << "Class: ";
                cin >> class_name;
                cout << "Due Date (Format: yyyy-mm-dd): ";
                cin >> dueDate;
                cout << "Number of riority: ";
                cin >> priority;

                Task newTask(title, class_name, dueDate, priority);
                taskPlanner.addNode(newTask);
                break;
            }
            case 2: {
                string title;
                cout << "Enter the title of task to remove: ";
                cin >> title;
                taskPlanner.removeNode(title);
                break;
            }
            case 3: {
                string title;
                cout << "Enter the title of task to mark as completed: ";
                cin >> title;
                taskPlanner.markCompleted(title);
                break;
            }
            case 4: {
                string title;
                int newPriority;
                cout << "Enter the title of task to prioritize: ";
                cin >> title;
                cout << "Enter new priority: ";
                cin >> newPriority;
                taskPlanner.prioritizeTask(title, newPriority);
                break;
            }
            case 5:
                cout << "\nAll Tasks:\n";
                taskPlanner.displayTasks();
                break;
            case 6:
                cout << "Closing...\n";
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
