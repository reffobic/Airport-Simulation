//
//  DEQ.h
//  Project
//
//  Created by Farida Ragheb 900225892 and Mohamed El-Refai 900222334.
//


#ifndef DEQ_h
#define DEQ_h

template <typename T>
class DEQ
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node* front;
    Node* rear;
    int length;
    int capacity;

public:
    DEQ() // Constructor
    {
        front = nullptr;
        rear = nullptr;
        length = 0;
        capacity = 100; // Set the capacity to a default value
    }

    ~DEQ() // Destructor
    {
        // Implement destructor logic here if needed
    }

    bool DEQisEmpty() // Test if the DEQ is empty
    {
        return (length == 0);
    }

    bool DEQisFull() // Test if the DEQ is full
    {
        return (length == capacity);
    }

    void AddFront(T item) // Add an element at the front
    {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (DEQisEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->next = front;
            front = newNode;
        }

        length++;
    }

    void AddRear(T item) // Add an element at the rear
    {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (DEQisEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        length++;
    }

    void RemoveFront() // Remove the element at the front
    {
        if (!DEQisEmpty())
        {
            Node* temp = front;
            front = front->next;
            delete temp;
            length--;
        }
    }

    void RemoveRear() // Remove the element at the rear
    {
        if (!DEQisEmpty())
        {
            Node* current;

            if (front == rear)
            {
                delete front;
                front = nullptr;
                rear = nullptr;
            }
            else
            {
                current = front;
                while (current->next != rear)
                {
                    current = current->next;
                }
            }

            delete rear;
            rear = current;
            rear->next = nullptr;
        }

        length--;
    }

    T ViewFront() // Retrieve the front element without removal
    {
        if (!DEQisEmpty())
        {
            return front->data;
        }

        // Return a default value if the DEQ is empty
        return T();
    }

    T ViewRear() // Retrieve the rear element without removal
    {
        if (!DEQisEmpty())
        {
            return rear->data;
        }

        // Return a default value if the DEQ is empty
        return T();
    }

    int DEQlength() // Number of elements in the DEQ
    {
        return length;
    }
};

#endif
