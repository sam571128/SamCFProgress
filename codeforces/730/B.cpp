#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> ma, mi;
	if(n==1){
		cout << "! " << 1 << " " << 1 << endl;
		return;
	}
	for(int i = 0;i < n;i+=2){
		if(i==n-1){
			cout << "? " << i << " " << i+1 << endl;
			char c;
			cin >> c;
			if(c=='>'){
				mi.push_back(i+1);
			}else{
				ma.push_back(i+1);
			}
			continue;
		}
		cout << "? " << i+1 << " " << i+2 << endl;
		char c;
		cin >> c;
		if(c=='>'){
			ma.push_back(i+1), mi.push_back(i+2);
		}else{
			ma.push_back(i+2), mi.push_back(i+1);
		}
	}
	int maidx = ma[0], mnidx = mi[0];
	for(int i = 1;i < ma.size();i++){
		cout << "? " << maidx << " " << ma[i] << endl;
		char c;
		cin >> c;
		if(c=='<') maidx = ma[i];
	}
	for(int i = 1;i < mi.size();i++){
		cout << "? " << mnidx << " " << mi[i] << endl;
		char c;
		cin >> c;
		if(c=='>') mnidx = mi[i];
	}
	cout << "! " << mnidx << " " << maidx << endl;
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}
//1 2 3 4