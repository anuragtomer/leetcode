class Solution {
public:
    /* Not accepted but correct */
    long long appealSum(string s) {
        vector<bitset<26>> current_level(s.size());
        long long total = 0;
        size_t i = 0;
        for (const char &ch: s) {
            bitset<26> btst;
            ++total;
            btst.set(ch - 'a');
            current_level[i++] = btst;
        }
        while (current_level.size() != 1) {
            vector<bitset<26>> next_level(current_level.size() - 1);
            for (size_t i = 0; i < current_level.size() - 1; ++i) {
                bitset<26> btst = current_level[i] | current_level[i + 1];
                total += btst.count();
                next_level[i] = btst;
            }
            current_level = next_level;
        }
        return total;
    }
};
