/**
Given an integer array nums and two integers k and p, return the number of distinct subarrays, which have at most k elements that are divisible by p.

Two arrays nums1 and nums2 are said to be distinct if:

They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
A subarray is defined as a non-empty contiguous sequence of elements in an array.
 
Example 1:

Input: nums = [2,3,3,2,2], k = 2, p = 2
Output: 11
Explanation:
The elements at indices 0, 3, and 4 are divisible by p = 2.
The 11 distinct subarrays which have at most k = 2 elements divisible by 2 are:
[2], [2,3], [2,3,3], [2,3,3,2], [3], [3,3], [3,3,2], [3,3,2,2], [3,2], [3,2,2], and [2,2].
Note that the subarrays [2] and [3] occur more than once in nums, but they should each be counted only once.
The subarray [2,3,3,2,2] should not be counted because it has 3 elements that are divisible by 2.
Example 2:

Input: nums = [1,2,3,4], k = 4, p = 1
Output: 10
Explanation:
All element of nums are divisible by p = 1.
Also, every subarray of nums will have at most 4 elements that are divisible by 1.
Since all subarrays are distinct, the total number of subarrays satisfying all the constraints is 10.

Constraints:

1 <= nums.length <= 200
1 <= nums[i], p <= 200
1 <= k <= nums.length

Follow up: Can you solve this problem in O(n2) time complexity?
*/
class Solution {
private:
    struct Trie {
        unordered_map<int, Trie*> ch;
        int cnt = 0;
        int insert(vector<int>& nums, int i, int k, int p) {
            // We need the second part of condition because we also want to include more elements
            // when k = 0, but next numbers are not divisible by p. So adding them is no harm.
            // But if they are divisible, then bail out.
            if (i == nums.size() || k - (nums[i] % p == 0) < 0)
                return 0;
            if (ch[nums[i]] == nullptr)
                ch[nums[i]] = new Trie();
            ++ch[nums[i]]->cnt;
            return (ch[nums[i]]->cnt == 1) + // denotes we have 1 more distinct subarray, irrespective of divisibility.
                ch[nums[i]]->insert(nums, i + 1/*check for next number in array*/, k - (nums[i] % p == 0) /*check divisibility. reduce 1 from k if divisible*/, p);
        }
    };
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int result = 0;
        Trie tree;
        for (int i = 0; i < nums.size(); ++i)
            result += tree.insert(nums, i, k, p);
        return result;
    }
};
