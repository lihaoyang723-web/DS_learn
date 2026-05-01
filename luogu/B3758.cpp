//括号序列
// need to rewrite
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string result;
    int balance = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            result.push_back('(');
            ++balance;
        }
        else
        {
            if (balance == 0)
            {
                result.push_back('(');
                ++balance;
            }
            result.push_back(')');
            --balance;
        }
    }
    while (balance > 0)
    {
        result.push_back(')');
        --balance;
    }

    cout << result << endl;
    return 0;
}