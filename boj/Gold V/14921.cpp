#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890
int n, ans = INF, real_ans = 0;
vector<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin >> n;
	a.resize(n);
	for (i=0;i<n;i++)
		cin >> a[i];
	for (auto it = a.begin();it != a.end(); it++) {
		auto it2 = upper_bound(a.begin(), a.end(), 0-(*it));
		for (i=0;i<2;i++) {
			if (it2 != a.end() && it != it2) {
				int x = abs(*it + *it2);
				if (x < ans) {
					ans = x;
					real_ans = *it + *it2;
				}
			}
			if (it2 == a.begin()) break;
			it2--;
		}
	}
	cout << real_ans << endl;

	return 0;
}
