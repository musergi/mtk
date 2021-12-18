#include "mtk/string.h"

#include <assert.h>
#include <stdlib.h>

void test_lifetime();
void test_copy();
void test_substring();
void test_concat();

int main() {
  test_lifetime();
  test_copy();
  test_substring();
  test_concat();
  return 0;
}

void test_lifetime() {
  MtkString string;
  mtkStringInit(&string, "HelloWorld");
  assert(string.length == 10);

  mtkStringUninit(&string);
  assert(string.length == 0);
  assert(string.data == NULL);
}

void test_copy() {
  MtkString string, copy;
  mtkStringInit(&string, "HelloWorld");
  mtkStringInitCopy(&copy, &string);
  assert(string.length == copy.length);
  assert(mtkStringEquals(&string, &copy));
  mtkStringUninit(&string);
  mtkStringUninit(&copy);
}

void test_substring() {
  MtkString string, subString, subStringVerification;
  mtkStringInit(&string, "HelloWorld");

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

  mtkStringUninit(&string);
}

void test_concat() {
  MtkString string, catString1, catString2, totalString;
  mtkStringInit(&string, "HelloWorld");

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
}
