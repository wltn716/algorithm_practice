// 문제: https://www.acmicpc.net/problem/12100
#include <iostream>
#include <cstring>
#define MAX 20
#define U 0
#define R 1
#define D 2
#define L 3

using namespace std;

int board[MAX][MAX];

int ans = -1;
int n;

void up (int brd[][MAX]) {
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 1; j < n; j++) {
            if(brd[x][i] != brd[j][i]) {
                if(brd[x][i] > 0 && brd[j][i] > 0) x++;
                if(brd[j][i] > 0) {
                    brd[x][i] = brd[j][i];
                    if(j != x) brd[j][i] = 0;
                }    
                ans = max(ans, brd[x][i]);
            }
            else { 
                brd[x][i] *= 2;
                ans = max(ans, brd[x][i]);
                if(brd[x][i] > 0) x++;
                brd[j][i] = 0;
            }
        }
    }
}

void right (int brd[][MAX]) {
    for (int i = n-1; i > -1; i--) {
        int y = n-1;
        for (int j = n-2; j > -1; j--) {
            if(brd[i][y] != brd[i][j]) {
                if(brd[i][y] > 0 && brd[i][j]) y--;
                if(brd[i][j] > 0) {
                    brd[i][y] = brd[i][j]; 
                    if(j != y) brd[i][j] = 0;
                }    
                ans = max(ans, brd[i][y]);
            }
            else { 
                brd[i][y] *= 2;
                ans = max(ans, brd[i][y]);
                if(brd[i][y] > 0) y--;
                brd[i][j] = 0;
            }            
        }
    }
}

void down (int brd[][MAX]) {
    for (int i = n-1; i > -1 ; i--) {
        int x = n-1;
        for (int j = n-2; j > -1; j--) {
            if(brd[x][i] != brd[j][i]) {
                if(brd[x][i] > 0 && brd[j][i] > 0) x--;
                if(brd[j][i] > 0) {
                    brd[x][i] = brd[j][i]; 
                    if(j != x) brd[j][i] = 0;
                }    
                ans = max(ans, brd[x][i]);
            }
            else {
                brd[x][i] *= 2;
                ans = max(ans, brd[x][i]);
                if(brd[x][i] > 0) x--;
                brd[j][i] = 0;
            }

            
        }
    }
}

void left(int brd[][MAX]) {
    for (int i = 0; i < n; i++) {
        int y = 0;
        for (int j = 1; j < n; j++) {
            if(brd[i][y] != brd[i][j]) {
                if(brd[i][y] > 0 && brd[i][j]) y++;
                if(brd[i][j] > 0) {
                    brd[i][y] = brd[i][j]; 
                    if(j != y) brd[i][j] = 0;
                }    
                ans = max(ans, brd[i][y]);
            }
            else { 
                brd[i][y] *= 2;
                ans = max(ans, brd[i][y]);
                if(brd[i][y] > 0) y++;
                brd[i][j] = 0;
            }
        }
    }
}

void bf(int cnt, int brd[][MAX]) {
    if(cnt == 5) return;

    for (int i = 0; i < 4; i++) {
        int tmp_brd[MAX][MAX];
        memcpy(tmp_brd, brd, sizeof(tmp_brd));

        switch (i) {        
            case U:
                up(tmp_brd);
                break;
            case R:
                right(tmp_brd);
                break;
            case D:
                down(tmp_brd);
                break;
            case L:
                left(tmp_brd);
                break;        
        }

        bf(cnt+1, tmp_brd);
    }    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    memset(board, 0, sizeof(board));

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(n==1) {
                cout << board[i][j] << "\n"; 
                return 0;
            }    
        }
    }

    bf(0, board);
    cout << ans << "\n";

    return 0;
} 