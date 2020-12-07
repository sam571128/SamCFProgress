#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int cnt = 0, ma = 0;
	int m[n+1] = {}, cnt1[n+1] = {};
	int lst = -1;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		cnt1[tmp]++;
		if(i==0||i==n-1) m[tmp]++;
		if(tmp==lst) cnt++, m[tmp]++, m[lst]++;
		lst = tmp;
	}
	if(*max_element(cnt1,cnt1+n+1) > (n+1)/2){
		cout << -1 << "\n";
		return;
	}
	cout << cnt+max((int)0,*max_element(m,m+n+1)-(cnt+2)) << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}