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
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0;i < n;i++){
		int x;
		cin >> x;
		sum += x;
	}
	int count = 0;
	for(int i = 0;i < 5;i++){
		if((sum+i)%(n+1)!=0)count++;
	}
	cout << count;
}
