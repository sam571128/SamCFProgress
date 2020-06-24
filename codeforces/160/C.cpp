#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll N = 2e5;

ll v[N];
ll pri[N];
map<ll,ll> m;

int main(){
	//fastio
	ll n,k;
	cin >> n >> k;
	k--;
	for(ll i = 0; i < n;i++) cin >> v[i], m[v[i]]++;
	sort(v,v+n);
	ll x = k/n;
	pri[0]  = 0;
	for(ll i = 1;i < n;i++){
		if(v[i]==v[i-1]) pri[i] = pri[i-1];
		else pri[i] = i;
	}
	k -= pri[x] * n;
	ll y = k/m[v[x]];
	cout << v[x] << " " << v[y] << "\n";
}