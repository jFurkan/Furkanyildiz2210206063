#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void printList(Node* head) {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    Node* temp = head;

   
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("(Basa dondu: %d)\n", head->data);
}


void insertAfter(Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("Onceki dugum NULL olamaz.\n");
        return;
    }

    Node* newNode = createNode(data);

   
    newNode->next = prev_node->next;

    
    prev_node->next = newNode;
}


void deleteNode(Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    Node *curr = *head_ref, *prev = NULL;

    
    if (curr->data == key) {
       
        if (curr->next == *head_ref) {
            *head_ref = NULL;
            free(curr);
            return;
        }
        
       
        Node* last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }

      
        last->next = curr->next;
        *head_ref = curr->next;
        free(curr);
        return;
    }

   
    while (curr->next != *head_ref && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

   
    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("Eleman (%d) listede bulunamadi.\n", key);
    }
}


void append(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head_ref;

    
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = *head_ref;
    } else {
        
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head_ref;
    }
}


int main() {
    Node* head = NULL;

   
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    printf("--- Ilk Durum ---\n");
    printList(head);

    
    printf("\n--- 20'den sonraya 25 Eklendi ---\n");
    insertAfter(head->next, 25);
    printList(head);

    
    printf("\n--- 10 (Bas Dugum) Silindi ---\n");
    deleteNode(&head, 10);
    printList(head);

   
    printf("\n--- 25 (Ara Dugum) Silindi ---\n");
    deleteNode(&head, 25);
    printList(head);

    return 0;
}
