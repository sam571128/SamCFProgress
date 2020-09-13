#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n], arr2[n], cnt1[n+1] = {}, cnt2[n+1] = {};
	for(auto &x : arr){
		cin >> x;	
		cnt1[x]++;
	}
	for(auto &x : arr2){
		cin >> x;
		cnt2[x]++;
	}
	for(int i = 0;i <= n;i++){
		if(cnt1[i]+cnt2[i]>n){
			cout << "No\n";
			return;
		}
	}
	reverse(arr2,arr2+n);
	int l = 1e18, r = -1;
	for(int i = 0; i < n;i++){
		if(arr[i]==arr2[i]){
			l = min(l,i);
			r = i;
		}
	}
	for(int i = l; i <= r;i++){
		swap(arr2[i],arr2[(i+n/2)%n]);
	}
	cout << "Yes\n";
	for(auto x : arr2) cout << x << " ";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}