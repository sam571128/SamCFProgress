#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){ 
	fastio
	int t;
	cin >> t;
	while(t--){
		double a,b;
		cin >> a >> b;
		cout << (int)ceil((a*b)/2) << "\n";
	}
}