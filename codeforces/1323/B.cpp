#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll N = 1e5;
ll a[N], b[N], tmpa[N], tmpb[N];

int main(){
	//fastio
	ll n,m,k;
	cin >> n >> m >> k;
	for(ll i = 0;i < n;i++) cin >> a[i];
	for(ll i = 0;i < m;i++) cin >> b[i];
	ll i = 0;
	while(i < n){
		if(a[i]==0){
			i++;
			continue;
		}
		ll j = i;
		while(j < n && a[j]==1){
			j++;
		}
		for(ll len = 0; len <= j-i; len++){
			tmpa[len] += j-i - len + 1;
		}
		i = j;
	}

	i = 0;
	while(i < m){
		if(b[i]==0){
			i++;
			continue;
		}
		ll j = i;
		while(j < m && b[j]==1){
			j++;
		}
		for(ll len = 0; len <= j-i; len++){
			tmpb[len] += j-i - len + 1;
		}
		i = j;
	}
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		if(k%i==0&&k/i<=m){
			ans += tmpa[i] * tmpb[k/i];
		}
	}
	cout << ans << "\n";
}