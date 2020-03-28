#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	ll int a;
	cin >> a;
	ll int sum = 0;
	sum+=(a/2);
	if(a%2!=0){
		sum+=-a;
	}
	cout << sum;
}