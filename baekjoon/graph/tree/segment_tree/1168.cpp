// 문제: https://www.acmicpc.net/problem/1168
// 답안 출처+참고: https://www.crocus.co.kr/648
//              https://cocoon1787.tistory.com/433      
//              https://suri78.tistory.com/274
#include <iostream>
#define MAX 400000

using namespace std;

int seg_tree[MAX];
int n,k;

int init (int node, int st, int ed) {
    if(st == ed) {
        return seg_tree[node] = 1; //arr[st]
    }
    int mid = (st+ed)/2;
    
    return seg_tree[node] = init(node*2, st, mid)+init(node*2+1, mid+1, ed);
}

int update (int node, int st, int ed, int idx) {
    seg_tree[node]--;
    if(st==ed) return 0;
    else{
        int mid = (st+ed)/2;
        if(idx <= mid) return update(node*2, st, mid, idx);
        else return update(node*2+1, mid+1, ed, idx);
    }
}

int query (int node, int st, int ed, int order) {
    if(st == ed) return st;
    int mid = (st+ed)/2;

    if(order <= seg_tree[node*2]) return query(node*2, st, mid, order);
    else return query(node*2+1, mid+1, ed, order-seg_tree[node*2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    init(1, 1, n);

    int idx = 1;

    cout << "<";

    for (int i = 0; i < n; i++){
        int size = n-i;
        idx += k-1;
        
        if(idx%size == 0) idx = size;
        else if(idx>size) idx %= size;

        int num = query(1, 1, n, idx);

        update(1, 1, n, num);

        cout << num;
        if(i!=n-1) cout << ", ";
    }

    cout << ">\n";
    

    return 0;
}