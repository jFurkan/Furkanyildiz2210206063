#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next; 
    struct Node* prev; 
    
    
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

/
void printList(Node* node) {
    Node* last;
    printf("\nIleri Yonlu Gezinme: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        last = node; 
        node = node->next;
    }
    printf("NULL\n");

    printf("Geri Yonlu Gezinme:  ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}


void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Hata: Onceki dugum NULL olamaz.\n");
        return;
    }

    
    Node* newNode = createNode(new_data);

   
    newNode->next = prev_node->next;

   
    prev_node->next = newNode;

    
    newNode->prev = prev_node;

   
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}


void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

   
    if (*head_ref == del)
        *head_ref = del->next;

   
    if (del->next != NULL)
        del->next->prev = del->prev;

   
    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del); 
}


void append(Node** head_ref, int new_data) {
    Node* newNode = createNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
}

int main() {
    Node* head = NULL;

 
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    
    printf("--- Baslangic Listesi ---");
    printList(head);

   
    printf("\n--- 20'den sonraya 25 Eklendi ---");
    insertAfter(head->next, 25); 
    printList(head);

    
    printf("\n--- 20 Silindi ---");
    
    deleteNode(&head, head->next); 
    printList(head);

    return 0;
}
