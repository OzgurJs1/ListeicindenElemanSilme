//liste içinden eleman silmek
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

void delete_node(struct node **head_ref, int key) {
    // baþlangýç düðümü
    struct node* temp = *head_ref, *prev;

    // ilk eleman silinirse
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;  
        free(temp); 
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);   // eski düðümü serbest býrak
}

void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node *head = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Onceki liste: ");
    print_list(head);

    delete_node(&head, 3);

    printf("\nSonraki liste: ");
    print_list(head);

    return 0;
}

