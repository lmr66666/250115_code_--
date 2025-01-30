#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct sq_queue
{
    int data[QUEUE_SIZE];
    int tail;
}sq_queue_t;

// 
sq_queue_t *sq_queue_init(void)
{
    sq_queue_t *my_sq_queue = malloc(sizeof(sq_queue_t));
    
    (my_sq_queue->tail) = -1;
    return my_sq_queue;
}

// 入队
int en_queue(int new_data, sq_queue_t *sq_queue)
{
    // 判断队列是否满了
    if (sq_queue->tail > QUEUE_SIZE - 1)
    {
        printf("队列已满!\n");
        return -1;
    }
    
    (sq_queue->tail)++;
    sq_queue->data[sq_queue->tail] = new_data;
    return 0;
}

// 出队
int out_queue(sq_queue_t *sq_queue)
{
    int i;
    if (sq_queue->tail < 0)
    {
        printf("队列已空!\n");
        return -1;
    }
    int temp = sq_queue->data[0];
    for (i = 0; i < sq_queue->tail; i++)
    { 
        sq_queue->data[i] = sq_queue->data[i+1];
    }
    (sq_queue->tail)--;
    return temp;
}

int main(int argc, char const *argv[])
{
    int i;
    sq_queue_t *my_sq_queue = sq_queue_init();
    if (!my_sq_queue)
    {
        printf("[main] init fail\n");
        return -1;
    }

    for (i = 0; i < 12; i++)
    {
        en_queue(i, my_sq_queue);
    }

    for (i = 0; i < 12; i++)
    {
        printf("出队数据：%d\n", out_queue(my_sq_queue));
    }
    
    return 0;
}

