#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define CONVERT_CHAR(c) ((int)c - (int)'a')

// structs
typedef struct trieNode
{
	bool isEntry;
	struct trieNode *children[26];
} trieNode;

typedef struct trie
{
	trieNode *root;
} trie;


// current methods
void insert(trieNode *root, char *word);
bool validWord(trieNode *root, char *word);
trieNode *newNode(void);

int main(void)
{
	trie *t;
	t->root = newNode();
	insert(t->root,"cat");
	bool x = validWord(t->root, "cat");
	printf("%s\n", x ? "true" : "false");
	return 0; 
}

trieNode *newNode(void)
{
	// create our node to be added as needed for insertion
	trieNode *nuNode = malloc(sizeof(trieNode));

	if (nuNode != NULL)
	{

		nuNode->isEntry = false;

		for (int i = 0; i < 26; i++)
			nuNode->children[i] = NULL;

	}
	return nuNode;
}

void insert(trieNode *root, char *word)
{

	int level, index;
	trieNode *cur = root;

	for (level = 0; level < strlen(word); level++)
	{
		index = CONVERT_CHAR(word[level]);

		if ( !cur->children[index] )
			cur->children[index] = newNode();

		cur = cur->children[index];
	}

	cur->isEntry = true;

}

bool validWord(trieNode *root, char *word)
{
	int index;
	trieNode *cur = root;

	for (int level = 0; level < strlen(word); level++)
	{
		index = CONVERT_CHAR(word[level]);

		if ( !cur->children[index] )
			return false;

		cur = cur->children[index];
	}

	return cur->isEntry;

}

