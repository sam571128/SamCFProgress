#include <bits/stdc++.h>

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

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	map<string,int> m;
	int n;
	cin >> n;
	while(n--){
		cins(temp);
		m[temp]++;
	}
	int ma = INT_MIN;
	string ans;
	for(auto itr = m.begin();itr!=m.end();itr++){
		if(ma<itr->second){
			ma = itr->second;
			ans = itr->first;
		}
	} 
	cout << ans;
}
