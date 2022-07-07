package main
import "fmt"
func twoSum(nums []int, target int) []int {
  var hash = make(map[int]int)
  for i, v := range nums {
    _, exists := hash[target - v]
    if (exists) {
      return []int{hash[target - v], i}
    }
    hash[v] = i
  }
  return []int{-1, -1};
}

func main(){
    nums := []int{2,7,11,15}
    fmt.Println(twoSum(nums, 9));
}
