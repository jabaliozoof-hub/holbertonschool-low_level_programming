#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A dog structure
 * @name: The name of the dog
 * @age: The age of the dog
 * @owner: The owner of the dog
 *
 * Description: Defines a new type struct dog with name, age, and owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
