#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool isPrime(int n){
	for(int i = 2;i <= sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}

void solve(){
	int n;
	cin >> n;
	if(n==1||(n&1^1&&isPrime(n/2)&&n!=2)||(n!=2&&n%2==0&&log2(n)==round(log2(n)))){
		cout << "FastestFinger\n";
	}else{
		cout << "Ashishgup\n";
	}
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
} 
