#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - Creates a new session struct
 * @id: Session identifier
 *
 * Return: Pointer to created session, or NULL on failure
 */
session_t *session_create(int id)
{
	session_t *s;

	s = malloc(sizeof(session_t));
	if (!s)
		return (NULL);

	s->id = id;
	s->data = NULL;
	s->size = 0;

	return (s);
}

/**
 * session_set_data - Sets or updates session data securely
 * @session: Pointer to session struct
 * @data: Pointer to data buffer
 * @size: Size of data in bytes
 *
 * Return: 0 on success, -1 on failure
 */
int session_set_data(session_t *session, const void *data, size_t size)
{
	void *new_data;

	if (!session)
		return (-1);

	if (data && size > 0)
	{
		new_data = malloc(size);
		if (!new_data)
			return (-1);
		memcpy(new_data, data, size);
	}
	else
	{
		new_data = NULL;
		size = 0;
	}

	if (session->data)
	{
		memset(session->data, 0, session->size);
		free(session->data);
	}

	session->data = new_data;
	session->size = size;

	return (0);
}

/**
 * session_destroy - Safely clears and frees a session
 * @session: Pointer to session struct
 */
void session_destroy(session_t *session)
{
	if (!session)
		return;

	if (session->data)
	{
		memset(session->data, 0, session->size);
		free(session->data);
		session->data = NULL;
		session->size = 0;
	}

	free(session);
}
