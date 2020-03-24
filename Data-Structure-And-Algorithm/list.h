#pragma once
struct list_head {
	struct list_head* next, * prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }   

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)


//遍历链表

#define list_for_each(pos,head) \
	for(pos =(head)->next;pos!=(head);\
	pos=pos->next)
//链表初始化
static inline void INIT_LIST_HEAD(struct list_head* list)
{
	list->next = list;
	list->prev = list;
}

static inline void __list_add(struct list_head* new,
								struct list_head* prev,
								struct list_head* next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}
//增加节点
static inline void list_add(struct list_head* new, struct list_head* head)
{
	__list_add(new, head, head->next);
}