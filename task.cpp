#include "task.h"

using namespace std;

Task::Task(const string &title, const string &class_name, const string &due_date, int priority) {
    this->title = title;
    this->class_name = class_name;
    this->due_date = due_date;
    this->priority = priority;
    completed = false;
    next = nullptr;
}

Task::~Task() { }

string Task::getTitle() const {
    return title;
}
string Task::getClassName() const {
    return class_name;
}
string Task::getDueDate() const {
    return due_date;
}
int Task::getPriority() const {
    return priority;
}
bool Task::getCompleted() const {
    return completed;
}
Task *Task::getNext() const {
    return next;
}

void Task::setTitle(const string &title) {
    this -> title = title;
}
void Task::setClassName(const string &class_name) {
    this -> class_name = class_name;
}
void Task::setDueDate(const string &due_date) {
    this -> due_date = due_date;
}
void Task::setPriority(int priority) {
    this -> priority = priority;
}
void Task::setCompleted(bool completed) {
    this -> completed = completed;
}
void Task::setNext(Task *next) {
    this -> next = next;
}
