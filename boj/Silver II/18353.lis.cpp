#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j;
	cin >> N;

	vector<int> lis;
	vector<int> a(N);

	for (i=0;i<N;i++)
		cin >> a[i];

	reverse(a.begin(), a.end());

	for (i=0;i<N;i++) {
		j = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
		if (j < lis.size())
			lis[j] = a[i];
		else
			lis.push_back(a[i]);
	}

	cout << N - lis.size() << endl;


	return 0;
}
