#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a[4];
	for(auto &x : a) cin >> x;
	int tmp = a[0], even = 0, odd = 0;
	for(int i = 0;i < 3;i++){
		tmp = min(a[i],tmp);
		if(a[i]&1) odd++;
		else even++;
	}
	if(a[3]&1) odd++;
	else even++;
	//cout << even << " " << odd << "\n";
	if(tmp==0){
		if(odd <= 1){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
		return;
	}
	if(odd>=3||odd<=1){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}