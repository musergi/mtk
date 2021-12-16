#include "mtk/string.h"

#include <stdlib.h>
#include <string.h>

void mtkStringInit(MtkString *s, const char *content) {
  s->length = strlen(content);
  s->data = (char *)malloc(s->length + 1);
  memcpy(s->data, content, s->length + 1);
}

void mtkStringInitCopy(MtkString *s, const MtkString *other) {
  s->length = other->length;
  s->data = (char *)malloc(s->length + 1);
  memcpy(s->data, other->data, s->length + 1);
}

void mtkStringInitSub(MtkString *s, const MtkString *other, int startIndex, int endIndex) {
  unsigned int parsedStartIndex, parsedEndIndex;
  if (startIndex < 0) {
    parsedStartIndex = other->length + startIndex;
  } else {
    parsedStartIndex = startIndex;
  }
  if (endIndex < 0) {
    parsedEndIndex = other->length + endIndex;
  } else {
    parsedEndIndex = endIndex;
  }
  s->length = parsedEndIndex - parsedStartIndex;
  s->data = (char *)malloc(s->length + 1);
  memcpy(s->data, other->data + startIndex, s->length);
  s->data[s->length] = '\0';
}

bool mtkStringEquals(const MtkString *s1, const MtkString *s2) {
  unsigned int i;
  if (s1->length != s2->length)
    return false;
  for (i = 0; i < s1->length; i++) {
    if (s1->data[i] != s2->data[i])
      return false;
  }
  return true;
}

void mtkStringUninit(MtkString *s) {
  free(s->data);
  s->data = NULL;
  s->length = 0;
}
