#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> function(vector<int>& cows, vector<int>& pattern, int S) {
		vector<int> patternTree(S + 1, 0), cowTree(S + 1, 0);
		vector<int> patternEqual(pattern.size(), 0), patternLess(pattern.size(), 0);
		for (int i = 0; i < pattern.size(); i++) {
			patternLess[i] = sum(patternTree, pattern[i] - 1);
			patternEqual[i] = sum(patternTree, pattern[i]) - patternLess[i];
			update(patternTree, pattern[i], 1);
		}
		vector<int> next = getNext(pattern, patternEqual, patternLess, S);
		int i = 0, j = 0;
		vector<int> indexes;
		while (i < cows.size()) {
			int cowLess = sum(cowTree, cows[i] - 1);
			int cowEqual = sum(cowTree, cows[i]) - cowLess;
			if (j == -1 || (j < pattern.size() && cowLess == patternLess[j] && cowEqual == patternEqual[j])) {
				update(cowTree, cows[i], 1);
				i++;
				j++;
			} else {
				int index = i - j;
				if (j == pattern.size()) indexes.push_back(i - j + 1);
				j = next[j];
				for (int k = index; k < i - j; k++) update(cowTree, cows[k], -1);
			}		
		}
		if (j == pattern.size()) indexes.push_back(i - j + 1);
		return indexes;
	}
	vector<int> getNext(vector<int>& pattern, vector<int>& patternEqual, vector<int>& patternLess, int S) {
		vector<int> next(pattern.size() + 1, -1);
		vector<int> suffixTree(S + 1, 0);
		int k = -1, j = 0;
		update(suffixTree, pattern[0], -1);
		while (j < next.size() - 1) {
			int less = sum(suffixTree, pattern[j] - 1);
			int equal = sum(suffixTree, pattern[j]) - less;
			if (k == -1 || (patternLess[k] == less && patternEqual[k] == equal)) {
				update(suffixTree, pattern[j], 1);
				k++;
				j++;
				next[j] = k;
			} else {
				int start = j - k;
				k = next[k];
				for (int i = start; i < j - k; i++) update(suffixTree, pattern[i], -1);
			}
		}
		return next;
	}
	int lowbit(int x) {
		return x & -x;
	}
	void update(vector<int>& tree, int x, int off) {
		while (x < tree.size()) {
			tree[x] += off;
			x += lowbit(x);
		}
	}
	int sum(vector<int>& tree, int x) {
		int result = 0;
		while (x > 0) {
			result += tree[x];
			x -= lowbit(x);
		}
		return result;
	}
};

int main() {
	Solution* s = new Solution();
	int N, K, S;
	cin >> N >> K >> S;
	vector<int> cows(N), pattern(K);
	for (int i = 0; i < N; i++) cin >> cows[i];
	for (int i = 0; i < K; i++) cin >> pattern[i];
	vector<int> indexes = s->function(cows, pattern, S);
	cout << indexes.size() << endl;
	for (int i = 0; i < indexes.size(); i++) {
		cout << indexes[i] << endl;
	}
	system("pause");
	return 0;
}