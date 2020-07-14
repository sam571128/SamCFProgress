#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n,t,ans = INT_MIN;
	cin >> n >> t;
	vector<ll> a(n);
	for(auto &x : a) cin >> x;
	if(n==1) ans = a[0];
	for(ll i = 0;i < n;i++){
		for(ll j = i+1;j < n;j++){
			vector<ll> canuse;
			vector<ll> have;
			for(ll k = 0;k < n;k++){
				if(!(k>=i&&k<=j)) canuse.push_back(a[k]);
				else have.push_back(a[k]);
			}
			sort(canuse.begin(),canuse.end());
			sort(have.begin(),have.end(),greater<ll>());
			vector<ll> phve;
			vector<ll> pcan;
			ll tmp = 0;
			while(tmp < t){
				tmp++;
				if(!have.size()||!canuse.size()) continue;
				if(have.back()<canuse.back())  phve.push_back(canuse.back()),pcan.push_back(have.back()); canuse.pop_back();have.pop_back();
			}
			if(!(have.size()+phve.size())) continue;
			ll sum = 0;
			for(ll x : have){
				sum += x;
			}
			for(ll y : phve){
				sum += y;
			}
			ans = max(sum,ans);
		}
	}
	cout << ans << "\n";	
}