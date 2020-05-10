#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	if(!b){
		if(a)
			for(int i = 0;i < a+1;i++)
				cout << 0;
		else
			for(int i = 0;i < c+1;i++)
				cout << 1;
	}else{
		for(int i = 0;i < a;i++){
			cout << 0;
		}
		cout << "01";
		b--;
		for(int i = 0;i < c;i++){
			cout << 1;
		}
		int d = 0;
		for(int i = 0;i < b;i++){
			cout << d;
			d = !d;
		}
	}
	cout << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
