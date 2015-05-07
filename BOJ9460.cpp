/* 2015.04.14

http://www.acmicpc.net/problem/9460

 - INPUT : N( N <= 10,000), K, X, Y( -100,000,000 <= X, Y <= 100,000,000 )
 - OUTPUT : MINMUM IN MAXIMUM

 - SOLTION
	1. sort relative to X : O(N*logN)
	2. find possible soltion using bisection : O( log(MAX(Y) + |MIN(Y)|) * N )

 - TIME COMPLEXITY : O( log(MAX(Y) + |MIN(Y)|) * N )

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > metal;
int n, m;

bool possible(int mid){

	int count=1, minV, maxV;
	minV=maxV=metal[0].second;
	for(int i=1; i<n; i++){
		maxV=max(maxV, metal[i].second);
		minV=min(minV, metal[i].second);
		if( maxV - minV > mid ){
			count++;
			maxV=minV=metal[i].second;
		}
	}
	return m >= count;
}

void solve(){
	int start=0, end=200000000, mid, ret;
	while(start <= end){
		mid = (start+end)/2;
		if(possible(mid)){
			end=mid-1;
			ret=mid;
		}
		else{
			start=mid+1;
		}
	}
	
	printf("%0.1lf\n",ret*1.0/2 );
	return;
}

int main(){
	int t;
	freopen("input.txt", "r",stdin);
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		metal = vector<pair<int, int> >(n);
		for(int i=0; i<n; i++)
			scanf("%d %d", &metal[i].first, &metal[i].second);

		sort(metal.begin(), metal.end());
		solve();
	}
	return 0;
}
