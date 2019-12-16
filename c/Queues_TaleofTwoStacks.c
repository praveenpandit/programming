/*
A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
For example, a series of queries might be as follows:

image

Function Description

Complete the put, pop, and peek methods in the editor below. They must perform the actions as described above.

Input Format

The first line contains a single integer, , the number of queries.

Each of the next  lines contains a single query in the form described in the problem statement above. All queries start with an integer denoting the query , but only query  is followed by an additional space-separated value, , denoting the value to be enqueued.

Constraints

It is guaranteed that a valid answer always exists for each query of types  and .
Output Format

For each query of type , return the value of the element at the front of the fifo queue on a new line.
*/

#include <stdio.h>

#define MAX_SIZE 100
long stack[MAX_SIZE];
long si = -1;
long queue[MAX_SIZE];

void reverse(long *arr, long i, long *b, long j)
{
    if (i >= 0)
    {
        b[j] = arr[i - 1];
        reverse(arr, i - 1, b, j + 1);
    }
}
void push(long a)
{
    stack[++si] = a;
    reverse(stack, si + 1, queue, 0);
}
void pop()
{
    reverse(queue, si--, stack, 0);
    if (si < 0)
        si = -1;
}
int top()
{
    return queue[si];
}

/* Driver program to test above function */
long main()
{
    /* change MAX_SIZE */
    for (long i = 2; i < 4; i++)
        push(i * i);
    top();
    pop();
    push(99);
    pop();
    return 0;
}