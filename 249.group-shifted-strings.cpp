#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/* Works but O(n^2)

vector<vector<string>> GroupsofRotations(vector<string> &words) {
    vector<vector<string>> finalGroups;
    unordered_map<string, vector<string>> Groups;
    for(string word: words) {
        bool inserted = false;
        for (unordered_map<string, vector<string>>::iterator it = Groups.begin();
             it != Groups.end();
             ++it) {
            string existingWord = it->first;
            int diff = (existingWord[0] - word[0] + 25)%26;
            int i = 1;
            bool diffmismatched = false;
            for (i = 1; i < min(existingWord.size(), word.size()); ++i) {
                if ((existingWord[i] - word[i] + 25)%26 != diff) {
                    diffmismatched = true;
                    break;
                }
            }
            if (i == existingWord.size() && i == word.size() && diffmismatched == false) {
                it->second.push_back(word);
                inserted = true;
                break;
            }
        }
        if (inserted == false) {
            vector<string> temp;
            temp.push_back(word);
            Groups[word] = temp;
        }
    }
    for (unordered_map<string, vector<string>>::iterator it = Groups.begin();
         it != Groups.end();
         ++it) {
        finalGroups.push_back(it->second);
    }
    return finalGroups;
}
*/
/* 
 * Problem Statement:
 * Let's say we define rotations as below:
 * rot0: a->a, b->b, c->c,...,z->z;
 * rot1: a->b, b->c, c->d,...,z->a;
 * rot2: a->c, b->d, c->e,...,z->b;
 * rot25:a->z, b->a, c->b,...,z->y;
 * 
 * You're given a vector of strings. Return a vector of groups of strings such that string in each
 * group is some rotation of one another. For example:
 * {abbc, bccd, a, z, xfg, cube, zaab}
 * output: group1 = abbc, bccd, zaab
 *         group2 = a, k
 *         group3 = xfg
 *         group4 = cube
 * abbc and bccd are rot1. abbc and zaab are rot25. bccd and zaab are rot24. All are some rotation
 * of one another. So they must belong to same group.
 * a and z are rot11.
 * xfg and cube don't have any other elements with some rotation. So, they belong to their own 
 * group.
 * 
 * 
 * Solution idea:
 * For any two elements to be in same group, the relative distance between chars of word should be 
 * same.
 * abbc can be though as 101 - distance from a to b - 1, distance from b to b = 0, distance from b 
 * to c = 1.
 * 
 * This has to be with all the words who should belong to the same group
 * bccd = 101
 * zaab = 101 (after taking rollover into account)
 * 
 * This also takes care of elements of different length.
 * So map each element to a hash with this relative distance string. And at the end, return each
 * mapping.
 * 
 */

vector<vector<string>> GroupsofRotations(vector<string> &words) {
    vector<vector<string>> output;
    unordered_map<string, vector<string>> hash;
    for (string word: words) {
        string str("A"); // Some dummy string to begin with.
        for (int i = 1; i < word.size(); ++i) {
            // Take rotation into account. Make each num in ascii caps letters range.
            int num = ((word[i-1] - word[i] + 25 ) % 26) + 65; 
            str += num;
        }
        hash[str].push_back(word);
    }
    for (unordered_map<string, vector<string>>::iterator it = hash.begin();
         it != hash.end();
         ++it) {
        output.push_back(it->second);
    }
    return output;
}
int main() {
    vector<string> words = {"abbc", "bccd", "a", "d", "zaab", "cube"};
    vector<vector<string>> groups = GroupsofRotations(words);
    for (auto strings: groups) {
        cout << "Group: ";
        for (auto words: strings) {
            cout << words << "\t";
        }
        cout << "\n";
    }
    return 0;
}