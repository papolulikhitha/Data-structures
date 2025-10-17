#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL, *end = NULL;
int count = 0;
void create_nodes() {
    int info;
   

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
     printf("Overflow\n");
        return;
    }
    printf("Enter data into the node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = NULL;
    if (head == NULL) {
        head = end = newnode;
        end->next = head;  // Making it circular
    } else {
        end->next = newnode;
        end = newnode;
        end->next = head;  // Maintain circular link
    }
    count++;
}
void display() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    temp = head;
    printf("\nCircular Linked List: ");
  


  do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}
void insert_begin() {
    int info;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not created\n");
        return;
    }
    printf("\nEnter data into node: ");
    scanf("%d", &info);
    newnode->data = info;
    if (head == NULL) {
        head = end = newnode;
        end->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        end->next = head;  // Maintain circular link
    }
    count++;
    printf("Node is added\n");
}



void insert_end() {
    create_nodes();
}
void insert_at_any_position() {
    int info, pos, i;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not created\n");
        return;
    }
    printf("\nEnter data into node: ");
    scanf("%d", &info);
    newnode->data = info;

    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1) {
        printf("\nInvalid position!\n");
        free(newnode);
        return;
    }
    if (pos == 1) {
        insert_begin();
        return;
    } else if (pos == count + 1) {
        insert_end();
        return;
    }
   

 temp = head;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    count++;
    printf("\nNode is added\n");
}
void delete_beg() {
    struct node *temp;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    temp = head;
    if (head == end) {
        head = end = NULL;
    } else {
        head = head->next;
        end->next = head;  // Maintain circular link
    }
    free(temp);
    count--;
    printf("\n---Node is Deleted---\n");
}
void delete_end() {
    struct node *curr, *prev;
    if (head == NULL) {
      

  printf("\nList is empty\n");
        return;
    }
    curr = head;
    if (head == end) {  // Only one node
        free(head);
        head = end = NULL;
    } else {
        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        end = prev;
        free(curr);
    }
    count--;
    printf("\n---Node is Deleted---\n");
}
void delete_any_pos() {
    int pos, i;
    struct node *temp, *prev;
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count) {
       

 printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        delete_beg();
        return;
    }
    temp = head;
    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    if (temp == end) {
        end = prev;
    }
    free(temp);
    count--;
    printf("Node is deleted at position %d\n", pos);
}
void search() {
    int key, flag = 0;
    struct node *curr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

   
 do {
        if (curr->data == key) {
            printf("Element found\n");
            flag = 1;
            break;
        }
        curr = curr->next;
    } while (curr != head);

    if (flag == 0) {
        printf("Element not found\n");
    }
}
int main() {
    int ch;
    while (1) {
        printf("\n******* MENU *******");
        printf("\n1. Create\n2. Display\n3. Size of list\n4. Insert at Beginning\n5. Insert at End");
        printf("\n6. Insert at Any Position\n7. Delete from Beginning\n8. Delete from End");
        printf("\n9. Delete from Any Position\n10. Search\n11. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create_nodes(); break;
            case 2: display(); break;
            case 3: printf("\nNo. of nodes: %d\n", count); break;
            case 4: insert_begin(); break;
            case 5: insert_end(); break;
            case 6: insert_at_any_position(); break;
            case 7: delete_beg(); break;
            case 8: delete_end(); break;
            case 9: delete_any_pos(); break;
            case 10: search(); break;
            case 11: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
