//liste içinden eleman silmek
#include <stdio.h>
#include <stdlib.h>

// baðlý liste düðüm yapýsý
struct node {
    int data;
    struct node *next;
};

// verilen elemaný listeden silen fonksiyon
void delete_node(struct node **head_ref, int key) {
    // baþlangýç düðümü
    struct node* temp = *head_ref, *prev;

    // ilk eleman silinirse
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;   // baþlangýç düðümünü deðiþtir
        free(temp);               // eski düðümü serbest býrak
        return;
    }

    // silinecek elemaný bul
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // eleman bulunamadýysa
    if (temp == NULL) {
        return;
    }

    // elemaný listeden çýkar
    prev->next = temp->next;
    free(temp);   // eski düðümü serbest býrak
}

// baðlý listeyi yazdýran fonksiyon
void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node *head = NULL;

    // baðlý liste oluþtur
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Onceki liste: ");
    print_list(head);

    // elemaný sil
    delete_node(&head, 3);

    printf("\nSonraki liste: ");
    print_list(head);

    return 0;
}

