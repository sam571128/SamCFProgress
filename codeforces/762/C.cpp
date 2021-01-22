#pragma optimize("O2");
#pragma optimize("unroll-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string a,b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	int pref[m] = {}, suff[m] = {};
	//Two pointers to find the maximum pos that the pref or suff of b is subsequence of a
	fill(pref,pref+m,n);
	fill(suff,suff+m,-1);
	int i = 0, j = 0;
	while(i < n&&j < m){
		if(a[i]!=b[j]) i++;
		else if(a[i]==b[j]){
			pref[j] = i;
			i++, j++;
		}
	}
	i = n-1, j = m-1;
	while(~i&&~j){
		if(a[i]!=b[j]) i--;
		else if(a[i]==b[j]){
			suff[j] = i;
			i--,j--;
		}
	}
	string ans="";
	ans = b.substr(upper_bound(suff,suff+m,-1)-suff);
	for(int i = 0;i < m;i++){
		if(pref[i]==n) break;
		int num = upper_bound(suff,suff+m,pref[i])-suff;
		if(num <= i) continue; 
		string aa = b.substr(0,i+1), bb = b.substr(num);
		string cc = aa+bb;
		if(cc.size() > ans.size()) ans = cc;
		if(i==num-1) break;
	}
	if(ans.size()==0) cout << '-' << "\n";
	else cout << ans << "\n";
}