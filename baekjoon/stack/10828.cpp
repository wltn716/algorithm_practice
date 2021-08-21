// 문제: https://www.acmicpc.net/problem/10828
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;    
    stack<int> s;

    for (int i = 0; i < n; i++){
        string ins;
        int num;
        cin >> ins;

        if(ins == "push"){
            cin >> num;
            s.push(num);
        }
        else if(ins == "size"){
            cout << s.size() <<"\n";
        }
        else if(ins == "empty"){
            cout << s.empty() << "\n";
        }
        else {
            if(!s.empty()){
                num = s.top();
                if(ins == "pop") s.pop();
            }
            else num = -1;
            cout << num <<"\n";
        }

    }
    
    return 0;
}