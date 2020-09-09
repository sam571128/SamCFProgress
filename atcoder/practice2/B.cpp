#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace atcoder;

signed main(){
	fastio
	int n,q;
	cin >> n >> q;
	fenwick_tree<int> t(n);
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		t.add(i,tmp);
	}
	while(q--){
		int a,b,c;
		cin >> a >> b >> c;
		if(a==0) t.add(b,c);
		else cout << t.sum(b,c) << "\n";
	}
}