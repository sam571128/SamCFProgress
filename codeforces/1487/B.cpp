#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	if(n%2==0){
		cout << (k-1)%n+1 << "\n";
	}else{
		if(k >= (n/2+1)) cout << (k-1+(k-(n/2+1))/(n/2)+1)%n+1 << "\n";
		else cout << (k-1)%n+1 << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}
/*
9 8 7 6 *5* 4 3 2 *1* 9 8 7 *6* 5 4 3 *2* 1 9 8 *7* 6 5 4 *3* 2 1 9 *8* 7 6 5 *4* 3 2 1 *9* 8 7 6 
1 2 3 4 *6* 7 8 9 *2* 3 4 5 *7* 8 9 1 *3* 4 5 6 *8* 9 1 2 *4* 5 6 7 *9* 1 2 3 *5* 6 7 8 *1* 2 3 4 

4 3 2 1 4 3 2 1
1 2 3 4 1 2 3 4
*/