#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 256

typedef struct {
    char task[MAX_TASK_LENGTH];
    int completed;
} Task;

void addTask(Task tasks[], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter the task: ");
    getchar(); // to consume the newline character left by previous input
    fgets(tasks[*taskCount].task, MAX_TASK_LENGTH, stdin);
    tasks[*taskCount].task[strcspn(tasks[*taskCount].task, "\n")] = 0; // remove newline character
    tasks[*taskCount].completed = 0;
    (*taskCount)++;
    printf("Task added successfully!\n");
}

void deleteTask(Task tasks[], int *taskCount) {
    int taskNumber;
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNumber);
    if (taskNumber < 1 || taskNumber > *taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*taskCount)--;
    printf("Task deleted successfully!\n");
}

void markTaskCompleted(Task tasks[], int taskCount) {
    int taskNumber;
    printf("Enter the task number to mark as completed: ");
    scanf("%d", &taskNumber);
    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number!\n");
        return;
    }
    tasks[taskNumber - 1].completed = 1;
    printf("Task marked as completed!\n");
}

void listTasks(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to show.\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].task, tasks[i].completed ? "Completed" : "Not Completed");
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Mark Task as Completed\n");
        printf("4. List Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                deleteTask(tasks, &taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                listTasks(tasks, taskCount);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}