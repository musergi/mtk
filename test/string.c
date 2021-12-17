#include "mtk/string.h"

#include <assert.h>
#include <stdlib.h>

int main() {
  MtkString string;
  MtkString copy;
  MtkString subString, subStringVerification;
  MtkString catString1, catString2, totalString;

  mtkStringInit(&string, "HelloWorld");
  assert(string.length == 10);

  mtkStringInitCopy(&copy, &string);
  assert(string.length == copy.length);
  assert(mtkStringEquals(&string, &copy));
  mtkStringUninit(&copy);

  /* Substring */
  mtkStringInitSub(&subString, &string, 0, 5);
  mtkStringInit(&subStringVerification, "Hello");
  assert(mtkStringEquals(&subString, &subStringVerification));
  mtkStringUninit(&subString);
  mtkStringUninit(&subStringVerification);
  
  mtkStringInitSub(&subString, &string, 5, -1);
  mtkStringInit(&subStringVerification, "Worl");
  assert(mtkStringEquals(&subString, &subStringVerification));
  mtkStringUninit(&subString);
  mtkStringUninit(&subStringVerification);

  mtkStringInitSub(&subString, &string, -5, 0);
  mtkStringInit(&subStringVerification, "World");
  assert(mtkStringEquals(&subString, &subStringVerification));
  mtkStringUninit(&subString);
  mtkStringUninit(&subStringVerification);

  /* Concat */
  mtkStringInit(&catString1, "Hello");
  mtkStringInit(&catString2, "World");
  mtkStringInitConcat(&totalString, &catString1, &catString2);
  assert(mtkStringEquals(&totalString, &string));
  mtkStringUninit(&totalString);
  mtkStringUninit(&catString1);
  mtkStringUninit(&catString2);

  mtkStringInit(&catString1, "Hello");
  mtkStringInit(&catString2, "World");
  mtkStringConcat(&catString1, &catString2);
  assert(mtkStringEquals(&catString1, &string));
  mtkStringUninit(&catString1);
  mtkStringUninit(&catString2);

  mtkStringUninit(&string);
  assert(string.length == 0);
  assert(string.data == NULL);

  return 0;
}
