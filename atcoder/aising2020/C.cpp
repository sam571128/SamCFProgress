#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll N = 1e6+5;
ll arr[N];

void build(){
	for(ll i = 1; i <= 105;i++){
		for(ll j = 1;j <= 105;j++){
			for(ll k = 1;k <= 105;k++){
				if(i*i+j*j+k*k+i*j+j*k+k*i <= N) arr[i*i+j*j+k*k+i*j+j*k+k*i]++;
			}
		}
	}
}

int main(){
	fastio
	ll n;
	cin >> n;
	build();
	for(ll i = 1;i <= n;i++){
		cout << arr[i] << "\n";
	}
}