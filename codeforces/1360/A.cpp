#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int ans = min(2*a,2*b);
		if(a>ans) ans = a;
		if(b>ans) ans = b;
		cout << pow(ans,2) << "\n";
	}
}