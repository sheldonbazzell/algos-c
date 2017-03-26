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

// current list of methods
void print_list(list *list);
void append(list *list, int value);
void enqueue(list *list, int value);

int main(void)
{
	// instantiate and test
	list *list;
	append(list, 5);
	append(list, 10);
	append(list, 15);
	enqueue(list, 2);
	print_list(list);

	return 0;

}


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