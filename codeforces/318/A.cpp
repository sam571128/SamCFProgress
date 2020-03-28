#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	ll int n,k;
	cin >> n >> k;
	if(n==k){
		if(n%2==0||n==1){
			cout << n;
			return 0;
		}else{
			cout << n-1;
			return 0;
		}
	}
	int odd = 1; // odd => 1, even => 0
	if(k>(n+1)/2){
		odd = 0;
		k%=(n+1)/2;
	}
	if(odd){
		cout << 2*k-1;
	}else{
		cout << 2*k;
	}
}