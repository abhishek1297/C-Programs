#include<stdio.h>
#define SIZE 20

struct ll {

    int data,
    next, //next index
    prev; // previous index
} list[SIZE];

int count = 0; // num of elements
int head_ptr, last_ptr; // indices of the first and last numbers in array

void sorted_insert(int data) {

    int i, prev;
    if(count == SIZE) {
        printf("List is Full!\n");
        return;
    }
    if(count != 0) {
        
        if(data <= list[head_ptr].data) {

            list[count].next = head_ptr;
            list[count].prev = last_ptr;
            list[last_ptr].next = head_ptr = count;
        }
        else
        if(data >= list[last_ptr].data) {

            list[last_ptr].next = count;
            list[count].prev = last_ptr;
            last_ptr = count;
            list[count].next = head_ptr;
            list[head_ptr].prev = count;
        }
        else {
            
            i = head_ptr; // current
            do {
                //prev = i;
                i = list[i].next;
            } while(list[i].data <= data);
            //traverse the list until data is greater
            
            list[count].next = i; // newNode.next = current
            list[list[i].prev].next = count; // current.prev.next = newNode
            list[count].prev = list[i].prev; // newNode.prev = current.prev
            list[i].prev = count; // current.prev = newNode
        }
    }
    else {

       head_ptr = last_ptr = list[count].next = list[count].prev = 0;
    }

    list[count++].data = data;
}

void delete_smallest() {

    list[head_ptr].data = 0;
    list[last_ptr].next = head_ptr = list[head_ptr].next;
    list[head_ptr].prev = last_ptr;
    count--;
}

void delete_largest() {

    list[last_ptr].data = 0;
    list[head_ptr].prev = last_ptr = list[last_ptr].prev;
    list[last_ptr].next = head_ptr;
    count--;
}

void delete(int pos) {
    
    int i, k = 0;
    if(pos - 1 < 0 || pos - 1 > count || pos - 1 > SIZE) {
        printf("Invalid Position!\n");
        return;
    }
    if(pos)
        delete_smallest();
    else
    if(pos == count)
        delete_largest();
    else {
        for(i = head_ptr; i != last_ptr && k < pos - 1; k++, i = list[i].next);
    
        list[i].data = 0;
        list[list[i].prev].next = list[i].next;
        list[list[i].next].prev = list[i].prev;
    }
}

void traverse() {
    
    int i;
    if(!count) {
        printf("List Empty!\n");
        return;
    }
    i = head_ptr;//list[last_ptr].next;
    do {
        printf("%d -> ", list[i].data);
        i = list[i].next;
    } while(i != head_ptr);
    printf("END\n");
}

void reverse_traverse() {
    int i;
    if(!count) {
        printf("List Empty!\n");
        return;
    }
    i = last_ptr;
    do {
        printf("%d -> ", list[i].data);
        i = list[i].prev;
    } while(i != last_ptr);
    printf("START\n");
}
    
int main() {
    
    int ch, temp;
    while(1) {
        printf("\n\n");
        traverse();
        printf("\n1.Sorted Insertion\n2.Delete Smallest\n3.Delete Largest\n4.Delete By Position\n5.Reverse Traversal\n6.Exit\n\n>> ");
        scanf("%d", &ch);
        
        switch(ch) {
            
            case 1 :
                printf("\nEnter Data : ");
                scanf("%d", &temp);
                sorted_insert(temp);
            break;
            
            case 2 : delete_smallest(); break;
            
            case 3 : delete_largest(); break;
            
            case 4 : 
                printf("\n Enter Position : ");
                scanf("%d", &temp);
                delete(temp);
            break;
            
            case 5 : reverse_traverse(); break;
            
            case 6 : exit(0);
        }
    }
}
