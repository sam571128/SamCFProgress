#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
signed main(){
	fastio
	int n;
	cin >> n;
	vector<int> arr(n+1,n);
	set<int> s;
	for(int i = 1;i <= n;i++) s.insert(i);
	while(s.size()>1){
		int x = *(s.begin()), y = *next(s.begin());
		int val1, val2;
		cout << "? " << x << " " << y << "\n";
		cout << endl;
		cin >> val1;
		cout << "? " << y << " " << x << "\n";
		cout << endl;
		cin >> val2;
		if(val1 < val2){
			arr[y] = val2;
			s.erase(y);
		}else{
			arr[x] = val1;
			s.erase(x);
		}
	}
	cout << "! ";
	for(int i = 1;i <= n;i++) cout << arr[i] << " ";
}