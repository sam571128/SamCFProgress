#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
bool visited[100005];
vi adj[100005];
void initialize(int n){
	for(int i = 0;i < n;i++){
		visited[i] = false;
	}
}

void dfs(int n){
	visited[n] = true;
	for(int i = 0;i < adj[n].size();i++){
		if(!visited[adj[n][i]]&&adj[n][i]>n)
			dfs(adj[n][i]);
	}
}

int main(){
	fastio
	int a,b;
	cin >> a >> b;
	initialize(a);
	a--;
	int num = 1;
	while(a--){
		int temp;
		cin >> temp;
		adj[num].push(num+temp);
		adj[num+temp].push(num);
		num++;
	}
	dfs(1);
	if(!visited[b]){
		cout << "NO" << "\n";
	}else{
		cout << "YES" << "\n";
	}
}
