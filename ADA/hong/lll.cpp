#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// 定义电梯状态
enum ElevatorState {
    Opening,
    Opened,
    Closing,
    Closed,
    Waiting,
    Moving,
    Decelerate
};

// 定义电梯的结构
struct Elevator {
    int currentFloor; // 当前楼层
    ElevatorState state; // 当前状态
    stack<int> EleStack[5]; // 电梯内的乘客栈，每个栈对应一个目标楼层
    queue<int> CallUp[4]; // 每层楼的上行按钮队列，地下层没有上行按钮
    queue<int> CallDown[5]; // 每层楼的下行按钮队列，第四层没有下行按钮
    bool CallCar[5]; // 电梯内的目标层按钮，数组元素为true表示有乘客要去该层
    int doorTimer; // 门打开或关闭的计时器
    int waitTimer; // 等待乘客进出的计时器
    int decelerateTimer; // 减速计时器
};

// 初始化电梯
void initializeElevator(Elevator& ele) {
    ele.currentFloor = 1; // 电梯初始在第一层
    ele.state = Closed; // 电梯初始状态为已关闭
    for (int i = 0; i < 5; ++i) {
        ele.CallCar[i] = false; // 初始化目标层按钮为false
    }
    ele.doorTimer = 0; // 初始化门计时器为0
    ele.waitTimer = 0; // 初始化等待计时器为0
    ele.decelerateTimer = 0; // 初始化减速计时器为0
}

// 模拟时钟推进
void tickClock(Elevator& ele, int& simClock) {
    ++simClock;
    if (ele.state == Opening || ele.state == Closing) {
        ele.doorTimer++;
    }
    if (ele.state == Waiting) {
        ele.waitTimer++;
    }
    if (ele.state == Decelerate) {
        ele.decelerateTimer++;
    }
}

