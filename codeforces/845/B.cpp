#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	string s;
	cin >> s;
	int n = s.size();
	int sum1 = 0, sum2 = 0;
	vector<int> v1, v2, v3, v4;
	for(int i = 0;i < 3;i++){
		v1.push_back('9'-s[i]);
		v3.push_back(s[i]-'0');
		sum1 += s[i]-'0';
	}
	for(int i = 3;i < 6;i++){
		v2.push_back('9'-s[i]);
		v4.push_back(s[i]-'0');
		sum2 += s[i]-'0';
	}
	sort(v1.begin(),v1.end(),greater<int>());
	sort(v2.begin(),v2.end(),greater<int>());
	sort(v3.begin(),v3.end(),greater<int>());
	sort(v4.begin(),v4.end(),greater<int>());
	if(sum1==sum2){
		cout << 0 << "\n";
	}else if(sum1 > sum2){
		int ans = 1e18;
		int d = sum1-sum2;
		int cnt = 0;
		for(auto x : v2){
			cnt++;
			d -= x;
			if(d <= 0){
				ans = min(cnt,ans);
				break;
			}
		}
		d = sum1-sum2;
		cnt = 0;
		for(auto x : v3){
			cnt++;
			d -= x;
			if(d <= 0){
				ans = min(cnt,ans);
				break;
			}
		}
		d = sum1-sum2;
		if(v3[0]+v4[0]>=d||v2[0]+v4[0]>=d||v1[0]+v4[0]>=d||v2[0]+v3[0]>=d){
			ans = min(ans,(int)2);
		}
		cout << ans << "\n";
	}else if(sum2 > sum1){
		int ans = 1e18;
		int d = sum2-sum1;
		int cnt = 0;
		for(auto x : v1){
			cnt++;
			d -= x;
			if(d <= 0){
				ans = min(cnt,ans);
			}
		}
		d = sum2-sum1;
		cnt = 0;
		for(auto x : v4){
			cnt++;
			d -= x;
			if(d <= 0){
				ans = min(cnt,ans);
			}
		}
		d = sum2-sum1;
		if(v3[0]+v4[0]>=d||v2[0]+v4[0]>=d||v1[0]+v4[0]>=d||v2[0]+v3[0]>=d){
			ans = min(ans,(int)2);
		}
		cout << ans << "\n";
	}
}