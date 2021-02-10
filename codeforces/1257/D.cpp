#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n], en[n+1] = {};
	for(auto &x : arr) cin >> x;
	int m;
	cin >> m;
	for(int i = 0;i < m;i++){
		int p,s;
		cin >> p >> s;
		en[s] = max(en[s],p);
	}
	for(int i = n-1;~i;i--) en[i] = max(en[i],en[i+1]);
	int now = 0, ans = 0;
	while(now < n){
		ans++;
		
		int used = 0, p = arr[now];
		while(p <= en[used+1] && now < n){
			used++ , now++;
			if(now < n) p = max(p,arr[now]);
		}
		if(!used){
			break;
		}
	}
	cout << (now < n ? -1 : ans) << "\n";
}

signed main(){
	//fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}