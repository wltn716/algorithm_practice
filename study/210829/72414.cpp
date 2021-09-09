//출처: 프로그래머스 코딩테스트 연습, https://programmers.co.kr/learn/courses/30/lessons/72414
//풀이 참조: https://yjyoon-dev.github.io/kakao/2021/01/29/kakao-insertad
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 360000

using namespace std;

int ad[MAX] = {0};

int toSec(string str) {
    int h, m, s;
    h = stoi(str.substr(0,2));
    m = stoi(str.substr(3,2));
    s = stoi(str.substr(6));

    return ((h*60) + m)*60 + s;
}

string zeroFill (int sec) {
    return (sec < 10 ? "0" : "")+ to_string(sec);
}

string toStr(int sec) {
    string str = "";

    if(!sec) return "00:00:00";

    for(int i = 0; i < 2; i++){
        int t = sec%60;
        str = ":" + zeroFill(t) + str;
        sec = sec/60;
    }

    return zeroFill(sec) + str;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int n = toSec(play_time);
    int m = toSec(adv_time);

    for(string log : logs) {
        int start = toSec(log.substr(0,8));
        int end =  toSec(log.substr(9));

        for (int i = start; i <= end; i++){
            ad[i]++;
        }
    }

    int total = 0;
    int ans = 0;

    for (int i = 0; i <= m; i++){
        total+=ad[i];
    }

    for (int i = m+1; i <= n; i++){
        int tmp = total + ad[i] - ad[i-(m+1)];
        if(total < tmp) {
            cout << total
            ans = i-m;
            total = tmp;
        }   
    }

    return toStr(ans);
}