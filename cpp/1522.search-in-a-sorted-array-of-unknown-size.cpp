class Solution {
   public:
    /**
     * @reader: reader.get(k) returns the element of the array at index k (0-indexed).
     * @return: return target index
     */
    int normal_binary_search(ArrayReader reader, int target, int low, int high) {
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int mid_num = reader.get(mid);
            if (mid_num == target) {
                return mid;
            } else if (mid_num < target) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return -1;
    }
    int binary_search(ArrayReader reader, int target, int low, int high) {
        if (low > high) {
            return -1;
        }
        int current_num = reader.get(high);
        if (current_num > target) {
            return normal_binary_search(reader, target, low, high);
        } else if (current_num < target) {
            if (high == numeric_limits<int>::max())
                return -1;
            return binary_search(reader, target, high, high * 2);
        } else {
            return high;
        }
    }
    int search(ArrayReader reader, int target) { return binary_search(reader, target, 0, 16); }
};

