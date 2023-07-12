#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, i, j, cnt, ans = 0;

	cin >> N;
	vector<int> c(N);
	for (i=0;i<N;i++)
		cin >> c[i];

	cin >> M;
	vector<int> box(M);

	for (i=0;i<M;i++)
		cin >> box[i];

	sort(c.begin(), c.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	if (box[0] > c[0]) {
		cout << "-1\n";
		return 0;
	}

	cnt = 1;
	while (!box.empty() && cnt) {
		for (i=0;i<N;i++) {
			for (j=0;j<box.size();j++) {
				if (c[i] >= box[j]) {
					box.erase(box.begin() + j);
					cnt++;
					break;
				}
			}
		}
		ans++;
	}

	if (box.empty())
		cout << ans << endl;
	else
		cout << "-1\n";
	
	return 0;
}
