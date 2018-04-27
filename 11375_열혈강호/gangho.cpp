/*

2018 Apr 27, made by Moon

*/
#include <cstdio>
#include <vector>

#define MAX 1001
using namespace std;

int n, m;
int employee[MAX], work[MAX], visited[MAX];
vector<int> adj[MAX];

bool dfs(int r) {
	if (visited[r]) {
		return false;
	}
	visited[r] = 1;

	for (auto i : adj[r]) {
		//if (work[i] != r) {
			if (work[i] == -1 || dfs(work[i])) {
				//연결이 되어있지 않거나
				//연결이 이미 되어있는 노드의 왼쪽 연결점에서 다시 조사해서
				//다른 연결점이 발견이 된다면, r은 work[i]에 연결할 수 있다
				employee[r] = i;
				work[i] = r;
				return true;
			}
		//}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) {
			int k;
			scanf("%d", &k);
			adj[i].push_back(k);
		}
	}

	int match = 0;
	fill(employee, employee + MAX, -1);
	fill(work, work + MAX, -1);

	for (int i = 1; i <= n; i++) {
		if (employee[i] == -1) {
			//매칭이 안되어있으면
			fill(visited, visited + MAX, 0);
			if (dfs(i)) {
				match++;
			}
		}
	}

	printf("%d\n", match);
	return 0;
}