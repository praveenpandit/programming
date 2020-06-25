#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *sum_runner(void *arg)
{
    long long *sum = malloc(sizeof(long long));
    *sum = 0;
    for (long long i = 0; i <= *(long long *)arg; i++)
        *sum += i;
    printf("sum is %lld\n", *sum);
    pthread_exit((void *)sum);
}
int main(int argc, char **argv)
{
    printf("welcome in sum_of_threads programe!!!\n");
    if (argc < 2)
    {
        perror("Please pass atleast one argument ");
        exit(-1);
    }
    int num_args = argc - 1;

    pthread_t tid[num_args];
    long long limit[num_args];
    for (int i = 0; i < num_args; i++)
    {
        limit[i] = atoll(argv[i + 1]);
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tid[i], &attr, sum_runner, &limit[i]);
    }
    for (int i = 0; i < num_args; i++)
    {
        pthread_detach(tid[i]);
        // pthread_join(tid[i], NULL);
        printf("thread is -- %ld\n", tid[i]);
        sched_yield();
    }
    return 0;
}