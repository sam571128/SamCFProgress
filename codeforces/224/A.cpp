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
	ll int a,b,c;
	cin >> a >> b >> c;
	ll int s1 = sqrt(a*b*c/pow(a,2));
	ll int s2 = sqrt(a*b*c/pow(b,2));
	ll int s3 = sqrt(a*b*c/pow(c,2));
	cout << 4*(s1+s2+s3);
}
