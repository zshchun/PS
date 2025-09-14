#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int n, ans;
int a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n;
	vector<int> lis; // Longest Increasing Subsequence
	for (i=0;i<n;i++)
		cin >> a[i];

	for (i=0;i<n;i++) {
		auto it = lower_bound(lis.begin(), lis.end(), a[i]);
		if (it == lis.end())
			lis.push_back(a[i]);
		else
			*it = a[i];
	}
	cout << lis.size() << endl;
	
	return 0;
}
