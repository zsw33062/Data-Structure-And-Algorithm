#include<stdio.h>
#include<stdlib.h>
#include"list.h"
struct person
{
	struct list_head list;
	int age;
};
int main(int argc, char** argv)
{
    int i;
    struct person* p;
    struct person person1;
    struct list_head* pos;

    INIT_LIST_HEAD(&person1.list);

    for (i = 0; i < 5; i++) {
        p = (struct person*)malloc(sizeof(struct person));
        p->age = i * 10;
        list_add(&p->list, &person1.list);
    }

    list_for_each(pos, &person1.list) {
        printf("age = %d\n", ((struct person*)pos)->age);
    }
    system("pause");
    return 0;
}