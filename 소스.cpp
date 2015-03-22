#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

//binary search

vector<pair<string, int> > input;
vector<vector<int> > adj;
bool visit[100001];
int n, m, start, goal;

bool solve(){
	for(int i=0; i<=n; i++) visit[i]=false;
	vector<int> path(n+1, -1);
	queue<int> q;
	visit[start]=true;

	
	for(int i=0; i<adj[start].size(); i++){
		int there=adj[start][i];
		path[there]=start;
		visit[there]=true;
		q.push(there);
	}

	while(!q.empty()){
		int here=q.front();
		q.pop();
		if(here==goal){
			vector<int> t; t.push_back(here);
			while(path[here]!=-1){
				t.push_back(path[here]);
				here=path[here];
			}
			for(int i=t.size()-1; i>=0; i--)
				cout<<t[i]<<" ";
			cout<<endl;
			return true;
		}
		for(int i=0; i<adj[here].size(); i++){
			int there=adj[here][i];
			if(!visit[there]){
				path[there]=here;
				visit[there]=true;
				q.push(there);
			}
		}
	}
	return false;
}
int main(){

	freopen("input.txt", "r", stdin);
	int p;
	cin>>n>>m;
	input=vector<pair<string, int> >(n);
	adj=vector<vector<int> >(n+1);

	for(int i=0; i<n; i++){
		cin>>input[i].first;
		input[i].second=i+1;
	}

	sort(input.begin(), input.end());

	for(int i=0; i<n; i++){
		string here=input[i].first;

		for(int j=0; j<m; j++){
			if(here[j]=='0'){
				string there=here;
				there[j]='1';
				vector<pair<string, int> >::iterator low;
				low=lower_bound(input.begin(), input.end(), make_pair(there,0));
				int index=low-input.begin();

				if(index>=n) continue;
				if(input[index].first==there){
					adj[input[index].second].push_back(input[i].second);
					adj[input[i].second].push_back(input[index].second);
				}
			}
		}
	}
	cin>>p;
	start=1;
	for(int i=0; i<p; i++){
		cin>>goal;
	
		if(!solve()) cout<<"-1"<<endl;
	}
	return 0;
}

