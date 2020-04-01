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
	int a,b,c;
	cin >> a >> b >> c;
	int round = 0; // 0=>Simon 1=>Antimison
	while(c!=0){
		if(!round){
			c-=__gcd(a,c);
		}else{
			c-=__gcd(b,c);
		}
		if(c==0){
			cout << round;
			return 0;
		}
		round = (round==0 ? 1 : 0);
	}
}
