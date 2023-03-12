impl Solution {
    #[allow(dead_code)]
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        prices
            .iter()
            .fold((0, std::i32::MAX), |(mut max_profit, mut buy), price| {
                buy = std::cmp::min(*price, buy);
                max_profit = std::cmp::max(max_profit, price - buy);
                (max_profit, buy)
            })
            .0
    }
    /*
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let (mut profit, mut buy, mut sell) = (0, std::i32::MAX, 0);
        for price in prices {
            if buy > price {
                profit = max(profit, sell - buy);
                buy = price;
                sell = price;
            }
            if sell < price {
                sell = price;
            }
            profit = max(profit, sell - buy);
        }
        profit
    }
    */
}
#[allow(dead_code)]
struct Solution {}

#[cfg(test)]

mod tests {
    use super::*;
    #[test]
    fn test_max_profit() {
        assert_eq!(Solution::max_profit(vec![7, 1, 5, 3, 6, 4]), 5);
    }
}
