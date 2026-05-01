#include "simulate_serve.h"
int main(){
    simulator sim;
    std::cout << "平均等待时间:" << sim.avgWaitTime() << std::endl;
    return 0;
}