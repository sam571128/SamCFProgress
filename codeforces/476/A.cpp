#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

//Check if any number is multiple of m between ceil(n/2) ~ n
//n -> n/2
//n
//n/2+1 => all 2 one 1 
//n/2 => all 2
signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = (n+1)/2;i <= n;i++){
		if(i%m==0){
			cout << i << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}