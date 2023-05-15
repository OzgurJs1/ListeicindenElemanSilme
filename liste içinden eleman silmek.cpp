//liste i�inden eleman silmek
#include <stdio.h>
#include <stdlib.h>

// ba�l� liste d���m yap�s�
struct node {
    int data;
    struct node *next;
};

// verilen eleman� listeden silen fonksiyon
void delete_node(struct node **head_ref, int key) {
    // ba�lang�� d���m�
    struct node* temp = *head_ref, *prev;

    // ilk eleman silinirse
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;   // ba�lang�� d���m�n� de�i�tir
        free(temp);               // eski d���m� serbest b�rak
        return;
    }

    // silinecek eleman� bul
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // eleman bulunamad�ysa
    if (temp == NULL) {
        return;
    }

    // eleman� listeden ��kar
    prev->next = temp->next;
    free(temp);   // eski d���m� serbest b�rak
}

// ba�l� listeyi yazd�ran fonksiyon
void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node *head = NULL;

    // ba�l� liste olu�tur
    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = (struct node*)malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next = (struct node*)malloc(sizeof(struct node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    printf("Onceki liste: ");
    print_list(head);

    // eleman� sil
    delete_node(&head, 3);

    printf("\nSonraki liste: ");
    print_list(head);

    return 0;
}

