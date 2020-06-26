#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int pref[n];
	memset(pref, 0 , sizeof pref);
	for(int i = 1;i < n;i++){
		pref[i] = pref[i-1];
		if(i==n-1) break;
		if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) pref[i]++;
	}
	int ans = 0;
	int ind = -1;
	//for(auto x : pref) cout << x << " ";
	for(int i = 0;i < n-k+1;i++){
		if(pref[i+k-2]-pref[i]+1 > ans){
			//cout << i+k-2 << " " << i << "\n";
 			ans = max(ans,pref[i+k-2]-pref[i]+1);
			ind = i+1;
		}
	}
	cout << ans << " " << ind << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}