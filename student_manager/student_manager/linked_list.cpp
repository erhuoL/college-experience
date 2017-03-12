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
