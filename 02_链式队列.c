#include <stdio.h>
#include <stdlib.h>

typedef struct list_queue
{
    int data;
    struct list_queue *tail;
    struct list_queue *next;
}list_queue_t;

// 初始化链式队列， 定义结构体变量
list_queue_t *list_queue_init(void)
{
    list_queue_t *queue_head = malloc(sizeof(list_queue_t));
    queue_head->next = NULL;
    queue_head->tail = queue_head; // 对尾指针指向头节点,每次插入新的节点需要更新队尾指针

    return queue_head;
}

// 入队--尾插
int in_queue(int new_data, list_queue_t *queue)
{
    list_queue_t *new_node = malloc(sizeof(list_queue_t));
    // 初始化数据域
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->tail = NULL;
    // 把新的节点插入到队尾后面
    queue->tail->next = new_node; 
    // 更新队尾---指向新的节点
    queue->tail = new_node;

    return 0;
}

// 出队--把头节点的下一个节点删除，返回该节点的数据
int out_queue(list_queue_t *queue)
{
    // 判断队列是否为空
    if (!queue->next)
    {
        printf("队列已空!\n");
        return -1;
    }
    
    // 定义指针p指向待删除的节点--也就是头节点的下一个节点
    list_queue_t *p = queue->next;
    // 备份待删除节点的数据
    int temp = p->data;
    // 将头节点的next指针指向待删除节点的下一个节点--删除队首
    queue->next = p->next;

    p->next = NULL;
    free(p);

    return temp;
}

#define IN_QUEUE_NUM 5
int main(int argc, char const *argv[])
{
    unsigned char i;
    list_queue_t *head_queue = list_queue_init();
    for (i = 0; i < IN_QUEUE_NUM; i++)
    {
        in_queue(i, head_queue);
    }
    
    for (i = 0; i < IN_QUEUE_NUM + 1; i++)
    {
        printf("出队的数据：%d\n", out_queue(head_queue));
    }
    

    return 0;
}

/*
执行结果：
    出队的数据：0
    出队的数据：1
    出队的数据：2
    出队的数据：3
    出队的数据：4
    队列已空!
    出队的数据：-1

*/
