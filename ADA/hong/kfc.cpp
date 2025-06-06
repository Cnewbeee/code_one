#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASS 100
#define MAX_WAIT 3000
#define TIME_UNIT 0.1

typedef enum {
    OPENING, OPENED, CLOSING, CLOSED, WAITING, MOVING, DECEL
} ElevatorState;

typedef struct {
    int id;
    int from;
    int to;
    int arrive;
    int enter;
    int leave;
    int giveUp;
    int inElevator;
    int finished;
    int gaveUp;
} Passenger;

typedef struct QueueNode {
    Passenger p;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

typedef struct {
    Passenger pass[MAX_PASS];
    int top;
} Stack;

int simulationTime = 0;  // 重命名time变量避免冲突
int currentFloor = 1;    // 重命名floor变量避免冲突
ElevatorState state = WAITING;
int dir = 0;
int openTimer = 0;
int moveTimer = 0;
int waitTimer = 0;
int upCall[4] = {0};
int downCall[4] = {0};
int carCall[5] = {0};
Queue upQ[4];
Queue downQ[4];
Stack carStack[5];
Passenger passengers[MAX_PASS];
int passCount = 0;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, Passenger p) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->p = p;
    node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int dequeue(Queue* q, Passenger* p) {
    if (q->front == NULL) return 0;
    *p = q->front->p;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return 1;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, Passenger p) {
    if (s->top < MAX_PASS - 1) {
        s->pass[++s->top] = p;
    }
}

