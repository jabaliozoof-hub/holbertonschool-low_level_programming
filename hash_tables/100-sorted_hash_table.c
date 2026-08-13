#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the new sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * add_to_sorted_list - inserts a node into the sorted doubly linked list
 * @ht: pointer to sorted hash table
 * @node: node to insert
 */
static void add_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
		return;
	}
	if (strcmp(ht->shead->key, node->key) > 0)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}
	tmp = ht->shead;
	while (tmp->snext != NULL && strcmp(tmp->snext->key, node->key) < 0)
		tmp = tmp->snext;
	node->sprev = tmp;
	node->snext = tmp->snext;
	if (tmp->snext == NULL)
		ht->stail = node;
	else
		tmp->snext->sprev = node;
	tmp->snext = node;
}

/**
 * shash_table_set - adds or updates an element in a sorted hash table
 * @ht: pointer to the sorted hash table
 * @key: key string
 * @value: value string
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *tmp;
	char *val_copy;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	for (tmp = ht->array[idx]; tmp != NULL; tmp = tmp->next)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = val_copy;
			return (1);
		}
	}
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		free(val_copy);
		return (0);
	}
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(val_copy);
		free(node);
		return (0);
	}
	node->value = val_copy;
	node->next = ht->array[idx];
	ht->array[idx] = node;
	add_to_sorted_list(ht, node);
	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: pointer to the sorted hash table
 * @key: key string
 *
 * Return: value associated with element, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	node = ht->array[idx];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints the sorted hash table in order
 * @ht: pointer to the sorted hash table
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned char comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		if (comma == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints the sorted hash table in reverse order
 * @ht: pointer to the sorted hash table
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned char comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		if (comma == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: pointer to the sorted hash table
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}
	free(ht->array);
	free(ht);
}
