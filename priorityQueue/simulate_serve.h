#ifndef SIMULATE_SERVE_H
#define SIMULATE_SERVE_H
#include <iostream>
#include "../Queue/linkQueue.h"
#include "priorityQueue.h"
class simulator
{
    private:
        int noOfServer; // 服务台个数
        int arrivalLow; //到达间隔时间的下界
        int arrivalHigh; //到达间隔时间的上界
        int serviceTimeLow; //服务间隔时间的下界
        int serviceTimeHigh; //服务间隔时间的上界
        int customNum; // 模拟的顾客数

        struct eventT
        {
            int time; // 事件发生时间
            int type; //0为到达，1为离开
            bool operator<(const eventT &e) const
            {
                if (time != e.time) return time < e.time;
                return type > e.type;
            }
        };
    public:
        simulator();
        int avgWaitTime();
};

simulator::simulator()
{
    std::cout << "please input the number of counters";
    std::cin >> noOfServer;
    std::cout << "Enter the arrival time interval bounds (min interval, max interval): ";
    std::cin >> arrivalLow >> arrivalHigh;
    std::cout << "Enter the service time bounds (min service time, max service time):";
    std::cin >> serviceTimeLow >> serviceTimeHigh;
    std::cout << "Enter the numbers of customers";
    std::cin >> customNum;

    srand(time(nullptr));
}

int simulator::avgWaitTime()
{
    int serverBusy = 0;
    int currentTime;
    int totalWaitTime = 0;
    linkQueue<eventT> waitQueue;
    priorityQueue<eventT>eventQueue;

    eventT currentEvent;

    int i;
    currentEvent.time = 0;
    currentEvent.type = 0;
    for(i = 0;i < customNum;i++)
    {
        currentEvent.time += arrivalLow + (arrivalHigh - arrivalLow + 1) * (rand() / (RAND_MAX + 1.0));
        eventQueue.enQueue(currentEvent);
    }

    while(!eventQueue.isEmpty())
    {
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch (currentEvent.type)
        {
        case 0:
            if(serverBusy < noOfServer)
            {
                ++serverBusy;
                currentEvent.time += serviceTimeLow + (serviceTimeHigh - serviceTimeLow + 1) * (rand() / (RAND_MAX + 1.0));
                currentEvent.type = 1;
                eventQueue.enQueue(currentEvent);  
            }
            else waitQueue.enqueue(currentEvent);
            break;
        case 1:
            if(!waitQueue.isempty())
            {
                currentEvent = waitQueue.dequeue();
                totalWaitTime += currentTime - currentEvent.time;
                currentEvent.time = currentTime + serviceTimeLow + (serviceTimeHigh - serviceTimeLow + 1) * (rand() / (RAND_MAX + 1.0));
                currentEvent.type = 1;
                eventQueue.enQueue(currentEvent);
            }
            else --serverBusy;
            break;
        default:
            break;
        }
    }

    return totalWaitTime / customNum;
}
#endif