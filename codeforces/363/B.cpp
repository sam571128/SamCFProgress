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
	int n,m;
	cin >> n >> m;
	int sum[n];
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		if(i==0){
			sum[i] = a;
		}else{
			sum[i] = a + sum[i-1];
		}
	}
	vi v;
	for(int i = 0;i < n-m+1;i++){
		if(i==0){
			v.pb(sum[i+m-1]);
		}else{
			v.pb(sum[i+m-1]-sum[i-1]);
		}
	}
	cout << distance(v.begin(),min_element(v.begin(),v.end()))+1;
}
