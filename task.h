#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task {
    public:
        Task(const string& title, const string& class_name, const string& due_date, int priority);
        ~Task();

        string getTitle() const;
        string getClassName() const;
        string getDueDate() const;
        int getPriority() const;
        bool getCompleted() const;
        Task* getNext() const;

        void setTitle(const string& title);
        void setClassName(const string& class_name);
        void setDueDate(const string& due_date);
        void setPriority(int priority);
        void setCompleted(bool completed);
        void setNext(Task* next);

    private:
        string title;
        string class_name;
        string due_date;
        int priority;
        bool completed;
        Task* next;
};

#endif