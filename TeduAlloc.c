/////////////////////////////
///////   TEDU_Alloc   /////
//////  Canay Kaplan  /////
///// Egemen Engin   /////
/////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


char* bigPtr = NULL;

typedef struct block {
    char* data;
    int size;
    struct block* next;
    struct block* previous;
}block;

block* firstOne = NULL;
int totalSize = 0;
int usedSize = 0;

int Mem_Init(int sizeOfRegion) {
    totalSize = sizeOfRegion;
    bigPtr = (char*)malloc(sizeof(char) * sizeOfRegion);
    return sizeOfRegion;
}

void* TEDU_alloc(int size) {

    if (firstOne == NULL && totalSize >= size) {

        firstOne = (block*)malloc(sizeof(block));
        firstOne->size = size;
        firstOne->data = bigPtr;

        return firstOne->data;
    }
    else {

        block* temp2 = firstOne;
        block* holder1 = NULL;
        block* holder2 = NULL;
        int currentEmptySize = totalSize;

        if (totalSize - usedSize >= size) {
            while (temp2->next != NULL) {

                if ((temp2->next->data - (temp2->data + temp2->size)) >= size) {

                    if (currentEmptySize > (temp2->next->data - (temp2->data + temp2->size))) {

                        currentEmptySize = (temp2->next->data - (temp2->data + temp2->size));

                        holder1 = temp2;
                        holder2 = temp2->next;

                    }
                }

                temp2 = temp2->next;

            }

            if ((bigPtr + totalSize) - (temp2->data + temp2->size) < currentEmptySize &&
                (bigPtr + totalSize - (temp2->data + temp2->size)) >= size) {

                holder1 = temp2;
                holder2 = NULL;
            }

            if ((firstOne->data - bigPtr) < currentEmptySize && (firstOne->data - bigPtr) >= size && (firstOne->data - bigPtr) > 0) {

                holder1 = NULL;
                holder2 = firstOne;
            }
            if (holder1 == NULL && holder2 == NULL) {
                printf("There is no enough space.\n");
                return NULL;
            }
            else {

                if (holder2 == NULL) {              

                    block* newOne = (block*)malloc(sizeof(block));
                    newOne->size = size;
                    newOne->data = holder1->data + holder1->size;
                    holder1->next = newOne;
                    newOne->previous = holder1;
                    newOne->next = NULL;
                    usedSize += size;

                    return newOne->data;
                }
                else if (holder1 == NULL) {

                    block* newOne = (block*)malloc(sizeof(block));
                    newOne->size = size;
                    newOne->data = bigPtr;
                    newOne->next = holder2;
                    holder2->previous=newOne;
                    firstOne = newOne;
                    usedSize += size;

                    return newOne->data;
                }
                else {                      

                    block* newOne = (block*)malloc(sizeof(block));
                    newOne->size = size;
                    newOne->data = holder1->data + holder1->size;
                    holder1->next = newOne;
                    newOne->previous = holder1;
                    newOne->next = holder2;
                    holder2->previous = newOne;
                    usedSize += size;

                    return newOne->data;

                }
            }

        }
        else {
            printf("There is no enough space.\n");
            return NULL;
        }
    }
}


int TEDU_Free(void* ptr) {

    block* temp2 = firstOne;
    int checker = -1;

    if (ptr == NULL) {
        return -1;
    }
    while (temp2 != NULL) {

        if ((temp2->data) >= ptr && (temp2->data) <= (ptr + totalSize)) {
            usedSize -= temp2->size;                 

            if (temp2->next != NULL && temp2->previous != NULL) {
                temp2->previous->next = temp2->next;
                temp2->next->previous = temp2->previous;

            }
            else if (temp2->previous == NULL && temp2->next == NULL) {

                firstOne = NULL;

            }
            else if (temp2->previous == NULL && temp2->next != NULL) {


                firstOne = temp2->next;
                temp2->next->previous = NULL;

            }
            else if (temp2->next == NULL && temp2->previous != NULL) {

                temp2->previous->next = NULL;

            }

            int i = temp2->size - 1;
            while (i >= 0) {
                char* tempPtr = temp2->data;
                tempPtr[i] = 0;
                i--;
            }
            free(temp2);
            checker = 0;
            break;
        }

        temp2 = temp2->next;
    }
    return checker;
}

int Mem_IsValid(void* ptr) {
    block* temp2 = firstOne;
    while (temp2 != NULL) {
        if (temp2->data == ptr) {
            return 1;
        }
        temp2 = temp2->next;
    }
    return 0;
}

int Mem_GetSize(void* ptr) {

    block* temp2 = firstOne;

    while (temp2 != NULL) {
        if (temp2->data == ptr) {
            return temp2->size;
        }
        temp2 = temp2->next;
    }
    return -1;
}

int TEDU_GetStats() {

    block* temp2 = firstOne;

    int emptyTotalSize = 0;
    int emptyCounter = 0;
    int totalUsedSize = 0;
    int largestEmtpySize = 0;
    int blockCounter = 0;

    if (temp2 == NULL) {

        emptyTotalSize = totalSize;
        emptyCounter = 1;
        largestEmtpySize = totalSize;
        printf("There is %d empty fragmentation and average fragment size is %.2f.\nLargest empty fragment is %d.\n", emptyCounter, ((float)emptyTotalSize / (float)emptyCounter), largestEmtpySize);
        printf("0 percentage of memory is used.\n");
        printf("%d number of block.\n", blockCounter);
        return largestEmtpySize;
    }
    else {
        while (temp2->next != NULL) {

            totalUsedSize += temp2->size;
            blockCounter++;
            if ((temp2->next->data - (temp2->data + temp2->size)) == 0) {
                temp2 = temp2->next;
            }
            else {
                emptyCounter++;
                emptyTotalSize += (temp2->next->data - (temp2->data + temp2->size));
                if ((temp2->next->data - (temp2->data + temp2->size)) > largestEmtpySize) {

                    largestEmtpySize = (temp2->next->data - (temp2->data + temp2->size));
                }
                temp2 = temp2->next;
            }

        }

        totalUsedSize += temp2->size;
        blockCounter++;
        if (((bigPtr + totalSize) - (temp2->data + temp2->size)) != 0) {
            emptyCounter++;
            emptyTotalSize += ((bigPtr + totalSize) - (temp2->data + temp2->size));

            if (((bigPtr + totalSize) - (temp2->data + temp2->size)) > largestEmtpySize) {

                largestEmtpySize = ((bigPtr + totalSize) - (temp2->data + temp2->size));
            }
        }
        if ((firstOne->data - bigPtr) != 0) {
            emptyCounter++;
            emptyTotalSize += ((bigPtr + totalSize) - (temp2->data + temp2->size));
            if ((firstOne->data - bigPtr) > largestEmtpySize) {
                largestEmtpySize = (firstOne->data - bigPtr);
            }
        }
        if (emptyCounter == 0) {
            printf("There is no empty fragmentation.\n");
        }

        else {
            printf("There is %d empty fragmentation and average fragment size is %.2f.\nLargest empty fragment is %d.\n", emptyCounter, ((float)emptyTotalSize / (float)emptyCounter), largestEmtpySize);
        }

        printf("%.2f percentage of memory is used.\n", ((float)totalUsedSize / (float)totalSize) * 100);
        printf("%d number of block.\n", blockCounter);
    }

    return largestEmtpySize;
}

