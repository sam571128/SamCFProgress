#include <bits/stdc++.h>
#include <cmath> 

#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll int t;
	cin >> t;
	while(t--){
		ll int a,b;
		cin >> a >> b;
		if(a<pow(b,2)||(a%2)!=(b%2)){
			cout << "NO" << "\n";
		}else{
			cout << "YES"<<"\n";
		}
	}
}