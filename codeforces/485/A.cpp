#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll a,m;
	cin >> a >> m;
	for(ll i = 0;i < 30;i++){
		if(a*(1<<i)%m==0){
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
}