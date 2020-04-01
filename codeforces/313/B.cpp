#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

int arr[100000],k = 0;
int main(){
	fastio
	string a;
	cin >> a;
	for(int i = 1;i < a.size();i++){
		if(a[i]==a[i-1]){
			k++;
		}
		arr[i] = k;
	}
	
	int t;
	cin >> t;
	while(t--){
		int b,c;
		cin >> b >> c;
		cout << arr[c-1]-arr[b-1] << "\n";
	}
}
