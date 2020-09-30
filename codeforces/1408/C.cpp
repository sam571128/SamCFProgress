#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,l;
	cin >> n >> l;
	deque<double> v;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	double ans = 0;
	double sa = 1, sb = 1, apos = 0, bpos = l;
	while(!v.empty()){
		if((v.front()-apos)/sa < (bpos-v.back())/sb){
			bpos -= (v.front()-apos)/sa*sb;
			ans += (v.front()-apos)/sa;
			apos = v.front();
			sa++;
			v.pop_front();
		}else if((v.front()-apos)/sa > (bpos-v.back())/sb){
			apos += (bpos-v.back())/sb*sa;
			ans += (bpos-v.back())/sb;
			bpos = v.back();
			sb++;
			v.pop_back();
		}else{
			ans += (v.front()-apos)/sa;
			apos = v.front();
			bpos = v.back();
			sa++;
			sb++;
			v.pop_front();
			if(!v.empty())v.pop_back();
		}
	}
	//cout << apos << " " << bpos << " " << sa << " " << sb << "\n";
	//cout << fixed << setprecision(3) << apos << " " << bpos << " " << sa << " " << sb << "\n";
	ans += (bpos-apos)/(sa+sb);
	cout << ans << "\n";
}

signed main(){
	fastio
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while(t--) solve();
}