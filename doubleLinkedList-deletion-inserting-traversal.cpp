#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtFront(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data) {
    struct Node* new_node;
    if (prev_node == NULL) {
        printf("Hata: Onceki dugum NULL olamaz!\n");
        return;
    }

    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
    printf("\nSecilen dugum silindi.\n");
}

void displayList(struct Node* node) {
    struct Node* last = NULL;
    
    printf("\nIleri Yonlu: ");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");

    printf("Geri Yonlu: ");
    while (last != NULL) {
        printf("%d <-> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30); 

    printf("Baslangic Listesi:");
    displayList(head);

    printf("\n--- 20'den sonra 25 ekleniyor ---");
    insertAfter(head->next, 25);
    displayList(head);

    printf("\n--- 20 dugumu siliniyor ---");
    deleteNode(&head, head->next);
    displayList(head);

    return 0;
}
