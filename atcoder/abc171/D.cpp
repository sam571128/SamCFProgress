#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	unordered_map<ll,ll> m;
	ll sum = 0;
	for(ll i = 0, tmp;i < n;i++) cin >> tmp, m[tmp]++, sum += tmp;
	ll q;
	cin >> q;
	while(q--){
		ll a,b;
		cin >> a >> b;
		m[b] += m[a];
		sum -= m[a]*a;
		sum += b*m[a];
		m[a] = 0;
		cout << sum << "\n";
	} 
}