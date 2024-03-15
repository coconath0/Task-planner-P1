#ifndef TASK_PLANNER_H
#define TASK_PLANNER_H

#include "task.h"

using namespace std;

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        void addNode(const Task& task, bool addToEnd = false);
        void removeNode(const string& title);
        void markCompleted(const string& title);
        void prioritizeTask(const string& title, int newPriority);
        void displayTasks() const;

    private:
        Task* head;

        Task* findNode(const string& title);
};

#endif