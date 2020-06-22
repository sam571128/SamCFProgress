#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n;
	cin >> n;
	ll arr[n];
	ll zero = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i]==0) zero++;
	}
	if(zero!=0){
		cout << 0 << "\n";
		return 0;
	}
	ll prod = 1;
	for(auto x : arr){
		if(x<=((ll)1e18)/prod){
			prod *= x;
		}else{
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << prod << "\n";
}