#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll a,b;
	cin >> a >> b;
	if(a==b){
		cout << "infinity" << "\n";
		return 0;
	}
	ll cnt = 0;
	for(ll i = 1;i * i <= a-b;i++){
		if((a-b)%i==0) {
			if(a%i==b) cnt++;
			if(i!=(a-b)/i&&a%((a-b)/i)==b) cnt++;
		}
	}
	cout << cnt << "\n";

}