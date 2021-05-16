#include "unity.h"
#include "unity_fixture.h"
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"

#define SIZE_ARRAY 10

TEST_GROUP(Sort);

static int* ARRAY1;
static int* ARRAY2;

// init two identical arrays with interleaved positive and negative values
static void initArrays(void)
{	
    printf("\n");
    for(int i=0;i<SIZE_ARRAY;i++){
      ARRAY1[i] = SIZE_ARRAY-1-i;
      ARRAY1[i] = i%2 == 0 ? ARRAY1[i] : ARRAY1[i]*-1; // interleaves positive and negative values
      ARRAY2[i] = ARRAY1[i];
    }

}

// check if all elemets in ARRAY1 are in ARRAY2
static bool checkArraysElements(void)
{
  bool usedIndexes[SIZE_ARRAY];
  bool flag = true;
  for(int i=0; i<SIZE_ARRAY; i++)
    usedIndexes[i]=false;

  for(int i=0; i<SIZE_ARRAY; i++)
    for(int j=0; j<SIZE_ARRAY; j++)
      if(ARRAY1[i]==ARRAY2[j] && !usedIndexes[j]){
        usedIndexes[j]=true;
        break;
      }

  for(int i=0; i<SIZE_ARRAY; i++)
    if(!usedIndexes[i]){
      flag = false;
      break;
    }
  return flag;
}


// test the checkArraysElements function
void testCompareArraysFunc(void)
{
  ARRAY2[0] = ARRAY1[SIZE_ARRAY-1];
  ARRAY2[SIZE_ARRAY-1] = ARRAY1[0];
  TEST_ASSERT_MESSAGE(checkArraysElements(),"Error in compareArray function");
}

// check if ARRAY1 is in the correct order
static bool isArray1InCorrectOrder(void){
  for(int i=0; i<SIZE_ARRAY-1; i++)
    if(ARRAY1[i]>ARRAY1[i+1])
      return false;

  return true;
}

TEST_SETUP(Sort)
{
  ARRAY1 = malloc(sizeof(int)*SIZE_ARRAY);
  ARRAY2 = malloc(sizeof(int)*SIZE_ARRAY);
  initArrays();
}

TEST_TEAR_DOWN(Sort)
{
  free(ARRAY1);
  free(ARRAY2);
}

/************************/
/* SORT FUNCTIONS TESTS */
/************************/

// check if the sort function changed any value of the array
TEST(Sort, testCheckIfValuesWereChanged)
{
  sort(ARRAY1,SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(checkArraysElements(),"Sort function changed the values");
}

// check if the restult array is in the correct order
TEST(Sort, testArrayOrder)
{
  sort(ARRAY1,SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(isArray1InCorrectOrder(), "Array is not in order");
}

// check if the sort function changed a single value array
TEST(Sort, testSingleValue)
{
  sort(ARRAY1,1);
  TEST_ASSERT_EQUAL_MESSAGE(ARRAY2[0],ARRAY1[0],"Sort function changes single value array");
}

// check if the sort function works with only zeros array
TEST(Sort, testOnlyZerosValues)
{
    for(int i=0; i<SIZE_ARRAY; i++){
      ARRAY1[i]=0;
      ARRAY2[i]=0;
    }
    sort(ARRAY1,SIZE_ARRAY);
    TEST_ASSERT_MESSAGE(checkArraysElements(),"Sort function changed a zero value");
}
