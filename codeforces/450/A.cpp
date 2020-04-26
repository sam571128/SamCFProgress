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
	queue< pair<int,int> > q;
	for(int i = 1;i <= n;i++){
		int a;
		cin >> a;
		q.push(make_pair(a,i));
	}
	int last = -1;
	while(!q.empty()){
		pair<int,int> x = q.front();
		q.pop();
		last = x.second;
		x.first-=m;
		if(x.first>0) q.push(x);
	}
	cout << last;
}
