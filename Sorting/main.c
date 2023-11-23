#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <locale.h>

size_t GetSize(const char* const message);
int GetIntValue(const char* const message);
int* GetArray(size_t size);
void RandomFill(int* const array, size_t size);
void Print(const int* const array, size_t size);
void BubbleSort(int* const array, size_t size);
void Swap(int* lha, int* rha);

int main()
{
	setlocale(LC_ALL, "ru-RU");
	size_t size = GetSize("Введите размера массива");
	int* array = GetArray(size);
	RandomFill(array, size);
	Print(array, size);
	BubbleSort(array, size);
	Print(array, size);
	return 0;
}

size_t GetSize(const char* const message)
{
	int size = GetIntValue(message);
	if (size <= 0)
	{
		errno = EDOM;
		perror("Ошибка: ");
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
		perror("Ошибка: ");
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
		perror("Ошибка: ");
		abort();
	}

	return array;
}

void RandomFill(int* const array, size_t size)
{
	srand(NULL);
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = rand();
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
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = i; j < size - 1; ++j)
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
