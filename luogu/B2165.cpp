//括号匹配
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        stack<char> left;
        bool ok = true;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                left.push(ch);
            } else {
                if (left.empty()) {
                    ok = false;
                    break;
                }

                char top = left.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    left.pop();
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if (!left.empty()) {
            ok = false;
        }

        if (!ok) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }

   
    return 0;
}