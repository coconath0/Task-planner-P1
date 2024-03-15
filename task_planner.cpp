#include "task_planner.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Task* current = head;
    while (current) {
        Task* next = current -> getNext();
        delete current;
        current = next;
    }
}

void LinkedList::addNode(const Task& task, bool addToEnd) {
    Task* newNode = new Task(task);
    if (addToEnd) {
        if (!head) {
            head = newNode;
        } else {
            Task* current = head;
            while (current -> getNext()) {
                current = current -> getNext();
            }
            current -> setNext(newNode);
        }
    } else {
        newNode -> setNext(head);
        head = newNode;
    }
}

void LinkedList::removeNode(const string& title) {
    Task* current = head;
    Task* prev = nullptr;

    while (current && current -> getTitle() != title) {
        prev = current;
        current = current -> getNext();
    }

    if (!current) {
        cerr << "Task not found: " << title << endl;
        return;
    }

    if (prev) {
        prev -> setNext(current -> getNext());
    } else {
        head = current -> getNext();
    }

    delete current;
}

void LinkedList::markCompleted(const string& title) {
    Task* task = findNode(title);
    if (task) {
        task -> setCompleted(true);
    } else {
        cerr << "Task not found: " << title << endl;
    }
}

void LinkedList::prioritizeTask(const string& title, int newPriority) {
    Task* task = findNode(title);
    if (task) {
        task -> setPriority(newPriority);
    } else {
        cerr << "Task not found: " << title << endl;
    }
}

void LinkedList::displayTasks() const {
    Task* current = head;

    while (current) {
        cout << "Title: " << current -> getTitle() << ", Class: " << current -> getClassName()
                << ", Due Date: " << current -> getDueDate() << ", Priority: " << current -> getPriority()
                << ", Completed: " << (current -> getCompleted() ? "Yes" : "No") << endl;
        current = current -> getNext();
    }
}

Task* LinkedList::findNode(const string& title) {
    Task* current = head;

    while (current && current -> getTitle() != title) {
        current = current -> getNext();
    }

    return current;
}
