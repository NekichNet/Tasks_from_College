#include <iostream>
#include <vector>

static class MemorizedFib {
public:
	static int find(int n) {
		if (n < 1) throw "Error: n < 1";
		if (_memo.size() < n - 1) _memo.resize(n + 1, 0);
		if (n <= 2) return 1;
		if (_memo[n] > 0) return _memo[n];
		_memo[n] = find(n - 1) + find(n - 2);
		return _memo[n];
	}
private:
	static std::vector<int> _memo;
};
std::vector<int> MemorizedFib::_memo;

int main() {
	int value = MemorizedFib::find(10);
	std::cout << value << std::endl;
	return 0;
}