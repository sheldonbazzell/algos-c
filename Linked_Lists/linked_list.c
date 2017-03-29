#include <stdio.h>
#include <stdlib.h>

// struct definitions
typedef struct node
{
	int val;
	struct node *next;
}
node;

typedef struct list
{
	struct node *head;
}
list;


void print_list(list *list)
{
	if (list->head != NULL) {
		node *cur = list->head;
		while (cur != NULL)
		{
			printf("%d\n", cur->val);
			cur = cur->next;
		}
	}
}

void append(list *list, int value)
{
	if (list->head == NULL)
	{
		list->head = malloc(sizeof(node));
		list->head->val = value;
		list->head->next = NULL;
	}
	else
	{
		node *cur = list->head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = malloc(sizeof(node));
		cur->next->val = value;
		cur->next->next = NULL;
	}
}

void enqueue(list *list, int value)
{
	if (list->head == NULL)
	{
		list->head = malloc(sizeof(node));
		list->head->val = value;
		list->head->next = NULL;
	}
	else
	{
		node *tmp = list->head;
		list->head = malloc(sizeof(node));
		list->head->val = value;
		list->head->next = tmp;
	}
}

void reverseList(list *list)
{
	node *cur = list->head;
	node *prev = NULL;
	node *nxt;
	while (cur != NULL)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	list->head = prev;
}

int count(list *list)
{
	if (list->head == NULL)
	{
		return 0;
	}
	else
	{
		int length = 0;
		node *cur = list->head;
		while (cur != NULL)
		{
			cur = cur->next;
			length++;
		}
		return length;
	}
}

node *removeKthFromLast(list *list, int k)
{
	node *slow = list->head;
	node *fast = list->head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (k-- < 0) slow = slow->next;
	}
	if (k == 0) fast = fast->next;
	else
	{
		node *tmp = slow->next;
		slow->next = slow->next->next;
		return tmp;
	}
	return list->head;
}

void dequeue(list *list)
{
	if(list->head != NULL)
	{
		node *tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
}

node *recursiveReverse(list *list, node *cur, node *prev)
{
	if (cur == NULL)
	{
		list->head = prev;
		return list->head;
	}
	node *nxt = cur->next;
	cur->next = prev;
	prev = cur;
	return recursiveReverse(list, nxt, prev);
}

int main(void)
{
	// instantiate and test
	list *list;
	append(list, 5);
	append(list, 10);
	append(list, 15);
	enqueue(list, 2);
	recursiveReverse(list, list->head, NULL);
	removeKthFromLast(list, 2);
	print_list(list);


	return 0;

}
