#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

string s1, s2;
signed main(){
	fastio
	cin >> s1 >> s2;
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end(),greater<char>());
	int n = s1.size();
	string ans = string((int)3e5+5,'a');
	s1 = s1.substr(0,(n+1)/2), s2 = s2.substr(0,n/2);
	int l = 0, r = n-1, l1 = 0, l2 = 0, r1 = s1.size()-1, r2 = s2.size()-1;
	for(int i = 0;i < n;i++){
		if(s1[l1] >= s2[l2]){
			if(i%2==0) ans[r] = s1[r1], r--, r1--;
			else ans[r] = s2[r2], r--, r2--;
		}else{
			if(i%2==0) ans[l] = s1[l1], l++, l1++;
			else ans[l] = s2[l2], l++, l2++;
		}
	}
	ans = ans.substr(0,n);
	//reverse(ans.begin(),ans.end());
	cout << ans << "\n";
}