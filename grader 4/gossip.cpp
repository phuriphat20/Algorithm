#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void BFS(int a, vector<int> adj[], int n){
	vector<int> day(n, -1);
	vector<bool> discovered(n, false);
	vector<int> ans(n, 0);
	int u,v;
	queue<int> q;
	q.push(a);
	day[a] = 0;
	discovered[a] = true;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = 0 ; i < adj[u].size(); i++){
			v = adj[u][i];
			if(!discovered[v]){
				discovered[v] = true;
				q.push(v);
				day[v] = day[u] + 1;
				ans[day[v]]++;
			}	
		}
	}
	int max1, max2;
	max1 = *max_element(ans.begin(), ans.end());
	max2 = max_element(ans.begin(),ans.end()) - ans.begin();
	cout << max1 << " " << max2 << endl;
}
int main(){
	int n;
	cin >> n;
	int k;
	vector<int> adj[n];
	for(int i = 0; i < n; i++){
		cin >> k;
		adj[i].resize(k);
		for(int j = 0; j < k; j++){
			cin >> adj[i][j];
		}
	}
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int r;
		cin >> r;
		if(adj[r].size() <= 0){
			cout << 0 << endl;
		}else{
			BFS(r, adj, n);
		}
	}
}