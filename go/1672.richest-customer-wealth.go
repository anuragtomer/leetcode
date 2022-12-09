func maximumWealth(accounts[][] int) int {
  max_wealth := 0;
  for i := range accounts {
    curr_wealth := 0;
    for j := range accounts[i] {
      curr_wealth += accounts[i][j];
    }
    if max_wealth < curr_wealth {
      max_wealth = curr_wealth;
    }
  }
  return max_wealth
}
