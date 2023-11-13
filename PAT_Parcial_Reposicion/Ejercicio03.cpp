#include "Ejercicio03.h"
Node<int>* Ejercicio03::detectCycle(Node<int>* head)
{
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node<int>* slow = head;
    Node<int>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            Node<int>* ptr1 = head;
            Node<int>* ptr2 = slow;

            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            return ptr1;
        }
    }

    return nullptr;
}
