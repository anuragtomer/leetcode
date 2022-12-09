class Solution {
 public:
  int maxProduct(vector<int> &nums) {

    int prefixProd = 0, suffixProd = 0, largestProd = INT_MIN, n = nums.size();
    for (int i = 0; i < n; ++i) {
      prefixProd = (prefixProd == 0) ? nums[i] : prefixProd * nums[i];
      suffixProd =
        (suffixProd == 0) ? nums[n - i - 1] : suffixProd * nums[n - i - 1];
      largestProd = max({prefixProd, suffixProd, largestProd});
    }
    return largestProd;

    // vector<int> left(nums.size() + 1, 1);
    // vector<int> right(nums.size() + 1, 1);
    // for (int i = 0, n = nums.size(), j = n - 1; i < n; ++i, --j) {
    //   left[i + 1] = nums[i] == 0? left[i]: left[i] * nums[i];    // 1 -2 -2 2
    //   right[j] = nums[j] == 0? right[j+1]: right[j+1] * nums[j]; // 1 -1 -1 2
    // }
    // int product = INT_MIN;
    // for (int i = 0; i < nums.size(); ++i)
    //   product = max({product, left[i], right[i]});
    // return product;
  }
};
