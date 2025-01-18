#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m;
void backtrack(vector<int> &a, vector<int> x, int c) {
	if (c >= m) {
		for (int &i : x)
			cout <<  i << ' ';
		cout << endl;
		return;
	}
	for (int &i : a) {
		x.push_back(i);
		backtrack(a, x, c+1);
		x.pop_back();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<int> a(n);
	vector<int> x;
	for (int i=0;i<n;i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	backtrack(a, x, 0);
	return 0;
}
