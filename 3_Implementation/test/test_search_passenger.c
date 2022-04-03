#include "unity.h"

extern void test_search_passenger();
extern void test_delete_passenger();

void setUp()
{

}
void tearDown()
{
  
}

int main(void)
{
  UnityBegin(NULL);
  RUN_TEST(test_search_passenger);
  RUN_TEST(test_delete_passenger);
  return UNITY_END();
}