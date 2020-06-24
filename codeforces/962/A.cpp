#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	ll sum = 0;
	ll arr[n];
	for(ll i = 0; i < n;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	for(ll i = 0, sum2 = 0;i < n;i++){
		sum2 += arr[i];
		if(sum2*2>=sum){
			cout << i+1 << "\n";
			return 0;
		}
	}
}