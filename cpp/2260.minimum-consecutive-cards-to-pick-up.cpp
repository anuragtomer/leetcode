class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> found_cards;
        int min_cards_to_pick = INT_MAX;
        for (int i = 0; i < cards.size(); ++i) {
            if (found_cards.find(cards[i]) != found_cards.end()) {
                min_cards_to_pick = min(min_cards_to_pick, i - found_cards[cards[i]] + 1);
            }
            found_cards[cards[i]] = i;
        }
        return min_cards_to_pick == INT_MAX? -1: min_cards_to_pick;
    }
};
