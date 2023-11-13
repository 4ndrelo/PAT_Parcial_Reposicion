#include "Ejercicio01.h"

Node<int>* Ejercicio01::addTwoNumbers(Node<int>* l1, int sizeL1, Node<int>* l2, int sizeL2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    Node<int>* result = nullptr;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = carry;

        if (l1 != nullptr)
        {
            sum += l1->value;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            sum += l2->value;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        Node<int>* newNode = new Node<int>{ sum, nullptr };
        newNode->next = result;
        result = newNode;
    }

    return result;
}

Node<int>* Ejercicio01::reverseList(Node<int>* l)
{
    Node<int>* result = nullptr;

    while (l != nullptr)
    {
        Node<int>* next = l->next;
        l->next = result;
        result = l;
        l = next;
    }

    return result;
}
