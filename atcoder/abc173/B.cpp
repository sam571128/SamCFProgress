#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int a,b,c,d;
int main(){
	fastio
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		if(s=="AC") a++;
		else if(s=="WA") b++;
		else if(s=="TLE") c++;
		else if(s=="RE") d++;
	}
	cout << "AC x " <<  a << "\n";
	cout << "WA x " <<  b << "\n";
	cout << "TLE x " << c << "\n";
	cout << "RE x " << d << "\n";
}