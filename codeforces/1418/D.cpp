#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<int> s;
multiset<int> ms;

void add(int val){
	s.insert(val);
	auto x = s.lower_bound(val);
	if(next(x)!=s.end()){
		ms.insert(*next(x)-val);
		//cout << "ADD " << *next(x)-val << "\n";
	}
	if(x!=s.begin()){
		ms.insert(val-*prev(x));
		//cout << "ADD " << val-*prev(x) << "\n";
		if(next(x)!=s.end()){
			//cout << "DEL " << *next(x)-*prev(x) << "\n";
			ms.erase(ms.find(*next(x)-*prev(x)));
		}	
	}
}

void del(int val){
	auto x = s.lower_bound(val);
	if(next(x)!=s.end()){
		ms.erase(ms.find(*next(x)-val));
	}
	if(x!=s.begin()){
		ms.erase(ms.find(val-*prev(x)));
		if(next(x)!=s.end()){
			ms.insert(*next(x)-*prev(x));
		}
	}
	s.erase(x);
}

void solve(){
	int n,q;
	cin >> n >> q;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		add(tmp);
	}
	if(s.size()&&ms.size()) cout << *s.rbegin()-*ms.rbegin()-*s.begin() << "\n";	
	else cout << 0 << "\n";
	while(q--){
		int a,b;
		cin >> a >> b;
		if(a) add(b);
		else del(b);
		if(s.size()&&ms.size()) cout << *s.rbegin()-*ms.rbegin()-*s.begin() << "\n";	
		else cout << 0 << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}