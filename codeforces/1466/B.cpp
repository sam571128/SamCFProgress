#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,int> m;
	int cnt = 0;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		if(!m[tmp]){
			cnt++, m[tmp]++;
		}else if(!m[tmp+1]){
			cnt++, m[tmp+1]++;
		}
	}
	cout << cnt << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}