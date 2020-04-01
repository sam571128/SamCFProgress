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
	while(t--){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int ma = max(max(a,b),max(b,c));
		d-=ma-a+ma-b+ma-c;
		if(d%3==0&&d>=0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}
