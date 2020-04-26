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
	//fastio
	vi fib;
	int a = 0, b = 1;
	while(a<=1e9){
		fib.pb(a);
		swap(a,b);
		b = a+b;
	}
	int n;
	cin >> n;
	int index = distance(fib.begin(),find(fib.begin(),fib.end(),n));
	if(n==0) cout << "0 0 0";
	else if(n==1) cout << "0 0 1";
	else if(n==2) cout << "0 1 1";
	else cout << fib[index-4] << " " << fib[index-3] << " " << fib[index-1];
}
