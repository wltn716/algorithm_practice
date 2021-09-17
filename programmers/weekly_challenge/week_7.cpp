// 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/courses/30/lessons/86048
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution1(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    vector<int> room;
    int n = enter.size();
    answer.resize(n, 0);

    
    room.push_back(enter[0]);
    int ei = 1;

    for (int l: leave) {
        auto iter = find(room.begin(), room.end(), l);
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

// YunGoon님 풀이 참조
vector<int> solution2(vector<int> enter, vector<int> leave) {
    int n = enter.size();
    vector<int> answer(n, 0);
    
    vector<int> room;
    for(int i=0, j=0; i < n; i++) {
        answer[enter[i]-1] += room.size();
        for(int r: room) answer[r-1]++;
        
        room.push_back(enter[i]);
        vector<int>::iterator iter;
        while(j<n && (iter= find(room.begin(), room.end(), leave[j])) != room.end()){
            room.erase(iter); j++;
        }
    }
        
    return answer;
}

int main() {
    vector<int> enter = {1, 4, 2, 3};
    vector<int> leave = {2, 1, 3, 4};
    solution1(enter, leave);
    return 0;
}