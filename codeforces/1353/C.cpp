#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		ll sum = 0;
		int n;
		cin >> n;
		for(int i = 1;i <= n/2;i++){
			sum += 2ll*i*4*i;
		}
		cout << sum << "\n";
	}
}