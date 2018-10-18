#include <stdio.h>
#include<stdlib.h>
#define SIZE 50

// Stack type
struct Stack
{
    int size;
    int top;
    struct Node* *array;
};
struct Node
{
    int data;
    struct Node *right, *left;
};


// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}

// BASIC OPERATIONS OF STACK
int isfull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }

int isempty(struct Stack* stack)
{  return stack->top == -1; }

void push(struct Stack* stack, struct Node* node)
{
    if (isfull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack)
{
    if (isempty(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct Node* peek(struct Stack* stack)
{
    if (isempty(stack))
        return NULL;
    return stack->array[stack->top];
}
struct Queue
{
    int front, rear;
    int size;
    struct Node* *array;
};
struct Queue* createQueue(int size)
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->array = (struct Node**)malloc(q->size * sizeof(struct node*));
    int i;
    for(i = 0; i < size; i++)
        q->array[i] = NULL;
    return q;
};

struct Node* getFront(struct Queue* q)
{
    return q->array[q->front];
};

int hasBoth(struct Node* t)
{
    return t && t->left && t->right;
}
int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}

int isFull(struct Queue* queue)
{ return queue->rear == queue->size - 1; }

int hasOne(struct Queue* queue)
{ return queue->front == queue->rear; }
void Enqueue(struct Node *root, struct Queue* queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}

struct Node* Dequeue(struct Queue* q)
{
    if(isEmpty(q))
        return NULL;
        struct Node* t = q->array[q->front];
        if(hasOne(q))
            q->front = q->rear = -1;
        else
            ++q->front;
        return t;
};
void insert(struct Node **root, int data, struct Queue* q)
{
    struct Node *t = newNode(data);
    if(!*root)
    {
        *root = t;
    }
    else
    {
        struct Node* f = getFront(q);
        if(!f->left)
            f->left = t;
        else if(!f->right)
            f->right = t;
        if(hasBoth(f))
            Dequeue(q);
    }
    Enqueue(t, q);
}
void levelOrder(struct Node* root)
{
    struct Queue* queue = createQueue(SIZE);

    Enqueue(root, queue);

    while (!isEmpty(queue))
    {
        struct Node* temp = Dequeue(queue);

        printf("%d ", temp->data);

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }
}



void postOrder(struct Node* root)
{
    struct Stack* stk = createStack(SIZE);
    struct Node* curr=root;
    push(stk,root);
    int i;
    while(i=0)
    {
        if(curr)
        {
            push(stk,curr);
            curr=curr->left;
        }

        i=1;
    }
}



int main()
{
    struct Node* root = NULL;
    struct Queue* queue = createQueue(SIZE);
    int i;
    for(i = 1; i <= 7; ++i)
        insert(&root, i, queue);

    levelOrder(root);
    postOrder(root);

    return 0;
}
