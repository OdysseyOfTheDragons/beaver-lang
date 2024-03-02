#ifndef _VECTOR
#define _VECTOR

/** The type of a `vector`. */
typedef struct Vector vector;

/**
 * Creates a new vector.
 *
 * \param size the initial size
 * \return the empty vector
 */
vector *vector_new (int size);

/**
 * Deletes a vector from memory.
 *
 * \param vec the vector to destroy
 */
void vector_delete (vector * vec);

/**
 * Gets the value at given index.
 *
 * \param vec the vector
 * \param index the index the element is at
 * \return the value at index
 * \raise BAD_INDEX the index is out of bounds
 */
ValueType *vector_get (vector * vec, int index);

/*
 * Sets the value at given index.
 *
 * \param vec the vector
 * \param index the index the element is at
 * \param value the new value
 * \raise BAD_INDEX the index is out of bounds
 */
void vector_set (vector * vec, int index, ValueType * value);

/**
 * Appends the value to the vector.
 *
 * \param vec the vector
 * \param value the added value
 */
void vector_push (vector * vec, ValueType * value);

/**
 * Pops the last value from the vector.
 *
 * \param vec the vector
 * \return the last value
 * \raise EMPTY_OBJECT the vector is empty
 */
ValueType *vector_pop (vector * vec);

/**
 * Inserts value at given index.
 *
 * \param vec the vector
 * \param index the position to insert at
 * \param value the inserted value
 * \raise BAD_INDEX the index is out of bounds
 */
void vector_insert (vector * vec, int index, ValueType * value);

/**
 * Removes the value at given index.
 *
 * \param vec the vector
 * \param index the index to remove at
 * \return the removed value
 * \raise BAD_INDEX the index is out of bounds
 */
ValueType *vector_remove (vector * vec, int index);

/**
 * Returns a shallow copy of the vector.
 *
 * \param vec the vector
 * \return a copy of the vector
 */
vector *vector_copy (vector * vec);

/**
 * Goes through each of the elements in the vector, and calls the function
 * on them.
 *
 * \param vec the vector
 * \param fun the function to call on each item
 */
void vector_foreach (vector * vec, void (*fun) (void *, int));

/**
 * Gets the length of the vector.
 *
 * \param vec the vector
 * \return the size
 */
int vector_length (vector * vec);
#endif