int pop(Stack* s, Passenger* p) {
    if (s->top >= 0) {
        *p = s->pass[s->top--];
        return 1;
    }
    return 0;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void addPassenger() {
    if (passCount >= MAX_PASS) return;
    
    int from, to;
    do {
        from = rand() % 5;
        to = rand() % 5;
    } while (from == to);
    
    Passenger newPass;
    newPass.id = passCount++;
    newPass.from = from;
    newPass.to = to;
    newPass.arrive = simulationTime;
    newPass.enter = -1;
    newPass.leave = -1;
    newPass.giveUp = simulationTime + MAX_WAIT;
    newPass.inElevator = 0;
    newPass.finished = 0;
    newPass.gaveUp = 0;
    
    passengers[newPass.id] = newPass;
    
    if (to > from) {
        upCall[from] = 1;
        enqueue(&upQ[from], newPass);
    } else {
        downCall[from] = 1;
        enqueue(&downQ[from], newPass);
    }
    
    printf("时间 %.1f 秒：乘客 %d 出现在楼层 %d，想去楼层 %d\n", 
           simulationTime * TIME_UNIT, newPass.id, from, to);
}

void checkGiveUp() {
    for (int i = 0; i < passCount; i++) {
        Passenger* p = &passengers[i];
        if (!p->gaveUp && !p->inElevator && simulationTime >= p->giveUp) {
            p->gaveUp = 1;
            
            Queue* q;
            if (p->to > p->from) {
                q = &upQ[p->from];
            } else {
                q = &downQ[p->from];
            }
            
            Queue tempQ;
            initQueue(&tempQ);
            Passenger tempP;
            
            while (dequeue(q, &tempP)) {
                if (tempP.id != p->id) {
                    enqueue(&tempQ, tempP);
                }
            }
            
            while (dequeue(&tempQ, &tempP)) {
                enqueue(q, tempP);
            }
            
            if (isQueueEmpty(q)) {
                if (p->to > p->from) {
                    upCall[p->from] = 0;
                } else {
                    downCall[p->from] = 0;
                }
            }
            
            printf("时间 %.1f 秒：乘客 %d 在楼层 %d 等待超时，放弃乘坐电梯\n", 
                   simulationTime * TIME_UNIT, p->id, p->from);
        }
    }
}

void handlePassMovement() {
    static int moveTimer = 0;
    
    if (state != OPENED) return;
    
    moveTimer++;
    
    if (moveTimer % 40 != 0) return;
    
    int moved = 0;
    
    if (!isStackEmpty(&carStack[currentFloor])) {
        Passenger p;
        if (pop(&carStack[currentFloor], &p)) {
            p.finished = 1;
            p.leave = simulationTime;
            passengers[p.id] = p;
            carCall[p.to] = 0;
            moved = 1;
            printf("时间 %.1f 秒：乘客 %d 从电梯出来，到达楼层 %d\n", 
                   simulationTime * TIME_UNIT, p.id, currentFloor);
        }
    }
    
    Queue* q;
    if (dir > 0 && !isQueueEmpty(&upQ[currentFloor])) {
        q = &upQ[currentFloor];
    } else if (dir < 0 && !isQueueEmpty(&downQ[currentFloor])) {
        q = &downQ[currentFloor];
    } else if (dir == 0) {
        if (!isQueueEmpty(&upQ[currentFloor])) {
            q = &upQ[currentFloor];
        } else if (!isQueueEmpty(&downQ[currentFloor])) {
            q = &downQ[currentFloor];
        } else {
            q = NULL;
        }
    } else {
        q = NULL;
    }
    
    if (q != NULL) {
        Passenger p;
        if (dequeue(q, &p)) {
            p.inElevator = 1;
            p.enter = simulationTime;
            push(&carStack[p.to], p);
            carCall[p.to] = 1;
            moved = 1;
            
            if (p.to > p.from) {
                if (isQueueEmpty(&upQ[p.from])) {
                    upCall[p.from] = 0;
                }
            } else {
                if (isQueueEmpty(&downQ[p.from])) {
                    downCall[p.from] = 0;
                }
            }
            
            printf("时间 %.1f 秒：乘客 %d 进入电梯，从楼层 %d 去楼层 %d\n", 
                   simulationTime * TIME_UNIT, p.id, p.from, p.to);
        }
    }
    
    if (!moved) {
        state = CLOSING;
        openTimer = 0;
        printf("时间 %.1f 秒：电梯开始关门\n", simulationTime * TIME_UNIT);
    }
}

int findNextFloor() {
    for (int i = 0; i < 5; i++) {
        if (carCall[i]) return i;
    }
    
    if (dir >= 0) {
        for (int i = currentFloor + 1; i < 5; i++) {
            if (upCall[i] || downCall[i]) return i;
        }
    }
    
    if (dir <= 0) {
        for (int i = currentFloor - 1; i >= 0; i--) {
            if (upCall[i] || downCall[i]) return i;
        }
    }
    
    if (currentFloor > 0 && downCall[currentFloor]) return currentFloor;
    if (currentFloor < 4 && upCall[currentFloor]) return currentFloor;
    
    return 1;
}

void updateElevator() {
    int nextFloor;
    
    switch (state) {
        case OPENING:
            openTimer++;
            if (openTimer >= 20) {
                state = OPENED;
                openTimer = 0;
                printf("时间 %.1f 秒：电梯门已完全打开\n", simulationTime * TIME_UNIT);
            }
            break;
            
        case OPENED:
            handlePassMovement();
            break;
            
        case CLOSING:
            openTimer++;
            if (openTimer >= 20) {
                state = CLOSED;
                openTimer = 0;
                printf("时间 %.1f 秒：电梯门已完全关闭\n", simulationTime * TIME_UNIT);
            }
            break;
            
        case CLOSED:
            state = MOVING;
            moveTimer = 0;
            printf("时间 %.1f 秒：电梯开始移动\n", simulationTime * TIME_UNIT);
            break;
            
        case WAITING:
            waitTimer++;
            if (waitTimer >= 3000) {
                waitTimer = 0;
                if (currentFloor != 1) {
                    dir = (1 > currentFloor) ? 1 : -1;
                    state = MOVING;
                    moveTimer = 0;
                    printf("时间 %.1f 秒：电梯等待时间过长，开始返回本垒层(1层)\n", 
                           simulationTime * TIME_UNIT);
                }
            } else {
                nextFloor = findNextFloor();
                if (nextFloor != currentFloor) {
                    dir = (nextFloor > currentFloor) ? 1 : -1;
                    state = MOVING;
                    moveTimer = 0;
                    printf("时间 %.1f 秒：电梯开始移动，前往楼层 %d\n", 
                           simulationTime * TIME_UNIT, nextFloor);
                }
            }
            break;
            
        case MOVING:
            moveTimer++;
            if (moveTimer == 15) {
                printf("时间 %.1f 秒：电梯加速完成，开始匀速运动\n", 
                       simulationTime * TIME_UNIT);
            }
            
            nextFloor = findNextFloor();
            if ((dir > 0 && currentFloor + 1 == nextFloor) ||
                (dir < 0 && currentFloor - 1 == nextFloor)) {
                state = DECEL;
                printf("时间 %.1f 秒：电梯开始减速，准备到达楼层 %d\n", 
                       simulationTime * TIME_UNIT, nextFloor);
            }
            break;
            
        case DECEL:
            moveTimer++;
            if (moveTimer >= 30) {
                currentFloor += dir;
                moveTimer = 0;
                state = OPENING;
                openTimer = 0;
                printf("时间 %.1f 秒：电梯到达楼层 %d，开始开门\n", 
                       simulationTime * TIME_UNIT, currentFloor);
            }
            break;
    }
}

void printStatus() {
    printf("\n--- 时间 %.1f 秒时系统状态 ---\n", simulationTime * TIME_UNIT);
    printf("电梯：楼层 %d，状态 ", currentFloor);
    
    switch (state) {
        case OPENING: printf("正在开门"); break;
        case OPENED: printf("已开门"); break;
        case CLOSING: printf("正在关门"); break;
        case CLOSED: printf("已关门"); break;
        case WAITING: printf("等待"); break;
        case MOVING: printf("移动中"); break;
        case DECEL: printf("减速中"); break;
    }
    
    printf("，方向 ");
    if (dir > 0) printf("向上\n");
    else if (dir < 0) printf("向下\n");
    else printf("静止\n");
    
    printf("呼叫状态：\n");
    printf("  向上呼叫：");
    for (int i = 0; i < 4; i++) printf("%d ", upCall[i]);
    printf("\n");
    printf("  向下呼叫：");
    for (int i = 1; i < 5; i++) printf("%d ", downCall[i-1]);
    printf("\n");
    printf("  电梯内呼叫：");
    for (int i = 0; i < 5; i++) printf("%d ", carCall[i]);
    printf("\n");
    
    printf("各楼层等待人数：\n");
    for (int i = 0; i < 5; i++) {
        int upCount = 0, downCount = 0;
        QueueNode* node;
        
        node = upQ[i].front;
        while (node) {
            upCount++;
            node = node->next;
        }
        
        node = downQ[i].front;
        while (node) {
            downCount++;
            node = node->next;
        }
        
        printf("  楼层 %d：向上 %d 人，向下 %d 人\n", i, upCount, downCount);
    }
    
    printf("电梯内人数：");
    int totalInside = 0;
    for (int i = 0; i < 5; i++) {
        totalInside += carStack[i].top + 1;
    }
    printf("%d 人\n", totalInside);
    
    printf("已完成行程的乘客数：");
    int completed = 0;
    for (int i = 0; i < passCount; i++) {
        if (passengers[i].finished) completed++;
    }
    printf("%d 人\n", completed);
    
    printf("已放弃的乘客数：");
    int givenUp = 0;
    for (int i = 0; i < passCount; i++) {
        if (passengers[i].gaveUp) givenUp++;
    }
    printf("%d 人\n\n", givenUp);
}

int main() {
    srand(time(NULL));
    
    for (int i = 0; i < 4; i++) {
        initQueue(&upQ[i]);
        initQueue(&downQ[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        initStack(&carStack[i]);
    }
    
    printf("电梯模拟系统启动！\n");
    
    for (simulationTime = 0; simulationTime < 10000; simulationTime++) {
        if (rand() % 100 == 0) {
            addPassenger();
        }
        
        checkGiveUp();
        updateElevator();
        
        if (simulationTime % 500 == 0) {
            printStatus();
        }
    }
    
    printf("电梯模拟系统运行结束！\n");
    
    int totalGen = passCount;
    int totalComp = 0;
    int totalGiveUp = 0;
    int totalWaitTime = 0;
    int maxWaitTime = 0;
    
    for (int i = 0; i < passCount; i++) {
        if (passengers[i].finished) {
            totalComp++;
            int waitTime = (passengers[i].enter - passengers[i].arrive) * TIME_UNIT;
            totalWaitTime += waitTime;
            if (waitTime > maxWaitTime) maxWaitTime = waitTime;
        }
        if (passengers[i].gaveUp) {
            totalGiveUp++;
        }
    }
    
    printf("\n--- 模拟统计信息 ---\n");
    printf("总生成乘客数：%d\n", totalGen);
    printf("成功到达目的地乘客数：%d\n", totalComp);
    printf("放弃等待乘客数：%d\n", totalGiveUp);
    if (totalComp > 0) {
        printf("平均等待时间：%.1f 秒\n", (double)totalWaitTime / totalComp);
        printf("最长等待时间：%.1f 秒\n", (double)maxWaitTime);
    }
    
    return 0;
}    