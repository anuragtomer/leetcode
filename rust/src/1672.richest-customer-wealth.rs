impl Solution {
  pub fn maximum_wealth(accounts : Vec<Vec<i32>>)->i32 {
    let mut max_wealth : i32 = 0;
    for
      i in 0..accounts.len() {
        let mut curr_wealth : i32 = 0;
      for
        j in 0..accounts [i].len() { curr_wealth += accounts[i][j]; }
      if max_wealth
        < curr_wealth { max_wealth = curr_wealth; }
      }
    max_wealth
  }
}
