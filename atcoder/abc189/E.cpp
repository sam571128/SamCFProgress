#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
pair<int,int> mul[N], add[N];
int rev[N]; 
vector<pair<int,int>> points;

signed main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		points.push_back({x,y});
	}
	mul[0] = {1,1}, add[0] = {0,0}, rev[0] = 0;
	int m;
	cin >> m;
	for(int i = 1;i <= m;i++){
		mul[i] = mul[i-1], add[i] = add[i-1], rev[i] = rev[i-1];
		int op;
		cin >> op;
		if(op==1){
			rev[i] ^= 1;
			swap(mul[i].first,mul[i].second);
			swap(add[i].first,add[i].second);
			mul[i].second *= -1;
			add[i].second *= -1;
		}else if(op==2){
			rev[i] ^= 1;
			swap(mul[i].first,mul[i].second);
			swap(add[i].first,add[i].second);
			mul[i].first *= -1;
			add[i].first *= -1;
		}else if(op==3){
			int x;
			cin >> x;
			mul[i].first *= -1;
			add[i].first *= -1;
			add[i].first += 2*x;
		}else if(op==4){
			int x;
			cin >> x;
			mul[i].second *= -1;
			add[i].second *= -1;
			add[i].second += 2*x;
		}
	}
	/*for(int i = 0;i <= m;i++){
		cout << mul[i].first << " " << mul[i].second << " " << add[i].first << " " << add[i].second << " " << rev[i] << "\n";
	}*/
	int q;
	cin >> q;
	for(int i = 0;i < q;i++){
		int id, num;
		cin >> num >> id;
		id--;
		auto [x,y] = points[id];
		//cout << mul[num].first << " " << mul[num].second << " " << add[num].first << " " << add[num].second << " " << rev[num] << "\n";
		if(rev[num]) swap(x,y);
		cout << mul[num].first*x + add[num].first << " " << mul[num].second*y + add[num].second << "\n";
	}
}