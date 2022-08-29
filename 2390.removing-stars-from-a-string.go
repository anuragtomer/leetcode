func removeStars(s string) string {
  result := make([]rune, 0)
  for _, ch := range s {
    if ch == '*' {
      result = result[:len(result) - 1]
    } else {
      result = append(result, ch)
    }
  }
  return string(result)
}
