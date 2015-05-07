/* 2015.05.03

http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251

 - INPUT : N( N <= 100 )
 - OUTPUT : COUNTING CUT VERTEX

 - SOLTION
	1. MAKE DFS SPANNING TREE USING DFS ( JUST USE DFS ONCE )
	2. COUNTING CUT VERTEX

 - TIME COMPLEXITY : O( M + N )

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

vector< vector<int> > adj;
vector<int> discovered;
vector<bool> isCutVertex;
vector<pair<int, int> >answer;

int counter=0;
int findCutVertex(int here, bool isRoot){

	discovered[here]=counter++;
	int ret=discovered[here];

	
	for(int i=0; i<adj[here].size(); i++){
		int there=adj[here][i];
		if(discovered[there]==-1){
			int subtree=findCutVertex(there, false);

			if(!isRoot && subtree > discovered[here]){
				answer.push_back(make_pair(here, there));
			}
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}
	if(isRoot){
		for(int i=0; i<adj[here].size(); i++){
			int there=adj[here][i];
			answer.push_back(make_pair(here, there));
		}
	}
	return ret;
}

int main(){
	freopen("input.txt", "r", stdin);

	int n,m,a,b,c=1;
	char input[301];
	while(1){
		cin >> n >> m;
		if(n ==0 && m == 0 ) break;
		adj = vector<vector <int> >(n+1);
		discovered = vector<int>(n+1, -1);
		isCutVertex = vector<bool>(n+1, false);
		for(int i=0; i<m; i++){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		findCutVertex(1, true);
		cout<<c<<endl<<endl;
		for(int i=0; i<answer.size(); i++){
			cout<<answer[i].first<<" "<<answer[i].second<<endl;
		}
		cout<<"#"<<endl;
		answer.clear();
	}
	return 0;
}