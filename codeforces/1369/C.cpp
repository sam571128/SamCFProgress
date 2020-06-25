#include <bits/stdc++.h> 

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	ll n,k;
	cin >> n >> k;
	ll arr[n];
	for(auto &x : arr) cin >> x;
	ll w[k];
	for(auto &x : w) cin >> x;
	sort(arr,arr+n);
	sort(w,w+k);
	ll fr = 0;
	ll ba = 0;
	ll sum = 0;
	for(ll i = 0;i < k;i++){
		if(w[i]>1) break;
		sum += arr[n-1-ba]*2;
		ba++;
	}	
	sort(w,w+k,greater<ll>());
	for(ll i = 0; i < k;i++){
		if(w[i]==1) break;
		sum += arr[fr];
		fr += w[i]-1;
		sum += arr[n-1-ba];
		ba++;
	}
	cout << sum << "\n";
}
 
int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}