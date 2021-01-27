#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 35;
vector<int> cnt(N,0);

int getBit(int n){
	int tt = 0;
	while(n!=0){
		n/=2;
		tt++;
	}
	return tt-1;
}
signed main(){
	fastio
	int n,q;
	cin >> n >> q; 
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		cnt[getBit(tmp)]++;
	}
	while(q--){
		int num;
		cin >> num;
		int res = 0;
		for(int i = 34;~i;i--){
			if(num/(1LL<<i)<=cnt[i]) res += (num/(1LL<<i)), num -= (num/(1LL<<i))*(1LL<<i);
			else res += cnt[i], num -= cnt[i]*(1LL<<i);
		}
		if(num==0) cout << res << "\n";
		else cout << -1 << "\n";
	}
}