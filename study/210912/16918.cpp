// 문제: https://www.acmicpc.net/problem/16918
#include <iostream>
#include <queue>
#define MAX 202
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c, n;
char board[MAX][MAX];

void setting(int k) {
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(board[i][j] == '.') {
                board[i][j] = '0' + k; // O, 2, 0
            }    
        }       
    }    
}

void explode(int k) {
    queue<pair<int,int>> q;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(board[i][j] == '0' + k || board[i][j] == 'O')  {
                board[i][j] = '.';
                q.push({i, j});
            }    
        }       
    }    

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx >= 0 && ny >= 0 && nx < r && ny <c) {
                board[nx][ny] = '.';
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> n;

    for (int i = 0; i < r; i++) {
        cin >> board[i]; 
    }

    for (int i = 2; i <= n; i++){
        if(i%2) { //폭탄 폭파
            explode((i-3)%4);
        }
        else { //폭탄 설치
            setting(i%4);
        }
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            board[i][j] = board[i][j] != '.' ? 'O' : '.';
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}