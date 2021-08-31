# TEDUAlloc
TEDU Alloc C Project
# Design Overview
All functionalities are tested in main.
For explaining what we have done in this homework and code part, we create data blocks
in order to make linked list. With the help of using linked list, we benefit its structure to
implement what we want such as previous and next ones. Also, with using linked list, we hold
pointers’ start and size so that we controlled used and empty spaces in the memory. For the
memory allocation part, we used best fit to use memory more efficiently. As an explanation of
functions and what they do; in Mem_Init function we open a memory for data structures, in
TEDU_alloc function we allocate memory according to the possible situations, in free function
we make allocated memory spaces free, in TEDU_Mem_IsValid function we checked whether
that space is valid or not, in TEDU_GetSize function we checked that whether pointer points the
data structure or not, in TEDU_GetStats function we find the allocated memory, the number of
fragments and average fragment size; according to required things in the homework, we print
necessary calculated values in the end of the function. Finally, in “Complete Specification” part,
we explained these functions and what they do in a detailed way.
# Complete Specification
Firstly, we create block structure in order to hold size, pointer of data block and the
pointer of next and previous. Then we continued with creating the required functions;
• Int Mem_Init(int sizeOfRegion) which creates memory for data structure to use
• Void *TEDU_alloc(int size) which represents every possible situation in order to divide
and allocating the memory for differently. Firstly, it checks if there is a block or not. If
there is no block and if the size of block which is wanted to create fits the memory, datablock structs and its pointer points to beginning of the memory. Otherwise, it doesn't
created and it returns null. If there are more than one block, it checks some other
situations. These are having empty space before first block, having empty space after last
block and having empty spaces between blocks. For deciding on which one occurs it
checks every empty space. Also, this function looks for best empty space for given size
which means best fit. For that reason, function checks that if the given size fits the empty
space or not. After that, it compares new empty space and current best empty space if it
is found. In the end, if it finds suitable empty space, it creates data block and put in the
linked list in a proper way. If it is not the case, it returns null.
• Void *TEDU_Free(void *ptr) which checks whether the given pointer points data block or
not. If that pointer points a data block, it holds that data block then it cleans inside of the
memory which belongs that data block. The linked list is linked according to next and
previous of that data block then that data block is removed. After that it frees the data
block and returns 0. In the other scenario which means ptr points the empty space,
function returns -1.
• Int TEDU_Mem_IsValid(void *ptr) which returns 1 if given pointer points a data block;
otherwise it returns 0.
• Int TEDU_GetSize(void *ptr) which returns the size of that data block if the given pointer
points a data block; otherwise it returns -1.
• Int TEDU_GetStats() which finds stats about the usage of memory. According to that, it
first finds the allocated memory then it prints the percent of used memory, the number
of fragments and the average fragment size. It returns the largest empty size in the end.

