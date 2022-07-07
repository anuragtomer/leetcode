package main
import "fmt"
func isPalindrome(x int) bool {
  if (x < 0) {
    return false
  }
  var y int
  origx := x
  for x > 0 {
    y = y * 10 + x % 10
    x = x / 10
  }
  return origx == y
}
func main() {
    fmt.Println(isPalindrome(121))
    fmt.Println(isPalindrome(-121))
}
