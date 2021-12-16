#include "mtk/string.h"

#include <assert.h>
#include <stdlib.h>

int main() {
  MtkString string;
  MtkString copy;
  MtkString subString, subStringVerification;

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
  
  mtkStringUninit(&string);
  assert(string.length == 0);
  assert(string.data == NULL);

  return 0;
}
