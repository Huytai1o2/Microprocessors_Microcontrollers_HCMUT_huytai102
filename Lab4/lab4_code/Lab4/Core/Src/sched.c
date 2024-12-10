/*
 * sched.c
 *
 *  Created on: Nov 25, 2024
 *      Author: nguye
 */

#include "main.h"
#include "sched.h"

sTask *head = NULL;
sTask *tail = NULL;
int count = 0;
int id = 0;
SCH_Error_Code_t Error_code_G = ERROR_SCH_NO_ERROR;

void clear_sched(void)
{
    while (head != NULL)
    {
        sTask *temp = head;
        head = head->next;
        free(temp);
    }

    head = NULL;
    tail = NULL;
}

void SCH_Init(void)
{
    clear_sched();
    Error_code_G = 0;
//    Timer_init();
//    Watchdog_init();
    count = 0;
    id = 0;
}

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD, int TaskID) {
    // Tạo task mới
    sTask *new_task = (sTask *)malloc(sizeof(sTask));
    if (new_task == NULL) {
        Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
        return SCH_MAX_TASKS; // Trả về mã lỗi nếu không cấp phát được bộ nhớ
    }

    if (id > SCH_MAX_TASKS) {
        id = 0;  // reset TaskID
    }

    // Gán giá trị cho task mới
    new_task->pTask = pFunction;
    new_task->Delay = DELAY;
    new_task->Period = PERIOD;
    new_task->RunMe = 0;
    if (TaskID < 0)
    {
        new_task->TaskID = id++;
    } else {
        new_task->TaskID = TaskID;
    }
    new_task->next = NULL;
    new_task->prev = NULL;

    // Nếu danh sách rỗng
    if (head == NULL) {
        head = new_task;
        tail = new_task;
        count++;
        return new_task->TaskID;
    }

    // Duyệt danh sách để tìm vị trí chèn
    sTask *temp = head;
    while (temp != NULL && temp->Delay <= DELAY) {
        DELAY -= temp->Delay; // Giảm giá trị DELAY tương đối
        temp = temp->next;
    }

    // Chèn task mới vào trước temp
    new_task->Delay = DELAY; // Delay đã được điều chỉnh
    if (temp != NULL) {
        new_task->next = temp;
        new_task->prev = temp->prev;

        if (temp->prev != NULL) {
            temp->prev->next = new_task;
        } else {
            head = new_task; // Nếu chèn ở đầu danh sách
        }
        temp->prev = new_task;
        // temp->Delay -= DELAY; // Cập nhật Delay của task sau

        // update the delay of the next task
        temp->Delay -= DELAY;

    } else {
        // Nếu chèn ở cuối danh sách
        tail->next = new_task;
        new_task->prev = tail;
        tail = new_task;
    }

    count++;
    return new_task->TaskID;
}

void SCH_Dispatch_Tasks(void)
{
    sTask *temp = head;
    while (temp != NULL)
    {
        if (temp->RunMe > 0)
        {
            temp->RunMe = 0;
            temp->pTask();
            if (temp->Period == 0)
            {
                SCH_Delete_Task(temp->TaskID);
            }

            else
            {
                sTask *temp2 = (sTask *)malloc(sizeof(sTask));
                deep_copy(temp2, temp);

                SCH_Delete_Task(temp->TaskID);
                SCH_Add_Task(temp2->pTask, temp2->Delay, temp2->Period, temp2->TaskID);
            }

//            break;
        }

        temp = temp->next;
    }
}

void SCH_Delete_Task(unsigned char TaskID)
{
    sTask *temp = head;

    while (temp != NULL && temp->TaskID != TaskID)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        tail = temp->prev;
    }

    free(temp);
    count--;
    return;
}

void SCH_Update(void)
{
    if (head -> pTask != NULL)
    {
        if (head->Delay == 0)
        {
            head->RunMe +=1;
            if (head->Period)
            {
                head->Delay = head->Period;
            } else {
                SCH_Delete_Task(head->TaskID);
            }
        } else {
            head->Delay -= 1;
        }
    }
}

void deep_copy(sTask *dest, sTask *src)
{
    dest->pTask = src->pTask;
    dest->Delay = src->Delay;
    dest->Period = src->Period;
    dest->TaskID = src->TaskID;
}

