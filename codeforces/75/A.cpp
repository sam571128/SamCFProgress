#include <bits/stdc++.h>

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

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	string a,b;
	cin >> a >> b;
	string sum1 = to_string(stoi(a) + stoi(b));
	for(int i = 0;i < a.size();i++){
		if(a[i]=='0'){
			a.erase(i,1);
			i--;
		}
	} 
	for(int i = 0;i < b.size();i++){
		if(b[i]=='0'){
			b.erase(i,1);
			i--;
		}
	} 
	for(int i = 0;i < sum1.size();i++){
		if(sum1[i]=='0'){
			sum1.erase(i,1);
			i--;
		}
	} 
	int sum2 = stoi(a)+stoi(b);
	cout << (stoi(sum1)==sum2 ? "YES" : "NO");
}
