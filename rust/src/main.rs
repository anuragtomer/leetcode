use cheapest_flights_within_k_stops::Solution;
use rust::cheapest_flights_within_k_stops;
fn main() {
    println!(
        "{}",
        Solution::find_cheapest_price(
            3,
            vec![vec![0, 1, 100], vec![1, 2, 100], vec![0, 2, 500]],
            0,
            2,
            0
        )
    );
}
