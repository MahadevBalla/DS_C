#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

int findLength(struct Node* node) {
    if (node == NULL)
        return 0;
    return 1 + findLength(node->next);
}

void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sortList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* i, *j;
    int swapped;

    for (i = head; i->next != NULL; i = i->next) {
        swapped = 0;
        for (j = head; j->next != NULL; j = j->next) {
            if (j->data > j->next->data) {
                swap(j, j->next);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void reverse(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

int main() {
    struct Node* head = NULL;

    append(&head, 5);
    append(&head, 3);
    append(&head, 8);
    append(&head, 2);

    printf("Original List: ");
    displayList(head);

    int length = findLength(head);
    printf("Length of the list: %d\n", length);

    sortList(head);

    printf("Sorted List: ");
    displayList(head);

    return 0;
}