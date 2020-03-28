#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	int result = INT_MIN;
	result = max(result,a+b*c);
	result = max(result,a*(b+c));		
	result = max(result,a*b*c);
	result = max(result,(a+b)*c);
	result = max(result,a*b+c);
	result = max(result,a+b+c);
	cout << result;
}