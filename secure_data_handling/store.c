#include <stdlib.h>
#include "store.h"

/**
 * store_init - Initializes the store structure
 * @store: Pointer to store struct
 */
void store_init(store_t *store)
{
	if (!store)
		return;

	store->head = NULL;
}

/**
 * store_add - Adds a session to the store
 * @store: Pointer to store struct
 * @session: Pointer to session struct
 *
 * Return: 0 on success, -1 on failure or duplicate ID
 */
int store_add(store_t *store, session_t *session)
{
	store_node_t *new_node, *curr;

	if (!store || !session)
		return (-1);

	curr = store->head;
	while (curr)
	{
		if (curr->session && curr->session->id == session->id)
			return (-1);
		curr = curr->next;
	}

	new_node = malloc(sizeof(store_node_t));
	if (!new_node)
		return (-1);

	new_node->session = session;
	new_node->next = store->head;
	store->head = new_node;

	return (0);
}

/**
 * store_get - Retrieves a session by ID
 * @store: Pointer to store struct
 * @id: Session ID to find
 *
 * Return: Pointer to session if found, or NULL
 */
session_t *store_get(store_t *store, int id)
{
	store_node_t *curr;

	if (!store)
		return (NULL);

	curr = store->head;
	while (curr)
	{
		if (curr->session && curr->session->id == id)
			return (curr->session);
		curr = curr->next;
	}

	return (NULL);
}

/**
 * store_delete - Deletes a session by ID
 * @store: Pointer to store struct
 * @id: Session ID to delete
 *
 * Return: 0 on success, -1 on failure or not found
 */
int store_delete(store_t *store, int id)
{
	store_node_t *curr, *prev;

	if (!store || !store->head)
		return (-1);

	curr = store->head;
	prev = NULL;

	while (curr)
	{
		if (curr->session && curr->session->id == id)
		{
			if (prev)
				prev->next = curr->next;
			else
				store->head = curr->next;

			session_destroy(curr->session);
			free(curr);
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}

	return (-1);
}

/**
 * store_destroy - Frees all store nodes and sessions
 * @store: Pointer to store struct
 */
void store_destroy(store_t *store)
{
	store_node_t *curr, *tmp;

	if (!store)
		return;

	curr = store->head;
	while (curr)
	{
		tmp = curr->next;
		if (curr->session)
			session_destroy(curr->session);
		free(curr);
		curr = tmp;
	}

	store->head = NULL;
}
