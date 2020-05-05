package main

import "fmt"

type byteCounter int

func (c *byteCounter) write(p []byte) /* (int, error) */ {
	*c += byteCounter(len(p))
	// return len(p), nil
}
func main() {
	var c byteCounter
	c.write([]byte("hello"))
	c.write([]byte(" world"))
	fmt.Println(c)
}
