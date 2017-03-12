# Introduction #

In computer science, a linked list is a linear collection of data elements, in which linear order is not given by their physical placement in memory. Instead, each element points to the next. (wikipedia)


The definition writed by c code was:

    struct student {
	char *name;
	unsigned int stuNum;
	int eng;
	};

	struct node
	{
		struct student stu;
		struct node *next;
	};
**The data of the node can be everything.char, int or struct and etc.**

The memory of it is different from array;

**Linked list** 


the memory of linked list is likely to discrete.one node's address is 0x00001,the next is 0x00002 or another.

**Array**

The memory of array is consecutive.array[0] (0x001),array[1] (0x002)...

So,one array will usually apply for sizable consecutive memory.Instead,linked list's memory is fragmentary and small.

# Category #

There are common linked lists:single linked list,double linked list and circular linked list.
![](https://i.imgur.com/k86Mkee.png)

**Single linked list:**

which is consisted of  memeory structure by one "next pointer".

1. one node incude data and next pointer.
2. first node is the head of the linkd list,the last is the tail.
3. the last node's next pointer is Null.
4. the diretion is single.

# Operation	

![](https://i.imgur.com/1hyaplS.png)

# Code Implementation #

-  **interface declarations**
-  
    #include "stdafx.h"
    #ifndef LLIST_H
    #define LLIST_H
    
    typedef void node_proc_fun_t(void*);
    typedef int node_comp_fun_t(const void*, const void*);
    
    typedef void LLIST_T;
    
    LLIST_T *llist_new(int elmsize);
    int llist_delete(LLIST_T *ptr);
    
    int llist_node_append(LLIST_T *ptr, const void *datap);
    int llist_node_prepend(LLIST_T *ptr, const void *datap);
    
    int llist_travel(LLIST_T *ptr, node_proc_fun_t *proc);
    
    void llist_node_delete(LLIST_T *ptr, node_comp_fun_t *comp, const void *key);
    void *llist_node_find(LLIST_T *ptr, node_comp_fun_t *comp, const void *key);
    
    #endif
- **interface Implementation**

        #include "stdafx.h"
    	#include "linked_list.h"
    	#include <stdlib.h>
    	#include <stdio.h>
    	struct node_st {
     	void *datap;
     	struct node_st *next, *prev;
    	};
    
    	struct llit_st {
    	 struct node_st head;
    	 int lmsize;
     	int elmnr;
    	};
    
    	LLIST_T *
    	llist_new(int elmsize) {
    	struct llist_st *newlist;
    	newlist =malloc(sizeof(struct llist_st));
    	if (newlist == NULL)
    		return NULL;
    	newlist->head.datap = NULL;
    	newlist->head.next = &newlist->head;
    	newlist->head.prev = &newlist->head;
    	newlist->elmsize = elmsize;
    	return (void *)newlist;
    	}
    
    	int llist_delete(LLIST_T *ptr) {
    	struct llist_st *me = ptr;
    	struct node_st *curr, *save;
    	for (curr = me->head.next;
    		curr != &me->head; curr = save) {
    		save = curr->next;
    		free(curr->datap);
    		free(curr);
    	}
    	free(me);
    	return;
    	}
    
    	int llist_node_append(LLIST_T *ptr, const void *datap) {
    	struct llist_st *me = ptr;
    	struct node_st *newnodep;
    	newnodep = malloc(sizeof(struct node_st));
    	if (newnodep == NULL)
    		return -;
    	newnodep->datap = malloc(me->elmsize);
    	if (newnodep->datap == NULL) {
    		free(newnodep);
    		return -;
    	}
    	memcpy(newnodep->datap, datap, me->elmsize);
    	me->head.prev->next = newnodep;
    	newnodep->prev = me->head.prev;
    	me->head.prev = newnodep;
    	newnodep->next = &me->head;
    	return;
    	}	
    
    	int llist_node_prepend(LLIST_T *ptr, const void *datap) {
    	struct llist_st *me = ptr;
    	struct node_st *newnodep;
    	newnodep = malloc(sizeof(struct node_st));
    	if (newnodep == NULL)
    		return -;
    	newnodep->datap = malloc(me->elmsize);
    	if (newnodep->datap == NULL) {
    		free(newnodep);
    		return -;
    	}
    	memcpy(newnodep->datap, datap, me->elmsize);
    	me->head.next->prev = newnodep;
    	newnodep->next = me->head.next;
    	me->head.next = newnodep;
    	newnodep->prev = &me->head;
    	return;
    	}
    
    	int llist_travel(LLIST_T *ptr, node_proc_fun_t *proc) {
    	struct llist_st *me = ptr;
    	struct node_st *curr;
    	for (curr = me->head.next;
    		curr != &me->head; curr = curr->next)
    		proc(curr->datap); // proc(something you like)
    	return;
    	}
    
    	void llist_node_delete(LLIST_T *ptr,
    	node_comp_fun_t *comp,
    	const void *key) {
    	struct llist_st *me = ptr;
    	struct node_st *curr;
    	for (curr = me->head.next;
    		curr != &me->head; curr = curr->next) {
    		if ((*comp)(curr->datap, key) == ) {
    			struct node_st *_next, *_prev;
    			_prev = curr->prev; _next = curr->next;
    			_prev->next = _next; _next->prev = _prev;
    			free(curr->datap);
    			free(curr);
    			break;
    		}
    	}
    	return;
    	}
    
    	void *llist_node_find(LLIST_T *ptr,
    	node_comp_fun_t *comp, const void *key) {
    	struct llist_st *me = ptr;
    	struct node_st *curr;
    	for (curr = me->head.next;
    		curr != &me->head; curr = curr->next) {
    		if ((*comp)(curr->datap, key) == )
    			return curr->datap;
    	}
    	return NULL;
    	}
