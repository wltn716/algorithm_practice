// 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/courses/30/lessons/85002
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Info {
    public:
        int num;
        double percent;
        int win_heavier_cnt;
        int weight;

        Info(int _num, double _percent, int _win_heavier_cnt, int _weight) {
            num = _num;
            percent = _percent;
            win_heavier_cnt = _win_heavier_cnt;
            weight = _weight;
        }
};

bool compare(Info i1, Info i2) {
    if(i1.percent == i2.percent) {
        if(i1.win_heavier_cnt == i2.win_heavier_cnt) {
            if(i1.weight == i2.weight) {
                return i1.num < i2.num;
            }
            return i1.weight > i2.weight;
        }
        return i1.win_heavier_cnt > i2.win_heavier_cnt;
    }
    return i1.percent > i2.percent;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    int n = weights.size();
    vector<int> answer;
    vector<Info> infos;

    for (int i = 0; i < n; i++){
        infos.push_back(Info(i+1, 0, 0, weights[i]));
        int j = 0;
        int k = 0;
        for (char h: head2head[i]){
            if(h == 'W') {
                infos[i].percent += 1.0;
                if(weights[j] > weights[i]) infos[i].win_heavier_cnt++;
            }

            if(h != 'N') k++;
            j++;
        }
        if(k > 0)
            infos[i].percent /= k;
        else infos[i].percent = 0.0;
    }
    
    stable_sort(infos.begin(), infos.end(), compare);

    for(Info info: infos) {
        answer.push_back(info.num);
    }
    
    return answer;
}