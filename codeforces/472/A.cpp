#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int isprime(int a){
	for(int i = 2;i <= pow(a,0.5);i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	fastio
	ll int a;
	cin >> a;
	for(ll int i = 4;i < a;i++){
		if(!isprime(i)&&!isprime(a-i)){
			cout << i << " " << a-i;
			return 0;
		}
	}
}