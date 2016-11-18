#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int function(vector<string>& grid) {
		vector<string> rgrid(grid[0].length(), string(grid.size(), ' '));
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				rgrid[j][i] = grid[i][j];
			}
		}
		return getNext(grid) * getNext(rgrid);
	}
	int getNext(vector<string>& grid) {
		int k = -1, j = 0, len = grid.size();
		vector<int> next(len + 1, -1);
		while (j < len) {
			while (k != -1 && grid[k] != grid[j]) k = next[k];
			j++;
			k++;
			next[j] = k;
		}
		return len - next.back();
	}
};

int main() {
	Solution* s = new Solution();
	int R, C;
	cin >> R >> C;
	vector<string> grid(R);
	for (int i = 0; i < R; i++) cin >> grid[i];
	if (R == 0 || C == 0) return 0;
	else cout << s->function(grid) << endl;	
	system("pause");
	return 0;
}