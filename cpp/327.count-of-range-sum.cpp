#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
    int mergeArray(vector<long> &sum, int lower, int upper, int low, int high) {
        if (low + 1 >= high)
            return 0;
        int mid = low + (high - low) / 2;
        int count = mergeArray(sum, lower, upper, low, mid) + mergeArray(sum, lower, upper, mid, high);
        int m = mid, n = mid;
        for (int i = low; i < mid; ++i) {
            while (m < high && sum[m] - sum[i] < lower)
                ++m;
            while (n < high && sum[n] - sum[i] <= upper)
                ++n;
            count += (n - m);
        }
        inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
        return count;
    }

   public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];
        return mergeArray(sums, lower, upper, 0, sums.size());
    }
};

*/
class Solution {
   public:
    int n;
    vector<int> bit;

    void add(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    int query(int i) {
        int ans = 0;
        for (; i > 0; i -= i & -i)
            ans += bit[i];
        return ans;
    }

    int countRangeSum(vector<int> &nums, int lower, int upper) {
        n = nums.size();
        bit.resize(n + 1);
        vector<long> prefix = {nums[0]};
        vector<pair<long, int>> sorted = {{prefix[0], 1}};
        for (int i = 1; i < n; i++) {
            prefix.push_back(prefix[i - 1] + nums[i]);
            sorted.push_back({prefix[i], i + 1});
        }
        sort(sorted.begin(), sorted.end());

        int L = 0, U = 0, count = 0;
        for (int i = 0; i < n; i++) {
            long prefix = sorted[i].first;
            if (prefix >= lower && prefix <= upper)
                count++;
            long hi = prefix - lower;
            long lo = prefix - upper;
            while (U < n && sorted[U].first <= hi)
                add(sorted[U++].second, 1);
            while (L < n && sorted[L].first < lo)
                add(sorted[L++].second, -1);
            count += query(sorted[i].second - 1);
        }
        return count;
    }
};
int main() {
    Solution sol;

    return 0;
}

