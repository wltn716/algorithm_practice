// 문제: https://www.acmicpc.net/problem/10971
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N,m=0;
	scanf("%d",&N);
	int W[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			scanf("%d",&W[i][j]);
			m+=W[i][j];
		}

	int a[N];
	for(int i=0;i<N;i++)
		a[i]=i;

	do{
		int cost=0, temp=0;
		for(int i=0;i<N-1;i++){
			temp = W[a[i]][a[i+1]];
			if(temp)
				cost+=W[a[i]][a[i+1]];
			else break;
		}
		if(temp&&W[a[N-1]][a[0]])
			m = min(m,cost+W[a[N-1]][a[0]]);
	}while(next_permutation(a+1,a+N));

	printf("%d\n", m);	
	return 0;
		
}