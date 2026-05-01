// 堆栈计算机
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int origin_n = n;
    stack<string>reverse_result;
    while(n > 1)
    {
        if(n % 2 == 0)
        {
            reverse_result.push("add");
            reverse_result.push("dup");
            n /= 2;
        }
        else
        {
            reverse_result.push("add");
            reverse_result.push("1");
            reverse_result.push("add");
            reverse_result.push("dup");
            n = (n - 1) / 2;
        }
    }

    cout << 1 << '\n';
    if(origin_n > 1)
    {
        cout << 1 << '\n';
        cout << "add" << '\n';
        if(!reverse_result.empty()) reverse_result.pop(); 
        if(!reverse_result.empty()) reverse_result.pop(); 
    }
    while(!reverse_result.empty())
    {
        cout << reverse_result.top() << '\n';
        reverse_result.pop();
    }

    return 0;   
}