// 显示当前系统状态
void displayState(Elevator& ele, int simClock) {
    cout << "模拟时钟: " << simClock << endl;
    cout << "电梯当前楼层: " << ele.currentFloor << endl;
    cout << "电梯状态: ";
    switch (ele.state) {
        case Opening: cout << "Opening"; break;
        case Opened: cout << "Opened"; break;
        case Closing: cout << "Closing"; break;
        case Closed: cout << "Closed"; break;
        case Waiting: cout << "Waiting"; break;
        case Moving: cout << "Moving"; break;
        case Decelerate: cout << "Decelerate"; break;
    }
    cout << endl;
    cout << "上行按钮队列: \n";
    for (int i = 0; i < 4; ++i) {
        cout << "楼层" << i << ": ";
        queue<int> tempQueue = ele.CallUp[i];
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
    cout << "下行按钮队列: \n";
    for (int i = 1; i < 5; ++i) {
        cout << "楼层" << i << ": ";
        queue<int> tempQueue = ele.CallDown[i];
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
    cout << "电梯内的乘客栈: \n";
    for (int i = 0; i < 5; ++i) {
        cout << "楼层" << i << ": ";
        stack<int> tempStack = ele.EleStack[i];
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
    cout << "目标层按钮: \n";
    for (int i = 0; i < 5; ++i) {
        cout << "楼层" << i << ": " << (ele.CallCar[i] ? "true" : "false") << endl;
    }
    cout << endl;
}

// 电梯状态转换
void changeState(Elevator& ele, ElevatorState newState, int& simClock) {
    ele.state = newState;
    ele.doorTimer = 0; // 重置门计时器
    ele.waitTimer = 0; // 重置等待计时器
    ele.decelerateTimer = 0; // 重置减速计时器
    displayState(ele, simClock);
}

// 处理电梯状态
void processElevator(Elevator& ele, int& simClock) {
    switch (ele.state) {
        case Opening:
            if (ele.doorTimer >= 20) {
                changeState(ele, Opened, simClock);
            }
            break;
        case Opened:
            if (ele.waitTimer >= 40) {
                changeState(ele, Closing, simClock);
            }
            break;
        case Closing:
            if (ele.doorTimer >= 20) {
                changeState(ele, Closed, simClock);
            }
            break;
        case Closed:
            if (ele.currentFloor == 1 && ele.CallCar[1] == false) {
                changeState(ele, Waiting, simClock);
            } else if (ele.currentFloor == 0 && !ele.CallUp[0].empty()) {
                changeState(ele, Opening, simClock);
            } else if (ele.currentFloor == 4 && !ele.CallDown[4].empty()) {
                changeState(ele, Opening, simClock);
            } else if (ele.currentFloor > 0 && ele.CallDown[ele.currentFloor].empty() && ele.CallUp[ele.currentFloor].empty()) {
                if (ele.currentFloor < 4 && ele.CallUp[ele.currentFloor].empty()) {
                    changeState(ele, Moving, simClock);
                } else if (ele.currentFloor > 0 && ele.CallDown[ele.currentFloor].empty()) {
                    changeState(ele, Moving, simClock);
                }
            }
            break;
        case Waiting:
            if (ele.waitTimer >= 300) {
                changeState(ele, Moving, simClock);
                ele.currentFloor = 1;
            }
            break;
        case Moving:
            if (ele.currentFloor < 4 && ele.CallUp[ele.currentFloor].empty()) {
                ele.currentFloor++;
            } else if (ele.currentFloor > 0 && ele.CallDown[ele.currentFloor].empty()) {
                ele.currentFloor--;
            }
            changeState(ele, Decelerate, simClock);
            break;
        case Decelerate:
            if (ele.decelerateTimer >= 15) {
                if (!ele.CallUp[ele.currentFloor].empty() || !ele.CallDown[ele.currentFloor].empty() || ele.CallCar[ele.currentFloor]) {
                    changeState(ele, Opening, simClock);
                } else {
                    changeState(ele, Closed, simClock);
                }
            }
            break;
    }
}

// 处理乘客进出
void processPassenger(Elevator& ele, int& simClock) {
    if (ele.state == Opened) {
        if (!ele.CallUp[ele.currentFloor].empty() || ele.CallCar[ele.currentFloor]) {
            int passenger = ele.CallUp[ele.currentFloor].front();
            ele.CallUp[ele.currentFloor].pop();
            ele.EleStack[passenger].push(passenger);
            ele.CallCar[passenger] = true;
            ele.waitTimer = 0; // 重置等待计时器
            simClock += 25; // 乘客进出需要25t
        } else if (!ele.CallDown[ele.currentFloor].empty() || ele.CallCar[ele.currentFloor]) {
            int passenger = ele.CallDown[ele.currentFloor].front();
            ele.CallDown[ele.currentFloor].pop();
            ele.EleStack[passenger].push(passenger);
            ele.CallCar[passenger] = true;
            ele.waitTimer = 0; // 重置等待计时器
            simClock += 25; // 乘客进出需要25t
        }
    }
}


// 模拟乘客随机进出
void simulatePassenger(Elevator& ele, int& simClock) {
    if (simClock % 100 == 0) { // 每100t随机生成一个乘客
        int floor = rand() % 5; // 随机选择楼层
        int direction = rand() % 2; // 随机选择方向（0为上，1为下）
        int targetFloor = rand() % 5; // 随机选择目标楼层

        if (direction == 0 && floor < 4) {
            ele.CallUp[floor].push(targetFloor);
            if (ele.currentFloor == floor && ele.state == Closed) {
                changeState(ele, Opening, simClock);
            }
        } else if (direction == 1 && floor > 0) {
            ele.CallDown[floor].push(targetFloor);
            if (ele.currentFloor == floor && ele.state == Closed) {
                changeState(ele, Opening, simClock);
            }
        }
    }
}

int main() {
    srand(time(0)); // 初始化随机数生成器
    Elevator ele;
    initializeElevator(ele);
    int simClock = 0;

    while (simClock < 1000) { // 模拟1000t
        simulatePassenger(ele, simClock);
        processPassenger(ele, simClock);
        processElevator(ele, simClock);
        tickClock(ele, simClock);
    }

    return 0;
}
