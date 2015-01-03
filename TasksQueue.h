#include <list>

class TaskBase
{
public:
    virtual ~TaskBase() { }
    virtual void Do() = 0;
    virtual bool IsTaskFinished() const = 0;
};

class TasksQueue
{
public:
    TasksQueue();
    ~TasksQueue();

    // could be used by threads
    TaskBase* PopTask();
    bool IsEmpty() const;

    // only used in main thread
    void PushTask(TaskBase* task);

private:
    std::list<TaskBase*> m_tasks;
};
