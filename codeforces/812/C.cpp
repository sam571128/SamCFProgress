#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll N = 1e5+5;
ll arr[N],pref[N];
ll n,s;
ll sum(ll k){
	for(ll i = 0;i < n;i++){
		pref[i] = arr[i] + (i+1)*k;
	}
	sort(pref,pref+n);
	ll res = 0;
	for(ll i = 0;i < k;i++){
		res += pref[i];
	}
	return res;
}

signed main(){
	fastio
	cin >> n >> s;
	for(ll i = 0;i < n;i++) cin >> arr[i];
	ll l = 0, r = n;
	while(l < r){
		ll mid = (l+r)/2;
		if(sum(mid) <= s) l = mid+1;
		else r = mid-1;
	}
	if(sum(l)>s) l--;
	cout << l << " " << sum(l) << "\n";
}