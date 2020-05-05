package main

import (
	"fmt"
	"sync"
)

func run(wg *sync.WaitGroup) {
	for i := 0; i < 5; i++ {
		go func(n int, wg *sync.WaitGroup) {
			wg.Add(1)
			fmt.Println(n, ": go routien started")
			wg.Done()
		}(i, wg)
	}
}

func main() {
	var wg sync.WaitGroup
	run(&wg)
	fmt.Println("hello world ")
	wg.Wait()
}
