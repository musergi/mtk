#ifndef MTK_STRING_H
#define MTK_STRING_H

#include <stdbool.h>

typedef struct {
  unsigned int length;
  char *data;
} MtkString;

void mtkStringInit(MtkString *s, const char *content);
void mtkStringInitCopy(MtkString *s, const MtkString *other);
void mtkStringInitSub(MtkString *s, const MtkString *other, int startIndex, int endIndex);
void mtkStringInitConcat(MtkString *s, const MtkString *s1, const MtkString *s2);
void mtkStringConcat(MtkString *s, const MtkString *other);
bool mtkStringEquals(const MtkString *s1, const MtkString *s2);
void mtkStringUninit(MtkString *s);

#endif // MTK_STRING_H
