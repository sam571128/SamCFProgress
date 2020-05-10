#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

void solve(){
	string a;
	cin >> a;
	bool find1 = false;
	bool find2 = false;
	for(int i = 0;i < a.size()-1;i++){
		if(a[i]=='A'&&a[i+1]=='B'&&!find1){
			find1 = true;
			i++;
			continue;
		}
		if(a[i]=='B'&&a[i+1]=='A'&&find1){
			find2 = true;
			i++;
			continue;
		}
	}	
	if(find1&&find2){
		cout << "YES";
		return;
	}
	find1 = false;
	find2 = false;
	for(int i = 0;i < a.size()-1;i++){
		if(a[i]=='B'&&a[i+1]=='A'&&!find1){
			find1 = true;
			i++;
			continue;
		}
		if(a[i]=='A'&&a[i+1]=='B'&&find1){
			find2 = true;
			i++;
			continue;
		}
	}
	if(find1&&find2) cout << "YES";
	else cout << "NO";
}

int main(){
	fastio
	solve();
}
