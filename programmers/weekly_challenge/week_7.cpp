// 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/courses/30/lessons/86048
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    vector<int> room;
    int n = enter.size();
    answer.resize(n, 0);

    
    room.push_back(enter[0]);
    int ei = 1;

    for (int l: leave) {
        vector<int>::iterator iter = find(room.begin(), room.end(), l);
        while(iter == room.end() && ei < n) {
            room.push_back(enter[ei]);
            ei++;
            iter = find(room.begin(), room.end(), l);
        }
        
        int m = room.size();
        for(int i =0; i < m;i++) {
            int r = room[i];
            if(r != l){
                answer[r-1]++;
            }    
            else {
                answer[r-1] += m-1;
            }
        }
        room.erase(iter);
    }
        
    return answer;
}

int main() {
    vector<int> enter = {1, 4, 2, 3};
    vector<int> leave = {2, 1, 3, 4};
    solution(enter, leave);
    return 0;
}