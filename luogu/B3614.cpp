// 【模版】栈
#include <iostream>
#include <string>
using namespace std;
class mystack
{
    private:
        struct node{
            unsigned long long num;
            node *next;
            node():num(0),next(nullptr){}
            node(unsigned long long num):num(num),next(nullptr){}
            node(unsigned long long num,node *next):num(num),next(next){}
        };
        int length;
        node *head;
    public:
        mystack():head(nullptr),length(0){}
        bool empty();
        void push(unsigned long long x);
        void pop();
        void query();
        int size();
};
bool mystack::empty()
{
    return length == 0;
}
void mystack::pop()
{
    if(!empty())
    {
        node *tmp = head;
        head = head -> next;
        delete tmp;
        length --;
    }
    else
    {
        cout << "Empty" << endl;
        return ;
    }
}
void mystack::query()
{
    if(!empty())
    {
        cout << head -> num << endl;
    }
    else 
    {
        cout << "Anguei!" << endl;
    }
}
int mystack::size()
{
    return length;
}
void mystack::push(unsigned long long x)
{   
    node *tmp = new node(x,head);
    head = tmp;
    length ++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        mystack z;
        int n;
        cin >> n;
        while(n --)
        {
            string s;
            cin >> s;
            if(s == "push")
            {
                unsigned long long x;
                cin >> x;
                z.push(x);
            }
            else if(s == "pop")
            {
                z.pop();
            }
            else if(s == "query")
            {
                z.query();
            }
            else if(s == "size")
            {
                int tmp = z.size();
                cout << tmp << endl;
            }
        }
    }
    return 0;   
}