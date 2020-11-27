#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


signed main(){
	fastio
	int n;
	cin >> n;
	if(n&1^1){
		cout << "white\n1 2\n";
	}else{
		cout << "black\n";
	}
}