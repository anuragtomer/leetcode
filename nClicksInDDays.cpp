/* Problem Statement:
 * You are given a file containing the following information in each row:
 * - url - URL
 * - clicks - No of clicks for that URL
 * - day - Day on which clicks were recorded.
 * Given `minClicks` and `days`, you are required to return all the urls which have atleast `minClicks`
 * in `days` consecutive days. If for a particular day, there is no entry for any url, it may be assumed
 * that there were no clicks on that day.
 * Example:
 * abc.com 5 3
 * def.com 2 1
 * ghi.com 6 12
 * def.com 9 1
 * ghi.com 7 8
 * abc.com 6 4
 * abc.com 7 4
 * abc.com 1 1
 * minClicks: 5
 * Days: 2
 * Return: <abc.com, ghi.com>
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    struct data {
        string url;
        int day;
        int clicks;
    };
    struct dayAndClicks {
        int day;
        int clicks;
    };
    vector<data> readcsv(string &filename) {
        // read file and create a vector of data.
        return {data{"", 0, 0}};
    }

    bool nClicksInDDays(vector<dayAndClicks> &clickData, int minClicks, int days) {
        int currentClicks = 0;
        for (int left = 0, right = 0; right < clickData.size(); ++right) {
            currentClicks += clickData[right].clicks;
            while (clickData[right].day - clickData[left].day + 1 > days) {
                currentClicks -= clickData[left].clicks;
                left++;
            }
            if (currentClicks >= minClicks)
                return true;
        }
        return false;
    }

    vector<string> urls(string filename, int minClicks, int days) {
        vector<data> clickData = readcsv(filename);
        auto comp = [](data &a, data &b) {
            if (a.url == b.url)
                return a.day < b.day;
            return a.url < b.url;
        };
        sort(clickData.begin(), clickData.end(), comp);
        vector<string> result;
        for (int i = 0; i < clickData.size(); ++i) {
            vector<dayAndClicks> singleURLData;
            singleURLData.push_back({clickData[i].day, clickData[i].clicks});
            while (i < clickData.size() - 1 && clickData[i].url == clickData[i + 1].url) {
                singleURLData.push_back({clickData[i + 1].day, clickData[i + 1].clicks});
                ++i;
            }
            if (nClicksInDDays(singleURLData, minClicks, days))
                result.push_back(clickData[i].url);
        }
        return result;
    }
};

int main() {
    Solution sol;

    return 0;
}

