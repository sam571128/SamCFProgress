#include <bits/stdc++.h>

#define long long ll
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int f(int n){
	for(int i = 2;i <= n;i++){
		if(n%i==0) return i;
	}
	return n;
}
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		n+=f(n) + 2*(k-1);
		cout << n << "\n";
	}
}