#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define eb emplace_back
const int N = 1e5+10;
ll f[2][N];
bool machine[N];
vector<pii> con[N];
const ll inf = 1e18;
ll totalTime = 0;
inline int maxBranch(vector <int> branches){
	int max = 0;
	for(int i = 0; i < branches.size(); i++){
		if(branches[i] == -1)
			continue;
		if(max < branches[i]){
			totalTime += max;
			max = branches[i];
		}else{
			totalTime += branches[i];
		}
	}
	if(max)
		return max;
	return -1;
}
inline int sumBranches(vector <int> branches){
	int max = 0;
	for(int i = 0; i < branches.size(); i++){
		if(branches[i] == -1)
			continue;
		max += branches[i];
	}
	return max;
}
int dfs(int s, int p, int dist){
//	cout << "dfs(" << s << ", " << p << ", " << dist << ")" << endl;
 	vector<int> branches;
	for(auto it: con[s]){
		if(it.F == p)
			continue;
		branches.push_back(dfs(it.F, s, it.S));
	}
	if(branches.size() == 0){
		if(machine[s]){
			return dist;
		}else{
			return -1;
		}
	}else{
		if(machine[s]){
			totalTime+= sumBranches(branches);
			return dist;
		}
		return min(maxBranch(branches), dist);
	}
}
int main(){
	int n, k, u, v, w;
	cin >> 	n >> k;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v >> w;
		con[u].eb(mp(v,w));
		con[v].eb(mp(u,w));
	}
	int rt = -1;
	for(int i  = 0; i < k; i++){
		int node;
		cin >> node;
		machine[node] = 1;
		rt = node;
	}
	dfs(rt, -1, 0);
	cout << totalTime << endl;
}
