#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

void solve(){
	int n;
	cin >> n;
	if(n<4){
		cout << -1 << "\n";
		return;
	}
	deque<int> q;
	q.push_back(3);q.push_back(1);q.push_back(4);q.push_back(2);
	for(int i = 5;i <= n;i++){
		if(i%2==0) q.push_front(i);
		else q.push_back(i);
	}
	for(int x : q){
		cout << x << " ";
	}
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}
