#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a;
	cin >> a;
	ll int result = 0;
	result += a/500*1000;
	a%=500;
	result += a/5*5;
	cout << result;
}