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
	vll v(6,0);
	for(int i = 0;i < 6;i++){
		if(i==0){
			v[i] = a;
		}else if(i==1){
			v[i] = b;
		}else{
			v[i] = v[i-1]-v[i-2];
		}
	}
	cout << (v[(c-1)%6]+(long long int)((1e9+7)*3))%((int)1e9+7);
}
