#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int findSG(int n, int k){
	if(n<=1) return n;
	if(k&1^1){
		if(n == 2) return n;
		else{
			return (n&1^1);
		}
	}else{
		if(n < 5) return n-2;
		if(n%2) return 0;
		else if(findSG(n/2,k)==1) return 2;
		else return 1;
	}
}

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		//cout << findSG(tmp,k) << " ";
		ans ^= findSG(tmp,k);
	}
	cout << (ans ? "Kevin" : "Nicky");
}