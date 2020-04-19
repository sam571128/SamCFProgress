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
	string a;
	int b;
	cin >> a >> b;
	int value[26];
	for(int i = 0;i < 26;i++){
		cin >> value[i];
	}
	int ma = *max_element(value,value+26);
	int sum = 0;
	for(int i = 0;i < a.size();i++){
		sum+=(i+1)*value[a[i]-'a'];
	}
	for(int i = 0;i < b;i++){
		sum+=ma*(a.size()+i+1);
	}
	cout << sum;
}
