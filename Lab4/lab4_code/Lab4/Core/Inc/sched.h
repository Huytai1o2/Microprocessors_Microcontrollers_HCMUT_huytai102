/*
 * schd.h
 *
 *  Created on: Nov 25, 2024
 *      Author: nguye
 */

#ifndef INC_SCHED_H_
#define INC_SCHED_H_

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

#include "main.h"

typedef enum {
    ERROR_SCH_NO_ERROR = 0,                  // Không có lỗi
    ERROR_SCH_TOO_MANY_TASKS = 1,           // Quá nhiều task trong hàng đợi
    ERROR_SCH_CANNOT_DELETE_TASK = 2,       // Không thể xóa task
    ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK = 3, // Đang chờ phản hồi từ slave
    ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER = 4, // Đang chờ lệnh bắt đầu từ master
    ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START = 5, // Một hoặc nhiều slave không khởi động
    ERROR_SCH_LOST_SLAVE = 6,               // Mất kết nối với slave
    ERROR_SCH_CAN_BUS_ERROR = 7,            // Lỗi bus CAN
    ERROR_I2C_WRITE_BYTE_AT24C64 = 8        // Lỗi ghi byte I2C
} SCH_Error_Code_t;

typedef struct sTask{
	void (* pTask) (void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
    struct sTask *next;
    struct sTask *prev;
} sTask;

extern sTask *head;
extern sTask *tail;
extern int count;
extern int id;
extern SCH_Error_Code_t Error_code_G;


void clear_sched(void);
void SCH_Init(void);
unsigned char SCH_Add_Task(void (* pFunction)(), unsigned int DELAY, unsigned int PERIOD, int TaskID);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(unsigned char TaskID);
void SCH_Update(void);

void deep_copy(sTask *dest, sTask *src);

#endif /* INC_SCHED_H_ */
