#include "gd32f3x0.h"
#include "systick.h"

#include "FreeRTOS.h"
#include "task.h"


#define START_TASK_PRIO		1
#define START_STK_SIZE 		128  
TaskHandle_t StartTask_Handler;
void start_task(void *pvParameters);

#define TASK1_TASK_PRIO		2
#define TASK1_STK_SIZE 		128  
TaskHandle_t Task1Task_Handler;
void task1_task(void *pvParameters);

#define TASK2_TASK_PRIO		3	
#define TASK2_STK_SIZE 		128  
TaskHandle_t Task2Task_Handler;
void task2_task(void *pvParameters);

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{  
		nvic_priority_group_set(NVIC_PRIGROUP_PRE4_SUB0);
    systick_config();
    /* enable the LED GPIO clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    /* configure led GPIO port */ 
    gpio_mode_set(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_8);
    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
    
    gpio_bit_reset(GPIOA, GPIO_PIN_8);
	
    xTaskCreate((TaskFunction_t )start_task,           
				(const char*    )"start_task",        
				(uint16_t       )START_STK_SIZE,      
				(void*          )NULL,                  
				(UBaseType_t    )START_TASK_PRIO,      
				(TaskHandle_t*  )&StartTask_Handler);   
				
		vTaskStartScheduler(); 
	
    while(1){
//        /* turn on led */
//        gpio_bit_write(GPIOA, GPIO_PIN_8, SET);
//        delay_1ms(1000);
//        
//        /* turn off led */
//        gpio_bit_write(GPIOA, GPIO_PIN_8, RESET);
//        delay_1ms(1000);
    }
}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           
	
    xTaskCreate((TaskFunction_t )task1_task,             
                (const char*    )"task1_task",           
                (uint16_t       )TASK1_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )TASK1_TASK_PRIO,        
                (TaskHandle_t*  )&Task1Task_Handler);   
								
    xTaskCreate((TaskFunction_t )task2_task,     
                (const char*    )"task2_task",   
                (uint16_t       )TASK2_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )TASK2_TASK_PRIO,
                (TaskHandle_t*  )&Task2Task_Handler); 
				
    vTaskDelete(StartTask_Handler); 
				
    taskEXIT_CRITICAL();            
}

void task1_task(void *pvParameters)
{
	while(1)
	{
		gpio_bit_write(GPIOA, GPIO_PIN_8, SET);
    vTaskDelay(500);
		gpio_bit_write(GPIOA, GPIO_PIN_8, RESET);		
		vTaskDelay(500);
	}
}


void task2_task(void *pvParameters)
{
	while(1)
	{
   // gd_eval_led_on(LED2);;
        vTaskDelay(200); 
		//gd_eval_led_off(LED2);;
        vTaskDelay(800); 
	}
}

