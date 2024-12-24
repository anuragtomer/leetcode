class Solution {
public:
    string removeDigit(string number, char digit) {
        size_t index_to_remove = -1, possible_index = -1;
        for (size_t i = 0; i < number.size(); ++i) {
            if (number[i] == digit) {
                possible_index = i;
                if (i < number.size() - 1 && number[i + 1] > number[i]) {
                    index_to_remove = i;
                    break;
                }
            }
        }
        if (index_to_remove != -1) {
            number.erase(number.begin() + index_to_remove);
        } else if (possible_index != -1) {
            number.erase(number.begin() + possible_index);
        } else {
            throw "Digit not found";
        }
        return number;
    }
};
