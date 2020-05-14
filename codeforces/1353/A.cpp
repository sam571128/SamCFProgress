#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		if(n==1)
			cout << 0 << "\n";
		else if(n==2)
			cout << m << "\n";
		else
			cout << 2*m << "\n";
	}
}