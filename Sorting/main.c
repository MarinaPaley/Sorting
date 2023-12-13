#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h> //size_t
#include <time.h>
#include <stdbool.h>

size_t GetSize(const char* const message);
int GetIntValue(const char* const message);
int* GetArray(size_t size);
void RandomFill(int* const array, size_t size);
void Print(const int* const array, size_t size);
void BubbleSort(int* const array, size_t size);
void Swap(int* lha, int* rha);
bool LinearContains(const int* const array, const size_t size, const int value);
bool Contains(const int* const array, const size_t size, const int value);

size_t GetMinIndex(const int* const array,
	const size_t start,
	const size_t size);

size_t GetMaxIndex(const int* const array,
	const size_t start,
	const size_t size);

void SelectionSortAsc(int* const array, size_t size);
void SelectionSortDesc(int* const array, size_t size);

void InsertionSort(int* const array, size_t size);

void InsertionSortMirror(int* const array, size_t size);


int main()
{
	setlocale(LC_ALL, "ru-RU");
	size_t size = GetSize("¬ведите размера массива");
	int* array = GetArray(size);
	RandomFill(array, size);
	puts("»сходный массив");
	Print(array, size);
	puts("ќтсортированный по возрастанию");
	BubbleSort(array, size);
	Print(array, size);
	puts("ќтсортированный по убыванию");
	SelectionSortDesc(array, size);
	Print(array, size);
	InsertionSortMirror(array, size);
	puts("ќтсортированный по возрастанию");
	Print(array, size);

	return 0;
}

size_t GetSize(const char* const message)
{
	int size = GetIntValue(message);
	if (size <= 0)
	{
		errno = EDOM;
		perror("ќшибка: ");
		abort();
	}

	return (size_t)size;
}

int GetIntValue(const char* const message)
{
	int value = 0;
	printf_s("%s ", message);
	int result = scanf_s("%d", &value);
	if (result != 1)
	{
		errno = EIO;
		perror("ќшибка: ");
		abort();
	}

	return value;
}

int* GetArray(size_t size)
{
	int* array = calloc(size, sizeof(int));
	if (NULL == array)
	{
		errno = ENOMEM;
		perror("ќшибка: ");
		abort();
	}

	return array;
}

void RandomFill(int* const array, size_t size)
{
	srand(time(NULL));
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = rand() % 10;
	}
}

void Print(const int* const array, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		printf_s("%d ", array[i]);
	}

	printf_s("\n");
}

void BubbleSort(int* const array, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = 0; j < size - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}


void Swap(int* lha, int* rha)
{
	*lha ^= *rha;// XOR
	*rha ^= *lha;
	*lha ^= *rha;
}

bool LinearContains(const int* const array, const size_t size, const int value)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] == value)
		{
			return true;
		}
	}

	return false;
}

bool Contains(const int* const array, const size_t size, const int value)
{
	size_t i = size / 2;
	if (array[i] < value)
		return ...;
	if (array[i] > value)
		return ...;

	return true;
}

size_t GetMinIndex(const int* const array,
	const size_t start,
	const size_t size)
{
	size_t minIndex = start;
	int min = array[minIndex];
	for (size_t i = start + 1; i < size; ++i)
	{
		if (array[i] < min)
		{
			min = array[i];
			minIndex = i;
		}
	}
	return minIndex;
}

size_t GetMaxIndex(const int* const array, const size_t start, const size_t size)
{
	size_t maxIndex = start;
	int max = array[maxIndex];
	for (size_t i = start + 1; i < size; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void SelectionSortAsc(int* const array, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		size_t indexMin = GetMinIndex(array, i + 1, size);
		if (array[i] > array[indexMin])
		{
			Swap(&array[i], &array[indexMin]);
		}
	}
}

void SelectionSortDesc(int* const array, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		size_t indexMax = GetMaxIndex(array, i + 1, size);
		if (array[i] < array[indexMax])
		{
			Swap(&array[i], &array[indexMax]);
		}
	}
}

void InsertionSort(int* const array, size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		size_t j = i - 1;
		while (j >= 0 && array[j] > array[j + 1])
		{
			Swap(&array[j], &array[j + 1]);
			j--;
		}
	}
}

void InsertionSortMirror(int* const array, size_t size)
{
	for (size_t i = size - 1; i-->0;)
	{
		size_t j = i + 1;
		while (j <= size - 1 && array[j] < array[j - 1])
		{
			Swap(&array[j], &array[j - 1]);
			j++;
		}
	}
}
