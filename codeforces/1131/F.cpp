#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5;
int par[N];
vector<int> tmp[N];

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]); 
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(tmp[b].size()>tmp[a].size()) swap(a,b);
	for(int x : tmp[b]) tmp[a].push_back(x);
	par[b] = a;
}

int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i <= n;i++){
		par[i] = i;
		tmp[i].push_back(i);
	}
	for(int i = 0;i < n-1;i++){
		int u,v;
		cin >> u >> v;
		unite(u,v);
	}
	int tmp2 = find(1);
	for(int x : tmp[tmp2]) cout << x << " ";
}