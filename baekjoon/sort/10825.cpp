// 문제: https://www.acmicpc.net/problem/10825
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Student {
    public:
        int korean;
        int english;
        int math;
        string name;
        
        Student(int _korean, int _english, int _math, string _name) {
            korean = _korean;
            english = _english;
            math = _math;
            name = _name;
        }
};

bool compare(Student s1, Student s2) {
    if(s1.korean == s2.korean){
        if(s1.english == s2.english){
            if(s1.math == s2.math){
                return s1.name < s2.name;
            }
            return s1.math > s2.math;
        }
        return s1.english < s2.english;
    }

    return s1.korean > s2.korean;
}

int main() {
    int n;
    vector<Student> v;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int a,b,c;
        string d;
        cin >> d >> a >> b >> c;
        v.push_back(Student(a,b,c,d));
    }

    stable_sort(v.begin(), v.end(), compare);
    
    for(Student s : v) {
        cout << s.name << "\n";
    }

    return 0;
}

