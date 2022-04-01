#include "start_task.h"

#include "bsp_led.h"
#include "bsp_usart.h"

//任务优先级
#define START_TASK_PRIO		1
//任务堆栈大小	
#define START_STK_SIZE 		128  
//任务句柄
TaskHandle_t StartTask_Handler;
//任务函数
void start_task(void *pvParameters);

#define LED_TASK_PRIO		10
#define LED_STK_SIZE 		128  
TaskHandle_t LEDTask_Handler;
void led_task(void *pvParameters);

#define USART0_TASK_PRIO		6	
#define USART0_STK_SIZE 		128  
TaskHandle_t USART0Task_Handler;
void usart0_task(void *pvParameters);


//在mian函数中调用
void startTask(void)
{
	xTaskCreate((TaskFunction_t )start_task,           
				(const char*    )"start_task",        
				(uint16_t       )START_STK_SIZE,      
				(void*          )NULL,                  
				(UBaseType_t    )START_TASK_PRIO,      
				(TaskHandle_t*  )&StartTask_Handler);   
}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           
	
    xTaskCreate((TaskFunction_t )led_task,             
                (const char*    )"led_task",           
                (uint16_t       )LED_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )LED_TASK_PRIO,        
                (TaskHandle_t*  )&LEDTask_Handler); 
								
		xTaskCreate((TaskFunction_t )usart0_task,             
                (const char*    )"usart0_task",           
                (uint16_t       )USART0_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )USART0_TASK_PRIO,        
                (TaskHandle_t*  )&USART0Task_Handler); 
				
    vTaskDelete(StartTask_Handler); //删除开始任务
				
    taskEXIT_CRITICAL();   //退出临界区,任务级临界区不允许嵌套,中断级允许         
}

void led_task(void *pvParameters)
{
	while(1)
	{
    vTaskDelay(500);
		led_toggle();
	}
}

void usart0_task(void *pvParameters)
{
	while(1)
	{
		vTaskDelay(100);
		usart0_printf("Hello,GD32!\r\n");
	}
}
