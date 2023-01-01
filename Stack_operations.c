#include <stdio.h>
#include <stdlib.h>
struct stack   // initialise structure for stack
{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *ptr) //to check stack is full
{
    if (ptr->top == ptr->size - 1) // condition to check whether stack is full or not
        return 1;
    else
        return 0;
}
int isempty(struct stack *ptr) // to check stack is empty
{
    if (ptr->top == -1) //condition
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, int n) //Function to push value to stack
{
    if (isfull(ptr)) // condition for stack overflow
        printf("Stack Overflow...");
    else // condition fails then value pushed
        ptr->top++;
    ptr->arr[ptr->top] = n;
    printf("Element pushed successfully into the stack...\n");
}
void pop(struct stack *ptr) //Function to pop value to stack
{
    int val;
    if (isempty(ptr))// condition fails then value popped
        printf("Stack Underflow...");
    else
        val = ptr->arr[ptr->top - 1]; // condition fails then top value is popped
    ptr->top--;
    printf("Element popped successfully...");
}
void display(struct stack *ptr) // function to display the elements
{
    for (int i = ptr->top; i >= 0; i--)
        printf("%d\n", ptr->arr[i]);
}
void main()
{
    int a,i=1,k;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5; // initalising the sizeof stack
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int)); // dynamically allocating memory for array

    while (i)
    {
        printf(" 1) Push\n2)Pop\n3)Display\n4)Exit"); // menu for operations
        printf("\nEnter the operations that you want to perform:");
        scanf("%d",&k);
        switch(k) // switch cases
        {
            case 1: 
            {
                printf("Enter the element to be pushed:");
                scanf("%d", &a);
                push(s, a);
            };break;
            case 2: pop(s);break;
            case 3: display(s);break;
            default: i=0;break;
        }
    }
}