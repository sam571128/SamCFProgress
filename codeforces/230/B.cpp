#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;


vector<long long int> isprime(1000001,1);
set<long long int> Tprimes;
void checkdiv(){
	for(int i = 2;i <= 1e6;i++){
		if(isprime[i]){
			Tprimes.insert(1LL*i*i);
			
			for(ll int j = 2*i;j <= 1e6;j+=i){
				isprime[j] = 0;	
			}
		}
	}
}

int main(){
	fastio
	int n;
	cin >> n;
	checkdiv();
	while(n--){
		ll int a;
		cin >> a;
		if(Tprimes.count(a)==1){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}

