#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> v;
int k;

bool check(int n){
	int now = 0, cnt = 1;
	for(auto x : v){
		if(now+x <= n) now += x;
		else cnt++, now = x;
	}
	return cnt <= k;
}

signed main(){
	fastio
	cin >> k;
	string s;
	getline(cin,s);
	getline(cin,s);
	int cnt = 0;
	for(auto c : s){
		if(c==' '||c=='-'){
			v.push_back(cnt+1);
			cnt = 0;
		}else{
			cnt++;
		}
	}
	v.push_back(cnt);
	int l = *max_element(v.begin(),v.end()), r = 1e18;
	while(l < r){
		int mid = l+r>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l << "\n";
}