#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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


/********SAM571128's SOLUTION**********/
int cnt[27];
int main(){
	fastio
	string a,b;
	cin >> a >> b;
	bool au = false;
	for(int i = 0,j = 0;i < a.size();i++){
		if(j<b.size()&&a[i]==b[j]) j++;
		if(j==b.size()) au = true;
	}
	for(int i = 0;i < a.size();i++) cnt[a[i]-'a']++;
	for(int i = 0;i < b.size();i++) cnt[b[i]-'a']--;
	bool ar = true;
	bool all = true;
	for(int i = 0; i < 26;i++){
		ar &= cnt[i]==0;
		all &= cnt[i]>=0;
	}
	if(au)
		cout << "automaton";
	else if(ar)
		cout << "array";
	else if(all)
		cout << "both";
	else
		cout << "need tree";
}
