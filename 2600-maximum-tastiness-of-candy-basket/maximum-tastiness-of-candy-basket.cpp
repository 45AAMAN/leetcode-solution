#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumTastiness(std::vector<int>& price, int k) {
        std::sort(price.begin(), price.end());
        auto canPick = [&](int target) {
            int count = 1;
            int last_price = price[0];

            for (int i = 1; i < price.size(); ++i) {
                if (price[i] - last_price >= target) {
                    count++;
                    last_price = price[i];
                }
            }
            return count >= k;
        };
        int low = 0;
        int high = price.back() - price.front();

        while (low < high) {
            int mid = low + (high - low + 1) / 2;

            if (canPick(mid)) {
                low = mid;     // mid is possible, search higher values
            } else {
                high = mid - 1; // mid is not possible, search lower values
            }
        }

        return low;
    }
};