package main

import "fmt"

func main() {
	num := make(chan int)
	squar := make(chan int)

	go func() {
		for x := 0; ; x++ {
			num <- x
		}
		// close(num)
	}()

	go func() {
		// for x := range num {
		for {
			x := <-num
			squar <- x * x
		}
		// close(squar)
	}()

	// for x := range squar {
	for {
		fmt.Println(<-squar)
	}
}
