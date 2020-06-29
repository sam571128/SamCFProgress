#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll N = 4e4+5;
ll p[N];
ll a,b,q,len;

void build(){
	len = a*b;
	p[0] = 0;
	for(ll i = 1;i <= len;i++){
		p[i] = p[i-1];
		if((i%a)%b!=(i%b)%a) p[i]++;
	}
}

ll query(ll l){
	return (l/len)*p[len] + p[l%len];
}

ll query(ll l, ll r){
	return query(r) - query(l-1);
}

void solve(){
	cin >> a >> b >> q;
	build();
	for(ll i = 0;i < q;i++){
		ll l,r;
		cin >> l >> r;
		cout << query(l,r) << " ";
	}
	cout << "\n";
}

int main(){
	fastio
	ll t;
	cin >> t;
	while(t--) solve();
}