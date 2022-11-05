#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void SwapData(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

static void MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	//分解
	MergeSort(a, left, mid, tmp);
	MergeSort(a, mid + 1, right, tmp);

	//合并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + left, tmp + left, (right - left + 1) * 4);
}

static void QuickSort(int num[], int low, int high)
{
	int i = low;
	int j = high;
	int temp = num[low];   //任命为中间分界线，左边比他小，右边比他大,通常第一个元素是基准数

	if (i > j)  //如果下标i大于下标j，函数结束运行
	{
		return;
	}

	while (i != j) {
		while (num[j] >= temp && j > i) {
			j--;
		}

		while (num[i] <= temp && j > i) {
			i++;
		}

		if (j > i) {
			SwapData(&num[i], &num[j]);
		}
	}

	num[low] = num[i];
	num[i] = temp;

	QuickSort(num, low, i - 1);
	QuickSort(num, i + 1, high);
}

static int GenerateRandValue(int low, int high)
{
	if (low >= high) {
		return low;
	}
	srand((unsigned int)time(NULL));
	return rand() % (high - low) + low;
}

static void QuickSortRand(int num[], int low, int high)
{
	int i = low;
	int j = high;

	SwapData(&num[GenerateRandValue(low, high)], &num[low]);
	int temp = num[low];   //任命为中间分界线，左边比他小，右边比他大,通常第一个元素是基准数

	if (i > j)  //如果下标i大于下标j，函数结束运行
	{
		return;
	}

	while (i != j) {
		while (num[j] >= temp && j > i) {
			j--;
		}

		while (num[i] <= temp && j > i) {
			i++;
		}

		if (j > i) {
			SwapData(&num[i], &num[j]);
		}
	}

	num[low] = num[i];
	num[i] = temp;

	QuickSortRand(num, low, i - 1);
	QuickSortRand(num, i + 1, high);
}

// sort up, big heap, adjust down
static void SortUpAdjustDown(int* data, int size, int pos) // pos是要进行向下调整的数的下标
{
	if (data == NULL || size <= 0 || pos >= size) {
		return;
	}
	size_t parent = pos;
	size_t child = parent * 2 + 1;
	while (child < size) // 若孩子节点的下标小于数组长度，则循环继续
	{
		// 若右孩子存在并且右孩子大于左孩子，则修改child，将child指向右孩子
		if (child + 1 < size && data[child + 1] > data[child]) {
			child++;
		}
		if (data[parent] < data[child]) { // 若父节点小于子节点，交换两节点
			SwapData(&data[parent], &data[child]);
			parent = child;
			child = parent * 2 + 1;
		} else {
			break;//若父节点大于子节点，满足堆的性质，不用调整
		}
	}
}

// sort down, little heap, adjust down
static void SortDownAdjustDown(int* data, int size, int pos) // pos是要进行向下调整的数的下标
{
	if (data == NULL || size <= 0 || pos >= size) {
		return;
	}
	size_t parent = pos;
	size_t child = parent * 2 + 1;
	while (child < size) { // 若孩子节点的下标小于数组长度，则循环继续
		// 若右孩子存在并且右孩子大于左孩子，则修改child，将child指向右孩子
		if (child + 1 < size && data[child + 1] < data[child]) {
			child++;
		}
		if (data[parent] > data[child]) { // 若父节点小于子节点，交换两节点
			SwapData(&data[parent], &data[child]);
			parent = child;
			child = parent * 2 + 1;
		} else {
			break;//若父节点大于子节点，满足堆的性质，不用调整
		}
	}
}

/* select sort: use int type sort */
void SortAlgSelect(void* data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int* temp = (int*)data;

	for (int i = 0; i < len; i++) {
		int swap = 0;
		for (int j = 0; j < len - i; j++) {
			if (temp[j] > temp[swap]) {
				swap = j;
			}
		}
		SwapData(&temp[swap], &temp[len - i - 1]);
	}
}

/* bubble sort: use int type sort */
void SortAlgBubble(void* data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int* temp = (int*)data;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (temp[j] > temp[j + 1]) {
				SwapData(&temp[j], &temp[j + 1]);
			}
		}
	}
}

/* input sort: use int type sort */
void SortAlgInsert(void* data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int *temp = (int *)data;

	for (int i = 1; i < len; i++) {
		int t = temp[i];
		int j = i - 1;

		while (j >= 0 && t < temp[j]) {
			temp[j + 1] = temp[j];
			j--;
		}
		temp[j + 1] = t;
	}
}

/* shell sort: use int type sort */
void SortAlgShell(void* data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int *temp = (int *)data;
	for (int r = len / 2; r >= 1; r /= 2) {
		for (int i = r; i < len; i++) {
			int t = temp[i];
			int j = i - r;

			while (j >= 0 && t < temp[j]) {
				temp[j + r] = temp[j];
				j -= r;
			}
			temp[j + r] = t;
		}
	}
}

/* merge sort: use int type sort */
void SortAlgRecurveMerge(void* data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int *temp = (int*)malloc((sizeof(int)) * (len - 1));
	MergeSort((int *)data, 0, len - 1, temp);
}

/* not recurve merge sort: use int type sort */
void SortAlgLoopMerge(int *data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int *temp = (int *)malloc(sizeof(int) * len);
	if (temp == NULL) {
		return;
	}

	int gap = 1;

	int i = 0;

	while (gap < len)
	{
		for (i = 0; i < len; i = i + gap * 2)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int index = i;
			//当end1超过len
			if (end1 >= len)
				end1 = len - 1;

			//当begin2超过len，令[begin2,end2]不存在
			if (begin2 >= len) {
				begin2 = 1;
				end2 = 0;
			}
			//	end2超过len
			if (begin2 < len && end2 >= len)
				end2 = len - 1;

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (*(data + begin1) <= *(data + begin2)) {
					*(temp + index) = *(data + begin1);
					begin1++;
				} else {
					*(temp + index) = *(data + begin2);
					begin2++;
				}
				index++;
			}
			while (begin1 <= end1) {
				*(temp + index) = *(data + begin1);
				begin1++;
				index++;
			}

			while (begin2 <= end2) {
				*(temp + index) = *(data + begin2);
				begin2++;
				index++;
			}
		}
		memcpy(data, temp, sizeof(int) * len);
		gap *= 2;
	}
	free(temp);
}


/* merge sort: use int type sort */
void SortAlgFast(void* data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int* temp = (int*)data;

	QuickSort(temp, 0, len - 1);
}

/* merge sort: use int type sort */
void SortAlgFastRand(void* data, int len)
{
	if (data == NULL || len <= 0) {
		return;
	}

	int* temp = (int*)data;

	QuickSortRand(temp, 0, len - 1);
}

void SortAlgBigHeap(int* data, int size)
{
	if (data == NULL || size <= 0) {
		return;
	}

	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		SortUpAdjustDown(data, size, i);
	}

	while (size > 0)
	{
		SwapData(&data[0], &data[size - 1]);
		size--;
		SortUpAdjustDown(data, size, 0);
	}
}

void SortAlgLittleHeap(int* data, int size)
{
	if (data == NULL || size <= 0) {
		return;
	}

	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		SortDownAdjustDown(data, size, i);
	}

	while (size > 1)
	{
		SwapData(&data[0], &data[size - 1]);
		size--;
		SortDownAdjustDown(data, size, 0);
	}
}
