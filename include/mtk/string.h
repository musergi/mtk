#ifndef MTK_STRING_H
#define MTK_STRING_H

#include <stdbool.h>

/**
 * @brief Structure holding a string
 *
 * @var length length of the string
 * @var data buffer containing the null terminated characters of the string
 */
typedef struct {
  unsigned int length;
  char *data;
} MtkString;

/**
 * @brief Initializes the string.
 *
 * Initializes the passed string by allocating the necessary space to allocate the string and the null terminator. It
 * then copies the contents of content into the allocated buffer. Content must be null terminated, if not, this function
 * provides undefined behaviour.
 *
 * @param string String to be initialized
 * @param content C-style string to use as content
 */
void mtkStringInit(MtkString *string, const char *content);

/**
 * @brief Initializes a string identical to another string.
 *
 * Initializes the passed string by allocating the same size as other. It then copies the contents of other into the
 * allocated buffer.
 *
 * @param string String to be initialized
 * @param other Original string to be copied
 */
void mtkStringInitCopy(MtkString *string, const MtkString *other);

/**
 * @brief Initializes a string with a subset of another string.
 *
 * Initializes the passed string by allocating the necessary space to allocate the subset and a null terminator. It then
 * copies other contents into the allocated buffer. Negative indexing implies counting from the end (e.g. index -1 is
 * the last index of the array). A 0 value for the end Index is equivalent to passing other.length (e.g. indices (0, 0)
 * imply the entire string).
 *
 * @param string String to be initialized
 * @param other String to extract the subset from
 * @param startIndex starting index of the subset
 * @param endIndex index after the end index of the subset
 */
void mtkStringInitSub(MtkString *string, const MtkString *other, int startIndex, int endIndex);

/**
 * @brief Initializes a string with the concatenation of two others.
 *
 * @param s String to be initialized
 * @param s1 First string of the result
 * @param s2 Second string of the result
 */
void mtkStringInitConcat(MtkString *string, const MtkString *s1, const MtkString *s2);

/**
 * @brief Concatenates two strings into the first.
 *
 * @param string String to store the new concatenated string
 * @param other String to be appended to string
 */
void mtkStringConcat(MtkString *string, const MtkString *other);

/**
 * @brief Checks string equality.
 *
 * @param s1 First string of the equality
 * @param s2 Second string of the equality
 * @return True if the string are equal False otherwise
 */
bool mtkStringEquals(const MtkString *s1, const MtkString *s2);

/**
 * @brief Uninitializes a string.
 *
 * @param string String to be uninitialized
 */
void mtkStringUninit(MtkString *string);

#endif // MTK_STRING_H
