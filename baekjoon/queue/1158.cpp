// 문제: https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        q.push(i);
    }

    cout << "<";
    while(true){
        for(int i=0;i<k-1;i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();

        if(!q.empty()) {
            cout << ", ";
        }
        else{
            cout << ">" << "\n";
            break;
        }
    }
    

    return 0;
}