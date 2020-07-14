#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793
using namespace std;

int main(){
	fastio
	double n;
	cin >> n;
	vector<double> angle;
	for(double i = 0,x,y;i < n;i++){
		cin >> x >> y;
		angle.push_back(atan2(y,x));
		if(angle[i]<1e-7) angle[i]+=2*PI;
	}
	sort(angle.begin(),angle.end());
	double ans = angle[angle.size()-1] - angle[0];
	for(int i = 0;i < n-1;i++){
		double tmp = 2*PI - (angle[i+1]-angle[i]);
		ans = min(ans,tmp);
	}
	cout << fixed << setprecision(10) << ans*180/PI << "\n";
}