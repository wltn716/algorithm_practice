// 문제: https://www.acmicpc.net/problem/10866
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> dq;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        int num;
        string ins;
        cin >> ins;
        
        if(ins == "size"){
            cout << dq.size() << "\n";
        }
        else if(ins == "empty"){
            cout << dq.empty() << "\n";
        }
        else if(ins.substr(0,4) == "push"){
            cin >> num;
            if(ins.substr(5) == "front") dq.push_front(num);
            else dq.push_back(num);
        }
        else {
            if(dq.empty()) num = -1;
            else{
                if(ins.find("front") != string::npos){
                    num = dq.front();
                    if(ins.substr(0,3) == "pop") dq.pop_front();
                }
                else {
                    num = dq.back();
                    if(ins.substr(0,3) == "pop") dq.pop_back();
                }
            }

            cout << num << "\n";
        }
        
    }
    
    return 0;
}