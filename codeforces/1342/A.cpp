#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		ll int a,b;
		cin >> a >> b;
		ll int x,y;
		cin >> x >> y;
		
		ll int tempc = (a+b)*x;
		ll int count = 0;
		count += min(a,b)*y;
		ll int temp = min(a,b);
		a-=temp;
		b-=temp;
		count += a*x+b*x;
		cout << min(count,tempc)<<"\n";
	}
}
