#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("(Başa Dönüldü)\n");
    } else {
        printf("Liste bos.\n");
    }
}

void insertAfter(struct Node* head, int target, int newData) {
    struct Node* temp = head;
    struct Node* newNode;

    if (head == NULL) return;

    do {
        if (temp->data == target) {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = newData;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("%d degeri listede bulunamadi.\n", target);
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node *curr = *head_ref, *prev = NULL;

    if (*head_ref == NULL) return;

    if (curr->data == key && curr->next == *head_ref) {
        free(curr);
        *head_ref = NULL;
        return;
    }

    if (curr->data == key) {

        while (curr->next != *head_ref) {
            curr = curr->next;
        }
        curr->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = curr->next;
        return;
    }

    curr = *head_ref;
    while (curr->next != *head_ref && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    }
}

struct Node* addToEmpty(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp; 
    return temp;
}

int main() {
    struct Node* head = NULL;

    head = addToEmpty(head, 10);
    insertAfter(head, 10, 20);
    insertAfter(head, 20, 30);
    insertAfter(head, 30, 40);

    printf("Liste ilk hali: ");
    display(head);

    printf("\n20'den sonra 25 ekleniyor...");
    insertAfter(head, 20, 25);
    display(head);

    printf("\n30 degeri siliniyor...");
    deleteNode(&head, 30);
    display(head);

    return 0;
}
