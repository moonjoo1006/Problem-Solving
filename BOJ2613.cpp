#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ret;
vector<int> beads;

bool possible(int v){
	int sum=0, count=1;
	for(int i=0; i<n; i++){
		sum+=beads[i];
		if(sum > v){
			sum=beads[i];
			count++;
		}
	}
	return count>m;
}

void solve(){
	int start=0, end=30000,mid;
	while(start <= end){
		mid=(start+end)/2;
		if(possible(mid)){			
			start=mid+1;
		}
		else{
			end=mid-1;
			ret=mid;
		}
	}
	printf("%d\n", ret);
	int sum=0; start=0;
	for(int i=0; i<n; i++){
		sum+=beads[i];
		if(sum>ret){
			sum=beads[i];
			printf("%d ", i-start);
			start=i;
		}
	}
	printf("%d\n", n-start);
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	beads=vector<int>(n);
	for(int i=0; i<n; i++) scanf("%d", &beads[i]);
	solve();
	return 0;
}