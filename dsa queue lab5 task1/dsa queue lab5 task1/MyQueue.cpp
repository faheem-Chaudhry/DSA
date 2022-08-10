#include "MyQueue.h"
template<class T>
 void MyQueue<T>::enqueue(T value)
{
    if (isEmpty())
    {
        queue[rear] = value;
        count++;
    }
    else
    {
        if (isFull())
        {
            resize(size * 2);
        }
        if (count <= size / 4)
        {
            resize(size / 2);
        }
        rear = (rear + 1) % size;
        queue[rear] = value;
        count++;
    }
    cout << endl;
}


template<class T>
bool MyQueue<T>::isEmpty()
{
    return (max() == 0);
}
template<class T>
bool MyQueue<T>::isFull()
{
    return (max() == size);
}
template<class T>
void MyQueue<T>::dequeue()
{
    cout << "dequeue : " << Front();
    if (isEmpty())
    {
        cout << " error : empty";
    }
     /*      else if (back == front)
           {                           
               back = front = -1;
           }     */
    else
    {
        front = (front + 1) % size;
        count--;
    }
    cout << endl;
}
template<class T>
void MyQueue<T>::print()
{
    if (isEmpty())
    {
        cout << "Queue is empty";
    }
    else
    {
        // ******* IMPORTANT ******
        cout << "Elements in queue are :";
        for (int i = 0; i < count; ++i)
        {
            cout << queue[(front + i) % size] << " ";
        }
    }
    //cout<<"count is:" <<count<<endl;
    cout << endl;
    //      cout << size;
}
template<class T>
T MyQueue<T>::Front()
{

    if (front == -1)
    {
        cout << "Queue is empty\n";
        return queue[front];
    }
    return queue[front];

}
template<class T>
int MyQueue<T>::Rear()
{
    if (rear == -1)
    {
        cout << "Queue is full";
    }
    return array[rear];
}

template<class T>
int MyQueue<T>::max()
{                       //retunn count of array
    return count;
    cout << "count: " << count;

}


template<class T>
void MyQueue<T>::resize(int newsize)
{
    T* temp = new T[newsize];

    for (int i = 0; i < count; ++i)
    {
        temp[i] = queue[(front + i) % size];
    }

    front = 0;
    rear = count - 1;
    delete[]queue;
    queue = temp;
    //    count = newsize;
}


template<class T>
void PriorityQueue<T>::enqueue(T value)
{
    cout << "enqueue " << value << endl;
    int val = 0;                         //variable to store priority
    int k;
    MyQueue<T>::count++;
    for (int i = 0; ; i++)
    {
        k = i + 1;                               // Time Complexity ==n*n
        if (value[i] == ':')
        {
            while (k != value.length())
            {
                val = (val * 10) + (value[k] - 48);
                k++;
            }
            if (val > MyQueue<T>::size)
            {
                MyQueue<T>::resize(val);
            }
            MyQueue<T>::queue[val] = value;
            val = 0;
            break;
        }
    }
}


