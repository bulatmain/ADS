#include <stdio.h>
#include "imap.h"

int main() {
    imap m = create_empty_imap();
    
    imap_item* i1 = new_imap_item(0, 0, NULL, NULL);
    imap_item* i2 = new_imap_item(1, 1, NULL, NULL);
    imap_item* i3 = new_imap_item(2, 2, NULL, NULL);
    imap_item* i4 = new_imap_item(3, 3, NULL, NULL);
    imap_item* i5 = new_imap_item(4, 4, NULL, NULL);

    //m.begin = i1;
    i1->next = i2; i2->prev = i1;
    i2->next = i3; i3->prev = i2;

    i4->next = i5; i5->prev = i4;
    m.back = i5;

    printf("%d - %d\n", is_valid_edges(&m), is_valid(&m));

    make_valid(&m);

    printf("%d - %d\n%ld\n", is_valid_edges(&m), is_valid(&m), m.begin->value);

    //printf("123");

    clear_imap(&m);

    printf("%d\n", is_empty_imap(&m));

    return 0;
}