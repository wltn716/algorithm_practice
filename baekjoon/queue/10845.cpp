// 문제: https://www.acmicpc.net/problem/10845
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string ins;
        cin >> ins;

        int n;

        if(ins == "push"){
            cin >> n;
            q.push(n);
        }
        else if(ins == "size"){
            cout << q.size() << "\n";
        }
        else if(ins == "empty") {
            cout << q.empty() << "\n";
        }
        else{
            if(q.empty()) n = -1;
            else{
                if(ins == "back") {
                    n = q.back();
                }
                else {
                    n = q.front();
                    if(ins == "pop") q.pop();
                }
            }
            cout << n << "\n";
        }
    }
    
    return 0;
}