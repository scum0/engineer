#include "pyro_core_def.h"
#include "pyro_core_config.h"
#include "FreeRTOS.h"
#include "task.h"
extern "C"
{
    extern void pyro_init_thread(void *argument);
    extern void engineer_arm_init(void *argument);


    void start_mission_planer_task(void const *argument)
    {

        xTaskCreate(pyro_init_thread, "pyro_init_thread", 512, nullptr,
                    configMAX_PRIORITIES - 1, nullptr);
        // vTaskDelay(10);

#if BOARD == GIMBAL_BOARD
        xTaskCreate(engineer_arm_init, "engineer_arm_init", 512, nullptr,
                    configMAX_PRIORITIES - 1, nullptr);
        vTaskDelay(20);
#elif BOARD == CHASSIS_BOARD
        
#endif

        vTaskDelete(nullptr);
    }
}