// 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/courses/30/lessons/77486
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> answer;
map<string, int> idx_map;
vector<int> parent;

void setProfit(int man, int total) {
    if(parent[man] != man) {
        answer[man] += total;
        return;
    }   
    
    int remain = total/10;
    answer[man] += total-remain;
    
    if(remain > 0)
        setProfit(parent[man], remain);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int n = enroll.size();
    answer.resize(n, 0);
    
    for(int i=0; i < n; i++) {
        idx_map.insert({enroll[i], i});
    }

    for(int i=0; i < n; i++) {
        string r = referral[i];
        if(r == "-")
            parent.push_back(i);
        else 
            parent.push_back(idx_map[r]);
    }

    for(int i=0; i < seller.size(); i++) {
        setProfit(idx_map[seller[i]], amount[i]*100);
    }

    return answer;
}