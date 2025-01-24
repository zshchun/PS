#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

vector<int> prime;
vector<int> ans;
int n;
bool a[1000001];
bool found = false;

void dfs(int nth, int sum) {
	if (sum > n || found) return;
	if (nth == 4) {
		if (n == sum)
			found = true;
		return;
	}
	for (int &x : prime) {
		ans.push_back(x);
		dfs(nth+1, sum + x);
		if (found) break;
		ans.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	cin >> n;
	if (n < 8) {
		cout << "-1\n";
		return 0;
	}

	for (i=2;i<=1000;i++)
		for (j=i+i;j<=n;j+=i) {
			//if (a[j]) break;
			a[j] = 1;
		}

	for (i=2;i<=n;i++) {
		if (!a[i])
			prime.push_back(i);
	}

	ans.push_back(2);
	if (n % 2 == 1) {
		ans.push_back(3);
		dfs(2, 5);
	} else {
		ans.push_back(2);
		dfs(2, 4);
	}
	
	if (found) {
		for (int &x : ans)
			cout << x << " ";
		cout << endl;
	} else {
		cout << "-1\n";
	}


	return 0;
}
