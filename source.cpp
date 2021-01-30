#include <stdio.h>
#include <stdlib.h>

struct Node {
    int index;
    Node *next, *prev;
};

Node *top;

Node *createNode (int index) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->index = index;
    temp->next = temp->prev = NULL;
    return temp;
}

void pushStack(int index) {
    Node *temp = createNode(index);

    if (!top) {
        top = temp;
    }else {
        top->prev = temp;
        temp-> next = top;
        top = temp;
    }
}

void removeStack() {
    if (!top) {
        return;
    } else if (top->next == NULL) {
        free(top);
        top = NULL;
    } else {
        Node *newTop = top->next;
        top->next = newTop->prev = NULL;
        free(top);
        top = newTop;
    }

}

void CookBookMenu(){
    printf("this is cook book\n");
    getchar();
    getchar();
}

void KitchenMenu() {
    printf("this is kitchen\n");
    getchar();
    getchar();
}

void PantryMenu() {

    printf("this is pantry\n");
    getchar();
    getchar();
}

void ProfileMenu() {

    printf("this is Profile\n");
    getchar();
    getchar();
}

void HomePage() {
    printf("this is Home Page\n");
    getchar();
    getchar();
}



int main() {
    
    int menuChoice;
    bool ask = true;

    while (ask) {
        system("cls");
        puts("========================================");
        puts("\t\tMain Menu");
        puts("========================================");
        puts("Welcome To Whisk");
        puts("Your Personal Cooking Assistant");
        printf("========================================\n");
        printf("Please Select Menu Below:\n");
        printf("1. Home Page\n");
        printf("2. Cook Book\n");
        printf("3. Kitchen\n");
        printf("4. Pantry\n");
        printf("5. Profile Menu\n");
        printf("6. Exit\n");
        scanf("%d",&menuChoice);
        switch(menuChoice) {
            case 1: HomePage(); break;
            case 2: CookBookMenu(); break;
            case 3: KitchenMenu(); break;
            case 4: PantryMenu(); break;
            case 5: ProfileMenu(); break;
            case 6: ask = false; break;
            default: printf("Menu tidak tersedia\n"); getchar(); getchar(); break;
        }
    }
    

    return 0;
}