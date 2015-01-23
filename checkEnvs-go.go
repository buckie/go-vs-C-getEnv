package main

import "os"
import "fmt"

func main() {
  foo := os.Getenv("FOO")
  bar := os.Getenv("BAR")

  fmt.Println("FOO is:", foo, "\t\t", &foo)
  fmt.Println("BAR is:", bar, "\t\t", &bar)

  fmt.Print(" FOO ==  BAR -> ")
  if(foo == bar){
    fmt.Print("True\n")
  } else {
    fmt.Print("False\n")
  }
}
