#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_WAIT_TIME 3000  // 最长等待时间(300t = 30秒)
#define CLOCK_UNIT 0.1      // 时钟单位(0.1秒)

// 电梯状态
typedef enum {
    OPENING, OPENED, CLOSING, CLOSED, WAITING, MOVING, DECELERATE
} ElevatorState;

// 乘客结构体
typedef struct {
    int id;             // 乘客ID
    int fromFloor;      // 出发楼层
    int toFloor;        // 目标楼层
    int arrivalTime;    // 到达时间
    int waitTime;       // 等待时间
    int inElevator;     // 是否在电梯内
} Passenger;

// 队列节点
typedef struct Node {
    Passenger passenger;
    struct Node* next;
} Node;

// 链队列
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// 乘客栈
typedef struct {
    Passenger passengers[MAX_PASSENGERS];
    int top;
} Stack;

// 全局变量
int currentTime = 0;                  // 当前模拟时间
int callUp[4] = {0};                  // 向上呼叫按钮[0..3]
int callDown[4] = {0};                // 向下呼叫按钮[1..4]
int callCar[5] = {0};                 // 电梯内呼叫按钮[0..4]
ElevatorState elevatorState = WAITING; // 电梯当前状态
int elevatorFloor = 1;                // 电梯当前楼层
int elevatorDirection = 0;            // 电梯方向: -1=向下, 0=静止, 1=向上
int lastMovementTime = 0;             // 上次移动时间
Queue upQueues[5];                    // 每层向上队列
Queue downQueues[5];                  // 每层向下队列
Stack eleStacks[5];                   // 电梯内各层乘客栈
int nextPassengerId = 0;              // 下一个乘客ID
int doorOpenTime = 0;                 // 门打开的时间

