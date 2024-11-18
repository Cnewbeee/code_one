#include "stm32f4xx.h" 
#include "FreeRTOS.h" 
#include "task.h" 
#include "semphr.h" 
#include <stdio.h> 

// 定义任务栈大小 
#define SENSOR_TASK_STACK_SIZE 256 
#define PROCESS_TASK_STACK_SIZE 256 
#define DISPLAY_TASK_STACK_SIZE 256 

// 定义任务优先级 
#define SENSOR_TASK_PRIORITY 2 
#define PROCESS_TASK_PRIORITY 3 
#define DISPLAY_TASK_PRIORITY 2 

// 定义互斥锁和信号量 
SemaphoreHandle_t data_mutex; 
SemaphoreHandle_t data_ready_semaphore; 

// 模拟传感器数据结构 
typedef struct { 
    int value;
} SensorData; 

// 全局变量存储传感器数据 
SensorData sensor_data; 

// 传感器任务函数 
void sensorTaskFunction(void *pvParameters) { 
    while (1) { 
        // 模拟传感器数据采集 
        sensor_data.value = rand() % 100; 
        
        // 释放数据就绪信号量 
        xSemaphoreGive(data_ready_semaphore); 

        // 等待一段时间再采集下一次数据 
        vTaskDelay(1000 / portTICK_PERIOD_MS); 
        }
} 
// 数据处理任务函数 
void processTaskFunction(void *pvParameters) { 
    while (1) { 
        // 等待数据就绪信号量 
        xSemaphoreTake(data_ready_semaphore, portMAX_DELAY); 
        
        // 获取互斥锁以访问传感器数据 
        xSemaphoreTake(data_mutex, portMAX_DELAY); 
        
        // 处理传感器数据，这里只是简单地打印 
        printf("Processed data: %d\n", sensor_data.value * 2); 
        
        // 释放互斥锁 xSemaphoreGive(data_mutex); 
    } 
} 

// 显示任务函数 
void displayTaskFunction(void *pvParameters) { 
    while (1) { 
        // 获取互斥锁以访问传感器数据 
        xSemaphoreTake(data_mutex, portMAX_DELAY); 
        
        // 显示传感器数据，这里只是简单地打印 
        printf("Display data: %d\n", sensor_data.value); 
        
        // 释放互斥锁 
        xSemaphoreGive(data_mutex); 
        
        // 等待一段时间再显示下一次数据 
        vTaskDelay(2000 / portTICK_PERIOD_MS); 
    } 
} 

int main(void) { 
    // 初始化随机数种子 
    srand((unsigned int)time(NULL)); 

    // 创建互斥锁和信号量 
    data_mutex = xSemaphoreCreateMutex(); 
    data_ready_semaphore = xSemaphoreCreateBinary(); 
    
    // 创建传感器任务 
    xTaskCreate(sensorTaskFunction, "SensorTask", SENSOR_TASK_STACK_SIZE, NULL, SENSOR_TASK_PRIORITY, NULL); 
    
    // 创建数据处理任务 
    xTaskCreate(processTaskFunction, "ProcessTask", PROCESS_TASK_STACK_SIZE, NULL, PROCESS_TASK_PRIORITY, NULL); 
    
    // 创建显示任务 
    xTaskCreate(displayTaskFunction, "DisplayTask", DISPLAY_TASK_STACK_SIZE, NULL, DISPLAY_TASK_PRIORITY, NULL); 
    
    // 启动调度器 
    vTaskStartScheduler(); 
    while (1) { } 
}