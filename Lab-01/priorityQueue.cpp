#include <iostream>
#define MAXSIZE 4
using namespace std;
bool isEmpty(int size)
{
    return size == 0;
}
bool isFull(int size, int maxsize)
{
    return size == maxsize;
}
void insert(int elements[], int priorities[], int &size, int maxsize, int element, int priority)
{
    if (isFull(size, maxsize))
    {
        cout << "Overflow" << endl;
    }
    else
    {
        int i = size - 1;
        while (i >= 0 && priorities[i] < priority)
        {
            elements[i + 1] = elements[i];
            priorities[i + 1] = priorities[i];
            i = i - 1;
        }
        elements[i + 1] = element;
        priorities[i + 1] = priority;
        size = size + 1;
        cout << "Inserted element: " << element << " with priority: " << priority << endl;
    }
}
int extractMax(int elements[], int priorities[], int &size)
{
    if (isEmpty(size))
    {
        cout << "Queue is empty" << endl;
        return -1; // Use a special value to indicate the queue is empty
    }
    else
    {
        int maxElement = elements[0];
        for (int i = 0; i < size - 1; i++)
        {
            elements[i] = elements[i + 1];
            priorities[i] = priorities[i + 1];
        }
        size = size - 1;
        return maxElement;
    }
}
int main()
{
    int elements[MAXSIZE];
    int priorities[MAXSIZE];
    int size = 0; // Initially the priority queue is empty
    // Test inserting elements into the priority queue
    insert(elements, priorities, size, MAXSIZE, 20, 1);
    insert(elements, priorities, size, MAXSIZE, 40, 2);
    insert(elements, priorities, size, MAXSIZE, 50, 3);
    insert(elements, priorities, size, MAXSIZE, 70, 4);
    insert(elements, priorities, size, MAXSIZE, 80, 5);
    // Test extracting elements from the priority queue
    int maxElement = extractMax(elements, priorities, size);
    if (maxElement != -1)
    {
        cout << "Extracted element: " << maxElement << endl;
    }
    maxElement = extractMax(elements, priorities, size);
    if (maxElement != -1)
    {
        cout << "Extracted element: " << maxElement << endl;
    }
    maxElement = extractMax(elements, priorities, size);

    if (maxElement != -1)
    {
        cout << "Extracted element: " << maxElement << endl;
    }
    maxElement = extractMax(elements, priorities, size);
    if (maxElement != -1)
    {
        cout << "Extracted element: " << maxElement << endl;
    }
    // Attempt to extract from an empty priority queue
    maxElement = extractMax(elements, priorities, size);
    if (maxElement != -1)
    {
        cout << "Extracted element: " << maxElement << endl;
    }
    return 0;
}