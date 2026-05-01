#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct node
{
    int num;
    int index;
    node(int num,int index):num(num),index(index){}
};
int main(){
    int n;
    cin >> n;
    node *box [n + 1];
    for(int i = 1;i <= n;i++)
    {
        int num;
        cin >> num;
        box[i] = new node (num,i);
    }
    //cout << 1 << endl;
    vector<int> result(n + 1);
    stack<node> num;
    for(int i = n;i >= 1;i--)
    {
        //if(num.empty()) cout << 7 << endl;
        //else cout << 8 << endl;
        while(!num.empty() and num.top().num <= box[i]->num)
        {
            num.pop();
            //cout << 6 << endl;
        }
        //cout << 2 << endl;
        if(num.empty())
        {
            //cout << 4 << endl;
            result[i] = 0;
            //cout << 3 << endl;
        }
        else 
        {
            result[i]= num.top().index;
            //cout << 4 << endl;
        }
        num.push(*box[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}