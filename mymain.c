////////////////////////////////////
//////// CMPE 382 Project2 /////////
///////      MAIN PART     //////////
/////  Canay Kaplan 13975913008 ////
///// Egemen Engin 43144164030 /////
///////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "TeduAlloc.c"

int main(int argc, char* argv[]) {

    printf("\n------------------------------------------------\n");

    int tempSize = Mem_Init(50 * 1024 * 1024);

    printf("\nALLOCATION TESTS FOR SMALL OBJECTS\n");

    char* test1 = TEDU_alloc(100 * 1024);
    int *test2 = TEDU_alloc(100 * 1024);
    char *test3 = TEDU_alloc(100 * 1024);

    printf("Starting address of test1:%p\n", test1);
    printf("Starting address of test2:%p\n", test2);
    printf("Starting address of test3:%p\n", test3);

    int freeTest2 = TEDU_Free(test2);
    printf("Is test2 valid or not after free: %d\n", Mem_IsValid(test2));

    char* test4 = TEDU_alloc(16 * 1024);
    printf("Starting address of test4:%p\n", test4);
    printf("It means it is located test4 to best place which is between test1 and test3.\n");
    printf("Also test2 and test4 starting address is equal.\n");

    int *test5 = TEDU_alloc(84 * 1024);
    
    printf("\nSTATS\n");

    int smallGetStats = TEDU_GetStats();

    printf("Is test1 valid or not: %d\n", Mem_IsValid(test1));
    printf("Is test3 valid or not: %d\n", Mem_IsValid(test3));
    printf("Size of test4 %d\n", Mem_GetSize(test4));
    printf("Size of test5 %d\n", Mem_GetSize(test5));
    printf("Size of test1 %d\n", Mem_GetSize(test1));

    printf("\nFREE TESTS FOR SMALL OBJECTS\n");

    int freeTest1 = TEDU_Free(test1);
    int freeTest3 = TEDU_Free(test3);
    int freeTest4 = TEDU_Free(test4);
    int freeTest5 = TEDU_Free(test5);

    printf("In free method, 0 means operation is successful, -1 means operation is failed.\n");
    printf("Results of free methods for small objects:\n");
    printf("Test1: %d , Test2: %d , Test3: %d , Test4: %d  , Test5: %d\n", freeTest1, freeTest2, freeTest3, freeTest4, freeTest5);
    printf("\nSTATS\n");

    smallGetStats = TEDU_GetStats();

    printf("\n------------------------------------------------\n");

    printf("\nALLOCATION TESTS FOR SMALL & LARGE OBJECTS\n");

    char* test6 = TEDU_alloc(10 * 1024 * 1024);
    int* test7 = TEDU_alloc(5 * 1024 * 1024);
    char* test8 = TEDU_alloc(100 * 1024);
    char* test9 = TEDU_alloc(100 * 1024);
    int* test10 = TEDU_alloc(19 * 1024 * 1024);
    char* test11 = TEDU_alloc(10 * 1024 * 1024);
    char* test12 = TEDU_alloc(5 * 1024 * 1024);

    printf("\nSTATS\n");

    int largeGetStats = TEDU_GetStats();

    printf("Is test6 valid or not: %d\n", Mem_IsValid(test6));
    printf("Is test7 valid or not: %d\n", Mem_IsValid(test7));
    printf("Is test8 valid or not: %d\n", Mem_IsValid(test8));
    printf("Size of test9 %d\n", Mem_GetSize(test9));
    printf("Size of test10 %d\n", Mem_GetSize(test10));
    printf("Size of test11 %d\n", Mem_GetSize(test11));
    printf("FREE LARGEST DATA BLOCK...\n");

    int freeTest10 = TEDU_Free(test10);

    printf("In free method, 0 means operation is successful, -1 means operation is failed.\n");
    printf("Results of free methods for test10:%d \n", freeTest10);

    printf("\nSTATS\n");
    largeGetStats = TEDU_GetStats();
    printf("After free, validation of test10: %d\n", Mem_IsValid(test10));
    printf("FREE LAST 2 DATA BLOCKS\n");
    int freeTest11 = TEDU_Free(test11);
    int freeTest12 = TEDU_Free(test12);
    printf("In free method, 0 means operation is successful, -1 means operation is failed.\n");
    printf("Results of free methods for test11:%d  test12:%d \n", freeTest11, freeTest12);

    printf("FREE FIRST DATA BLOCK\n");
    int freeTest6 = TEDU_Free(test6);
    printf("In free method, 0 means operation is successful, -1 means operation is failed.\n");
    printf("Results of free methods for test6:%d \n", freeTest6);

    printf("\nSTATS\n");
    largeGetStats = TEDU_GetStats();

    printf("\n------------------------------------------------\n");

}

