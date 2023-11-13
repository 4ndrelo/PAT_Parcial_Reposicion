#include "Ejercicio02.h"

Node<char>* Ejercicio02::reverseKGroup(Node<char>* head, int k)
{
    if (head == nullptr || k == 1) {
        return head;
    }

    Node<char>* dummy = new Node<char>();
    dummy->next = head;

    Node<char>* prev = dummy;
    Node<char>* curr = head;
    int count = 0;

    while (curr != nullptr) {
        count++;

        if (count % k == 0) {
            prev = reverseNodes(prev, curr->next);
            curr = prev->next;
        }
        else {
            curr = curr->next;
        }
    }

    return dummy->next;
}

Node<char>* Ejercicio02::reverseNodes(Node<char>* start, Node<char>* end)
{
    Node<char>* prev = start->next;
    Node<char>* curr = prev->next;

    while (curr != end) {
        Node<char>* nextNode = curr->next;
        curr->next = start->next;
        start->next = curr;
        prev->next = nextNode;
        curr = nextNode;
    }

    return prev;
}

