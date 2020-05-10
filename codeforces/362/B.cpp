#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	int n,m;
	cin >> n >> m;
	vi v;
	for(int i = 0;i < m;i++){
		int a;
		cin >> a;
		v.push_back(a);
		if(a==1||a==n){
			cout << "NO";
			return 0;
		}
	} 
	if(m<=2){
		cout << "YES";
		return 0;
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size()-2;i++){
		if(v[i+2]-v[i]==2){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
