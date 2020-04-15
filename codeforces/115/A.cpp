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
int superior[100000];
int visited[100000];
int ans = 0;
void dfs(int i, int h){
	visited[i] = 1;
	if(superior[i]==-1){
		ans = max(h,ans);
		return;
	}
	dfs(superior[i],h+1);
}
int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> superior[i];
	}
	for(int i = 1;i <= n;i++){
		if(!visited[i])
			dfs(i,1);
	}
	cout << ans;
}