// 初始化队列
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// 入队
void enqueue(Queue* q, Passenger p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->passenger = p;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出队
int dequeue(Queue* q, Passenger* p) {
    if (q->front == NULL) return 0;
    *p = q->front->passenger;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return 1;
}

// 判断队列是否为空
int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// 初始化栈
void initStack(Stack* s) {
    s->top = -1;
}

// 入栈
int push(Stack* s, Passenger p) {
    if (s->top >= MAX_PASSENGERS - 1) return 0;
    s->passengers[++(s->top)] = p;
    return 1;
}

// 出栈
int pop(Stack* s, Passenger* p) {
    if (s->top < 0) return 0;
    *p = s->passengers[(s->top)--];
    return 1;
}

// 判断栈是否为空
int isStackEmpty(Stack* s) {
    return s->top < 0;
}

// 生成新乘客
void generatePassenger() {
    if (rand() % 100 < 5) { // 5%概率生成新乘客
        Passenger p;
        p.id = nextPassengerId++;
        p.fromFloor = rand() % 5;
        
        // 确保目标楼层与出发楼层不同
        do {
            p.toFloor = rand() % 5;
        } while (p.toFloor == p.fromFloor);
        
        p.arrivalTime = currentTime;
        p.waitTime = 0;
        p.inElevator = 0;
        
        printf("t=%.1fs: 乘客%d在楼层%d生成，想去楼层%d\n", 
               currentTime * CLOCK_UNIT, p.id, p.fromFloor, p.toFloor);
        
        // 更新呼叫按钮
        if (p.toFloor > p.fromFloor) {
            callUp[p.fromFloor] = 1;
            enqueue(&upQueues[p.fromFloor], p);
        } else {
            callDown[p.fromFloor] = 1;
            enqueue(&downQueues[p.fromFloor], p);
        }
    }
}

// 检查乘客是否放弃
void checkPassengerGiveUp() {
    for (int i = 0; i < 5; i++) {
        // 检查向上队列
        Node* current = upQueues[i].front;
        Node* prev = NULL;
        while (current != NULL) {
            current->passenger.waitTime++;
            if (current->passenger.waitTime > MAX_WAIT_TIME) {
                printf("t=%.1fs: 乘客%d在楼层%d等待超时，放弃乘坐电梯\n", 
                       currentTime * CLOCK_UNIT, current->passenger.id, i);
                Node* temp = current;
                if (prev == NULL) {
                    upQueues[i].front = current->next;
                    if (upQueues[i].front == NULL) upQueues[i].rear = NULL;
                    current = upQueues[i].front;
                } else {
                    prev->next = current->next;
                    if (prev->next == NULL) upQueues[i].rear = prev;
                    current = prev->next;
                }
                free(temp);
                callUp[i] = (upQueues[i].front != NULL) ? 1 : 0;
            } else {
                prev = current;
                current = current->next;
            }
        }
        
        // 检查向下队列
        current = downQueues[i].front;
        prev = NULL;
        while (current != NULL) {
            current->passenger.waitTime++;
            if (current->passenger.waitTime > MAX_WAIT_TIME) {
                printf("t=%.1fs: 乘客%d在楼层%d等待超时，放弃乘坐电梯\n", 
                       currentTime * CLOCK_UNIT, current->passenger.id, i);
                Node* temp = current;
                if (prev == NULL) {
                    downQueues[i].front = current->next;
                    if (downQueues[i].front == NULL) downQueues[i].rear = NULL;
                    current = downQueues[i].front;
                } else {
                    prev->next = current->next;
                    if (prev->next == NULL) downQueues[i].rear = prev;
                    current = prev->next;
                }
                free(temp);
                callDown[i] = (downQueues[i].front != NULL) ? 1 : 0;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

// 电梯开门
void openDoor() {
    printf("t=%.1fs: 电梯在楼层%d开始开门\n", currentTime * CLOCK_UNIT, elevatorFloor);
    elevatorState = OPENING;
    doorOpenTime = currentTime;
}

// 电梯关门
void closeDoor() {
    printf("t=%.1fs: 电梯在楼层%d开始关门\n", currentTime * CLOCK_UNIT, elevatorFloor);
    elevatorState = CLOSING;
}

// 电梯移动
void moveElevator() {
    if (elevatorDirection == 1) {
        elevatorFloor++;
        printf("t=%.1fs: 电梯上升到楼层%d\n", currentTime * CLOCK_UNIT, elevatorFloor);
    } else if (elevatorDirection == -1) {
        elevatorFloor--;
        printf("t=%.1fs: 电梯下降到楼层%d\n", currentTime * CLOCK_UNIT, elevatorFloor);
    }
    elevatorState = MOVING;
    lastMovementTime = currentTime;
}

// 电梯减速
void decelerateElevator() {
    printf("t=%.1fs: 电梯在楼层%d开始减速\n", currentTime * CLOCK_UNIT, elevatorFloor);
    elevatorState = DECELERATE;
}

// 电梯到达目标楼层
void arriveAtFloor() {
    printf("t=%.1fs: 电梯到达楼层%d\n", currentTime * CLOCK_UNIT, elevatorFloor);
    elevatorState = OPENING;
}

// 乘客进出电梯
void processPassengerMovement() {
    static int lastCheckTime = currentTime;
    static int movementOccurred = 0;
    
    // 每40t检查一次
    if (currentTime - lastCheckTime < 40) return;
    lastCheckTime = currentTime;
    
    int movement = 0;
    
    // 乘客出电梯
    if (!isStackEmpty(&eleStacks[elevatorFloor])) {
        Passenger p;
        if (pop(&eleStacks[elevatorFloor], &p)) {
            printf("t=%.1fs: 乘客%d从电梯出来，到达楼层%d\n", 
                   currentTime * CLOCK_UNIT, p.id, elevatorFloor);
            movement = 1;
            // 乘客出电梯需要25t
            currentTime += 25;
        }
    }
    
    // 乘客进电梯
    if (elevatorDirection >= 0 && !isQueueEmpty(&upQueues[elevatorFloor])) {
        Passenger p;
        if (dequeue(&upQueues[elevatorFloor], &p)) {
            printf("t=%.1fs: 乘客%d进入电梯，按了楼层%d按钮\n", 
                   currentTime * CLOCK_UNIT, p.id, p.toFloor);
            push(&eleStacks[p.toFloor], p);
            callCar[p.toFloor] = 1;
            movement = 1;
            // 乘客进电梯需要25t
            currentTime += 25;
        }
    }
    
    if (elevatorDirection <= 0 && !isQueueEmpty(&downQueues[elevatorFloor])) {
        Passenger p;
        if (dequeue(&downQueues[elevatorFloor], &p)) {
            printf("t=%.1fs: 乘客%d进入电梯，按了楼层%d按钮\n", 
                   currentTime * CLOCK_UNIT, p.id, p.toFloor);
            push(&eleStacks[p.toFloor], p);
            callCar[p.toFloor] = 1;
            movement = 1;
            // 乘客进电梯需要25t
            currentTime += 25;
        }
    }
    
    if (movement) {
        movementOccurred = 1;
    } else if (elevatorState == OPENED) {
        // 连续两次检查都没有移动，开始关门
        if (!movementOccurred) {
            closeDoor();
        }
        movementOccurred = 0;
    }
}

// 寻找下一个目标楼层
int findNextTargetFloor() {
    int nextFloor = -1;
    
    // 优先处理当前方向上的呼叫
    if (elevatorDirection == 1) {
        // 向上寻找最近的呼叫
        for (int i = elevatorFloor + 1; i < 5; i++) {
            if (callUp[i] || callDown[i] || callCar[i]) {
                return i;
            }
        }
        // 检查下方是否有呼叫
        for (int i = elevatorFloor - 1; i >= 0; i--) {
            if (callUp[i] || callDown[i] || callCar[i]) {
                elevatorDirection = -1;
                return i;
            }
        }
    } else if (elevatorDirection == -1) {
        // 向下寻找最近的呼叫
        for (int i = elevatorFloor - 1; i >= 0; i--) {
            if (callUp[i] || callDown[i] || callCar[i]) {
                return i;
            }
        }
        // 检查上方是否有呼叫
        for (int i = elevatorFloor + 1; i < 5; i++) {
            if (callUp[i] || callDown[i] || callCar[i]) {
                elevatorDirection = 1;
                return i;
            }
        }
    }
    
    // 如果没有呼叫，检查是否需要返回第一层
    if (nextFloor == -1 && elevatorFloor != 1) {
        return 1;
    }
    
    return nextFloor;
}

// 更新电梯状态
void updateElevatorState() {
    static int stateStartTime = currentTime;
    
    switch (elevatorState) {
        case OPENING:
            if (currentTime - stateStartTime >= 20) { // 开门需要20t
                elevatorState = OPENED;
                printf("t=%.1fs: 电梯在楼层%d门已完全打开\n", currentTime * CLOCK_UNIT, elevatorFloor);
                stateStartTime = currentTime;
            }
            break;
            
        case OPENED:
            processPassengerMovement();
            // 检查是否长时间静止
            if (currentTime - lastMovementTime > 300 && elevatorFloor != 1) {
                closeDoor();
            }
            break;
            
        case CLOSING:
            if (currentTime - stateStartTime >= 20) { // 关门需要20t
                elevatorState = CLOSED;
                printf("t=%.1fs: 电梯在楼层%d门已完全关闭\n", currentTime * CLOCK_UNIT, elevatorFloor);
                
                int nextFloor = findNextTargetFloor();
                if (nextFloor != -1) {
                    elevatorDirection = (nextFloor > elevatorFloor) ? 1 : -1;
                    elevatorState = MOVING;
                    printf("t=%.1fs: 电梯开始移动，目标楼层%d\n", 
                           currentTime * CLOCK_UNIT, nextFloor);
                    // 电梯加速需要15t
                    currentTime += 15;
                    moveElevator();
                } else {
                    elevatorState = WAITING;
                    printf("t=%.1fs: 电梯在楼层%d等待\n", currentTime * CLOCK_UNIT, elevatorFloor);
                }
                stateStartTime = currentTime;
            }
            break;
            
        case CLOSED:
            // 此状态已在CLOSING处理
            break;
            
        case WAITING:
            // 检查是否有新的呼叫
            if (callUp[elevatorFloor] || callDown[elevatorFloor] || callCar[elevatorFloor]) {
                openDoor();
                stateStartTime = currentTime;
            } else {
                // 检查是否有其他楼层呼叫
                int nextFloor = findNextTargetFloor();
                if (nextFloor != -1) {
                    elevatorDirection = (nextFloor > elevatorFloor) ? 1 : -1;
                    elevatorState = MOVING;
                    printf("t=%.1fs: 电梯开始移动，目标楼层%d\n", 
                           currentTime * CLOCK_UNIT, nextFloor);
                    // 电梯加速需要15t
                    currentTime += 15;
                    moveElevator();
                    stateStartTime = currentTime;
                } else if (elevatorFloor != 1 && currentTime - lastMovementTime > 300) {
                    // 长时间静止，返回第一层
                    elevatorDirection = (1 > elevatorFloor) ? 1 : -1;
                    elevatorState = MOVING;
                    printf("t=%.1fs: 电梯长时间静止，返回第一层候命\n", currentTime * CLOCK_UNIT);
                    // 电梯加速需要15t
                    currentTime += 15;
                    moveElevator();
                    stateStartTime = currentTime;
                }
            }
            break;
            
        case MOVING:
            // 模拟电梯移动时间
            if (rand() % 100 < 20) { // 20%概率到达下一层
                int nextFloor = findNextTargetFloor();
                if (nextFloor == elevatorFloor) {
                    decelerateElevator();
                    // 电梯减速需要15t
                    currentTime += 15;
                    stateStartTime = currentTime;
                } else {
                    moveElevator();
                    stateStartTime = currentTime;
                }
            }
            break;
            
        case DECELERATE:
            if (currentTime - stateStartTime >= 15) { // 减速需要15t
                arriveAtFloor();
                stateStartTime = currentTime;
            }
            break;
    }
}

// 初始化系统
void initSystem() {
    srand(time(NULL));
    
    for (int i = 0; i < 5; i++) {
        initQueue(&upQueues[i]);
        initQueue(&downQueues[i]);
        initStack(&eleStacks[i]);
    }
    
    elevatorState = WAITING;
    elevatorFloor = 1;
    elevatorDirection = 0;
    lastMovementTime = 0;
    
    printf("电梯模拟系统启动，当前时间: %.1fs\n", currentTime * CLOCK_UNIT);
}

int main() {
    initSystem();
    
    // 模拟运行5000个时间单位(500秒)
    for (int i = 0; i < 5000; i++) {
        generatePassenger();
        checkPassengerGiveUp();
        updateElevatorState();
        
        // 每100个时间单位打印一次状态
        if (currentTime % 100 == 0) {
            printf("\n--- t=%.1fs: 系统状态 ---\n", currentTime * CLOCK_UNIT);
            printf("电梯状态: ");
            switch (elevatorState) {
                case OPENING: printf("正在开门\n"); break;
                case OPENED: printf("门已打开\n"); break;
                case CLOSING: printf("正在关门\n"); break;
                case CLOSED: printf("门已关闭\n"); break;
                case WAITING: printf("等待中\n"); break;
                case MOVING: printf("移动中\n"); break;
                case DECELERATE: printf("减速中\n"); break;
            }
            printf("电梯位置: 楼层%d\n", elevatorFloor);
            printf("电梯方向: ");
            if (elevatorDirection == 1) printf("向上\n");
            else if (elevatorDirection == -1) printf("向下\n");
            else printf("静止\n");
            
            printf("呼叫状态: ");
            printf("向上[");
            for (int i = 0; i < 4; i++) printf("%d ", callUp[i]);
            printf("] 向下[");
            for (int i = 0; i < 4; i++) printf("%d ", callDown[i]);
            printf("] 电梯内[");
            for (int i = 0; i < 5; i++) printf("%d ", callCar[i]);
            printf("]\n\n");
        }
        
        currentTime++;
    }
    
    return 0;
}    