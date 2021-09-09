#include <string>
#include <vector>

using namespace std;

int postfix(string keyword, string w, int n) {
    return w.rfind(keyword) == n;
}

int prefix(string keyword, string w) {
    return w.rfind(keyword, 0) == 0;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for(string q: queries) {
        int a = 0, st = 0, ed = 0;
        bool flag = true;
        string keyword;
        if(q.at(0) == '?') {
            st = q.find_last_of('?');
            keyword = q.substr(st+1);
        }
        else {
            flag = false;
            ed = q.find_first_of('?');
            keyword = q.substr(0, ed);
        }

        for(string w: words) {
            if(q.length() == w.length()) {
                if(flag) a+= postfix(keyword, w, st+1);
                else a+= prefix(keyword, w);
            }
        }

        answer.push_back(a);
    }

    return answer;
}