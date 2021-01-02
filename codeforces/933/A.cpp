#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int a,b,c,d; //1, 12, 121, 1212;
	
signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(tmp==1) a++, c = max(b,c)+1;
		else b = max(a,b)+1, d = max(c,d)+1;
	}
	cout << max({a,b,c,d}) << "\n";
}