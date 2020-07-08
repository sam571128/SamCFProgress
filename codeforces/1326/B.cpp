#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	ll sum = 0, maxs = 0;
	for(ll i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(tmp > 0) sum+=tmp;
		cout << min(sum,sum+tmp) << " ";
	}
}