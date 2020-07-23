#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,s,k;
	cin >> n >> s >> k;
	unordered_map<int,int> m;
	for(int i = 0,tmp;i < k;i++) cin >> tmp,m[tmp]++;
	for(int i = 0;i < n;i++){
		if(s-i>0&&!m[s-i]){
			cout << i << "\n";
			return; 
		}else if(s+i<=n&&!m[s+i]){
			cout << i << "\n";
			return;
		}
	}
	
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}