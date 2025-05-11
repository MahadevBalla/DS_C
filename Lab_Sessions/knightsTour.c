#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

// Queue structure
typedef struct
{
    char data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Stack structure for operands
typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize the queue
void initQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

// Enqueue an element to the queue
void enqueue(Queue *queue, char value)
{
    queue->data[queue->rear++] = value;
}

// Dequeue an element from the queue
char dequeue(Queue *queue)
{
    return queue->data[queue->front++];
}

// Check if the queue is empty
int isQueueEmpty(Queue *queue)
{
    return queue->front == queue->rear;
}

// Initialize the stack
void initStack(Stack *stack)
{
    stack->top = -1;
}

// Push an element onto the stack
void push(Stack *stack, int value)
{
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack *stack)
{
    return stack->data[stack->top--];
}

// Function to check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Reverse the string
void reverseString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to evaluate the prefix expression
int evaluatePrefix(char *expression)
{
    // Reverse the prefix expression
    reverseString(expression);

    // Initialize the queue and stack
    Queue queue;
    initQueue(&queue);
    Stack stack;
    initStack(&stack);

    // Enqueue all characters of the reversed expression
    for (int i = 0; expression[i] != '\0'; i++)
    {
        enqueue(&queue, expression[i]);
    }

    // Process the queue
    while (!isQueueEmpty(&queue))
    {
        char token = dequeue(&queue);

        if (isdigit(token))
        { // Operand
            int operand = token - '0';
            push(&stack, operand);
        }
        else if (isOperator(token))
        { // Operator
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            int result;

            switch (token)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            push(&stack, result);
        }
    }

    // The final result is the last remaining value in the stack
    return pop(&stack);
}

int main()
{
    char expression[] = "*+123";

    int result = evaluatePrefix(expression);
    printf("Result: %d\n", result); // Output: 5

    return 0;
}