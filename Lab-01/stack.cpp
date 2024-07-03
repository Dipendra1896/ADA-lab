#include <iostream>
#define MAXSTACK 3
using namespace std;
bool isEmpty(int top)
{
    return top == -1;
}
bool isFull(int top, int maxstack)
{
    return top == maxstack - 1;
}
void push(int stack[], int &top, int maxstack, int item)
{
    if (isFull(top, maxstack))
    {
        cout << "Overflow" << endl;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
        cout << "Pushed item: " << item << endl;
    }
}
void pop(int stack[], int &top, int &item)
{
    if (isEmpty(top))
    {
        cout << "Underflow" << endl;
    }
    else
    {
        item = stack[top];
        top = top - 1;
        cout << "Popped item: " << item << endl;
    }
}
int main()
{
    int stack[MAXSTACK];

    int top = -1; // Initially the stack is empty
    // Test pushing elements onto the stack
    push(stack, top, MAXSTACK, 20);
    push(stack, top, MAXSTACK, 40);
    push(stack, top, MAXSTACK, 70);
    push(stack, top, MAXSTACK, 80);
    // Test popping elements from the stack
    int item;
    pop(stack, top, item);
    pop(stack, top, item);
    pop(stack, top, item);
    // Attempt to pop from an empty stack
    pop(stack, top, item);
    return 0;
}