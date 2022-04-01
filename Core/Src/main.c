#include "gd32f3x0.h"
#include "systick.h"

#include "FreeRTOS.h"
#include "task.h"

#include "gpio.h"
#include "start_task.h"

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
		//User Init
		My_GPIO_Init();

		//startTask
		startTask();
		//�������
    vTaskStartScheduler(); 
    while(1){
    }
}



