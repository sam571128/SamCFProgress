#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int askArea(int x, int y, int z){
	//Ask the area formed by the vertices x,y,z
	cout << 1 << " " << x << " " << y << " " << z << endl;
	int res;
	cin >> res;
	return res;
}

int askCross(int x, int y, int z){
	//Ask the Cross Product of (x,y) and (x,z)
	cout << 2 << " " << x << " " << y << " " << z << endl;
	int res;
	cin >> res;
	return res;
}


const int N = 1000;
int Area[N];

signed main(){
	fastio
	int n;
	cin >> n;
	//First, we fix two points 1, 2 as the center two point
	int x = 1, y = 2;
	vector<int> left, right;
	for(int i = 3;i <= n;i++){
		//All of this uses n-2 queries
		int c = askCross(x,y,i);
		//If the cross product is negative, then i is at the left of x-y
		//Else i is at right of x-y, the cross product would be positive
		//There will not be collinear on convex polygon
		if(c > 0)
			left.push_back(i);
		else
			right.push_back(i);
	} 

	if(left.size()>=2){
		vector<int> left2, right2;
		int p = 0, maxArea = 0;
		//We need to find the farthest point to the segment on the left
		for(auto z : left){
			int val = askArea(x,y,z);
			Area[z] = val;
			if(val > maxArea) maxArea = val, p = z;
		}
		//Now we need to know the point on the left, and later sort with area
		for(auto z : left){
			if(z==p){
				continue;
			}
			int val = askCross(x,p,z);
			if(val > 0) left2.push_back(z);
			else right2.push_back(z);
		}
		left.clear();
		sort(left2.begin(),left2.end(),[&](int a, int b){return Area[a] > Area[b];});
		sort(right2.begin(),right2.end(),[&](int a, int b){return Area[a] < Area[b];});
		for(auto z : right2) left.push_back(z);
		if(p!=0) left.push_back(p);
		for(auto z : left2) left.push_back(z);
	}
	if(right.size()>=2){
		//Do the same thing to the right
		vector<int> left2, right2;
		int p = 0, maxArea = 0;
		//We need to find the farthest point to the segment on the right
		for(auto z : right){
			int val = askArea(x,y,z);
			Area[z] = val;
			if(val > maxArea) maxArea = val, p = z;
		}
		//Now we need to know the point on the right, and later sort with area
		for(auto z : right){
			if(z==p){
				continue;
			}
			int val = askCross(x,p,z);
			if(val > 0) left2.push_back(z);
			else right2.push_back(z);
		}
		right.clear();
		sort(left2.begin(),left2.end(),[&](int a, int b){return Area[a] > Area[b];});
		sort(right2.begin(),right2.end(),[&](int a, int b){return Area[a] < Area[b];});
		for(auto z : right2) right.push_back(z);
		if(p!=0) right.push_back(p);
		for(auto z : left2) right.push_back(z);
	}
	cout << 0 << " " << x << " ";
	for(auto z : right) cout << z << " ";
	cout << y << " ";
	for(auto z : left) cout << z << " ";
	cout << endl;
}