#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_init - Initializes the store structure
 * @st: Pointer to store struct
 */
void store_init(store_t *st)
{
	if (!st)
		return;

	st->head = NULL;
}

/**
 * store_add - Adds a session to the store
 * @st: Pointer to store struct
 * @s: Pointer to session struct
 *
 * Return: 1 on success, 0 on failure or duplicate ID
 */
int store_add(store_t *st, session_t *s)
{
	node_t *new_node, *curr;

	if (!st || !s || !s->id)
		return (0);

	curr = st->head;
	while (curr)
	{
		if (curr->sess && curr->sess->id && strcmp(curr->sess->id, s->id) == 0)
			return (0);
		curr = curr->next;
	}

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return (0);

	new_node->sess = s;
	new_node->next = st->head;
	st->head = new_node;

	return (1);
}

/**
 * store_get - Retrieves a session by ID
 * @st: Pointer to store struct
 * @id: Session ID string
 *
 * Return: Pointer to session if found, or NULL
 */
session_t *store_get(store_t *st, const char *id)
{
	node_t *curr;

	if (!st || !id)
		return (NULL);

	curr = st->head;
	while (curr)
	{
		if (curr->sess && curr->sess->id && strcmp(curr->sess->id, id) == 0)
			return (curr->sess);
		curr = curr->next;
	}

	return (NULL);
}

/**
 * store_delete - Deletes a session by ID from the store
 * @st: Pointer to store struct
 * @id: Session ID string
 * @out: Pointer to store deleted session pointer, or NULL to destroy
 *
 * Return: 1 if deleted, 0 if not found
 */
int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *curr, *prev = NULL;

	if (!st || !id)
	{
		if (out)
			*out = NULL;
		return (0);
	}

	curr = st->head;
	while (curr)
	{
		if (curr->sess && curr->sess->id && strcmp(curr->sess->id, id) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				st->head = curr->next;

			if (out)
				*out = curr->sess;
			else if (curr->sess)
				session_destroy(curr->sess);

			free(curr);
			return (1);
		}
		prev = curr;
		curr = curr->next;
	}

	if (out)
		*out = NULL;

	return (0);
}

/**
 * store_destroy - Frees all store nodes and sessions
 * @st: Pointer to store struct
 */
void store_destroy(store_t *st)
{
	node_t *curr, *tmp;

	if (!st)
		return;

	curr = st->head;
	while (curr)
	{
		tmp = curr->next;
		if (curr->sess)
			session_destroy(curr->sess);
		free(curr);
		curr = tmp;
	}

	st->head = NULL;
}
