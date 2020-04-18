#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
typedef vector< pair<int,int> > vpi;

int countdigitsum(int i){
	int sum = 0;
	while(i!=0){
		sum+=i%10;
		i/=10;
	}
	return sum;
}
int main(){
	fastio
	ll int a,b,c;
	cin >> a >> b >> c;
	vi v;
	for(ll int i = 1;i <= 81;i++){
		ll int x = b*pow(i,a)+c;
		if(countdigitsum(x)==i&&x<1e9){
			v.pb(x);	
		}
	}
	cout << v.size() << "\n";
	for(int i : v){
		cout << i << " ";
	}
}
