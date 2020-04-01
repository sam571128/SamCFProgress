#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

int main(){
	fastio
	int n,m;
	cin >> n;
	vi v;
	while(n--){
		cini(a);
		v.push(a);
	}
	for(int i = 1;i < v.size();i++){
		v[i] += v[i-1];
	}
	cin >> m;
	while(m--){
		cini(temp);
		auto a = lower_bound(v.begin(),v.end(),temp);
		cout << a-v.begin() + 1 << "\n";
	}
}
