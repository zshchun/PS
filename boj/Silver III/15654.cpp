#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[9];
int nums[9];
bool used[9];
int N, M;
void dfs(int c, int n) {
	int i;
	if (c == M) {
		for (i=0;i<M;i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (i=0;i<N;i++) {
		if (used[i]) continue;
		used[i] = 1;
		a[c] = nums[i];
		dfs(c+1, n+1);
		used[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0;i<N;i++)
		cin >> nums[i];
	sort(nums, nums+N);
	dfs(0, 0);
	return 0;
}

