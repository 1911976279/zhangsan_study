#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* select sort: use int type sort */
void SortAlgSelect(void* data, int len)
/* bubble sort: use int type sort */
void SortAlgBubble(void* data, int len)
/* input sort: use int type sort */
void SortAlgInsert(void* data, int len)
/* shell sort: use int type sort */
void SortAlgShell(void* data, int len)
/* merge sort: use int type sort */
void SortAlgRecurveMerge(void* data, int len)
/* not recurve merge sort: use int type sort */
void SortAlgLoopMerge(int *data, int len)
/* merge sort: use int type sort */
void SortAlgFast(void* data, int len)
/* merge sort: use int type sort */
void SortAlgFastRand(void* data, int len)
void SortAlgBigHeap(int* data, int size)
void SortAlgLittleHeap(int* data, int size);


#endif 