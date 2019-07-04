//============================================================================
// Name        : roads.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];
long nodes;
long long cost;

void DFS(int n){
	nodes++;
	visited[n] = true;
	for(int i = 0; i < adj[n].size(); i++){
		if(!visited[adj[n][i]])
			DFS(adj[n][i]);
	}


}

int main() {
	int q;
	cin >> q;
	while(q--){
		int n, m, c_l, c_r;
		cin >> n >> m >> c_l >> c_r;
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i = 1; i <= n; i++){
			nodes = 0;
			if (!visited[i]){
				DFS(i);
				if(c_l > c_r)
					cost += c_l + c_r * (nodes - 1);
				else
					cost += c_l * (nodes);
			}
		}
		cout << cost << endl;
		nodes = 0;
		cost = 0;
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			visited[i] = false;
		}
	}

}
