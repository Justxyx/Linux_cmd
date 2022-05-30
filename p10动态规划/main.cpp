#include <iostream>
using namespace std;
#include <vector>

int main() {
    Solution solution;
    vector<int> v{1,100,1,1,1,100,1,1,100,1};
    cout << solution.minCostClimbingStairs(v);
    return 0;
}
