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

int main(){
	fastio
	int a,b;
	cin >> a;
	vi v;
	while(a--){
		int x;
		cin >> x;
		v.pb(x);
	}
	ll int count1 = 0;
	ll int count2 = 0;
	cin >> b;
	while(b--){
		int x;
		cin >> x;
		ll int pos = distance(v.begin(),find(v.begin(),v.end(),x));
		count1 += pos+1;
		count2 += v.size()-pos;
	}
	cout << count1 << " " << count2;
}
