// 문제: https://www.acmicpc.net/problem/10820
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (getline(cin, str)){
        int a = 0, A = 0, num = 0, space = 0;
        for(char c: str){
            if(c == ' '){
                space++;
            }
            else if(c >= 'a'){
                a++;
            }
            else if(c >= 'A'){
                A++;
            }
            else{
                num++;
            }
        }

        cout << a << " " << A << " " << num << " " << space << endl;
    }

    return 0;
}