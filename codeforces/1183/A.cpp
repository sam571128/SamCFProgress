#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int sumOfDigits(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n/=10;
	}
	return sum;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 0;i <= 10;i++){
		if(sumOfDigits(n+i)%4==0){
			cout << (n+i) << "\n";
			return;
		}
	}
}

signed main(){
	fastio
	int t = 1;
	while(t--) solve();
}