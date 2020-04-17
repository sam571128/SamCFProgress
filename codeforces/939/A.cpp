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

int adj[100005];
int main(){
	fastio
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		int a;
		cin >> a;
		adj[i] = a; 
	}
	for(int i = 1; i <= t;i++){
		if(adj[adj[adj[i]]]==i){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	
}
