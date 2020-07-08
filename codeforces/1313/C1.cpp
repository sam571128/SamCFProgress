#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int main(){
	fastio
	ll n;
	cin >> n;
	ll m[n], ans = 0, ind = -1;
	for(auto &x : m) cin >> x;
	for(ll i = 0;i < n;i++){
		ll x = 0;
		for(ll j = i, tmp = m[i]; j >= 0;j--){
			tmp = min(m[j],tmp);
			x += min(m[j],tmp);
		}
		for(ll j = i + 1, tmp = m[i]; j < n;j++){
			tmp = min(m[j],tmp);
			x += min(m[j],tmp);
		}
		if(x > ans) ind = i, ans = x;
	} 
	for(ll i = ind - 1, tmp = m[ind]; i >= 0;i--){
		m[i] = min(m[i],tmp);
		tmp = min(m[i],tmp);
	}
	for(ll i = ind + 1, tmp = m[ind]; i < n;i++){
		m[i] = min(m[i],tmp);
		tmp = min(m[i],tmp);
	}
	for(auto x : m) cout << x << " ";
}