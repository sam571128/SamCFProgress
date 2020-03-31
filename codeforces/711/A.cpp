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
	cini(t);
	bool done = 0;
	vs v;
	while(t--){
		cins(s);
		if(!done){
			if(s[0]=='O'&&s[1]=='O'){
				s[0] = '+';
				s[1] = '+';
				done = 1;
				v.push(s);
				continue;
			}
			if(s[3]=='O'&&s[4]=='O'){
				s[3] = '+';
				s[4] = '+';
				done = 1;
				v.push(s);
				continue;
			}
		}
		v.push(s);
	}
	if(done){
		cout << "YES" << "\n";
		for(auto i : v){
			cout << i << "\n";
		}
	}
	else{
		cout << "NO";
	}
}