#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int g = 0, mi = INT_MAX;
	int arr[n+1] = {};
	int ans[n+1] = {};
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		mi = min(mi,tmp);
		ans[tmp] = max(ans[tmp],(arr[tmp]+g + (ans[tmp]==0 ? 1 : 0)));
		arr[tmp] = -i;
		g++;
	}
	vector<int> pr(n+2,1e9+7);
	for(int i = 1;i <= n;i++){
		//cout << i << " " << ans[i] << "\n";
		ans[i] = max(ans[i],arr[i]+g);
		pr[ans[i]] = min(i,pr[ans[i]]);
	}
	pr[n] = mi;
	for(int i = 1;i <= n;i++){
		pr[i+1] = min(pr[i+1],pr[i]);
	}
	for(int i = 1;i <= n;i++){
		if(pr[i]==1e9+7) cout << -1 << " ";
		else cout << pr[i] << " "; 
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}