#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - Creates a new session struct
 * @id: Session string identifier
 * @uid: User ID
 * @data: Pointer to session data buffer
 * @data_len: Length of session data in bytes
 *
 * Return: Pointer to created session, or NULL on failure
 */
session_t *session_create(const char *id, unsigned int uid,
			  const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id)
		return (NULL);

	s = malloc(sizeof(session_t));
	if (!s)
		return (NULL);

	s->id = strdup(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;
	if (data && data_len > 0)
	{
		s->data = malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}
		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}
	else
	{
		s->data = NULL;
		s->data_len = 0;
	}

	return (s);
}

/**
 * session_set_data - Updates data buffer of a session safely
 * @s: Pointer to session struct
 * @data: Pointer to new data buffer
 * @data_len: Length of new data in bytes
 *
 * Return: 1 on success, 0 on failure
 */
int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *new_data = NULL;

	if (!s)
		return (0);

	if (data && data_len > 0)
	{
		new_data = malloc(data_len);
		if (!new_data)
			return (0);
		memcpy(new_data, data, data_len);
	}

	if (s->data)
	{
		memset(s->data, 0, s->data_len);
		free(s->data);
	}

	s->data = new_data;
	s->data_len = (new_data) ? data_len : 0;

	return (1);
}

/**
 * session_destroy - Safely clears and frees session memory
 * @s: Pointer to session struct
 */
void session_destroy(session_t *s)
{
	if (!s)
		return;

	if (s->id)
		free(s->id);

	if (s->data)
	{
		memset(s->data, 0, s->data_len);
		free(s->data);
	}

	free(s);
}
