#include <iostream>

// First
void insertionSort(int list[], int listLength)
{
	for (int i = 1; i < listLength; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j] > list[j + 1])
		{
			std::swap(list[j], list[j + 1]);
			j--;
		}
	}
}

// Second
void shellSort(int list[], int listLength)
{
	for (int step = listLength / 2; step > 0; step /= 2)
	{
		for (int i = step; i < listLength; i += 1)
		{
			int j = i;
			while (j >= step && list[j - step] > list[i])
			{
				std::swap(list[j], list[j - step]);
				j -= step;
			}
		}
	}
}

void merge(int list[], int start, int end, int mid);

// Third
void mergeSort(int list[], int start, int end)
{
	int mid;
	if (start < end) {

		mid = (start + end) / 2;
		mergeSort(list, start, mid);
		mergeSort(list, mid + 1, end);
		merge(list, start, end, mid);
	}
}

void merge(int list[], int start, int end, int mid)
{
	int mergedList[8];
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;

	while (i <= mid && j <= end) {
		if (list[i] < list[j]) {
			mergedList[k] = list[i];
			k++;
			i++;
		}
		else {
			mergedList[k] = list[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		mergedList[k] = list[i];
		k++;
		i++;
	}

	while (j <= end) {
		mergedList[k] = list[j];
		k++;
		j++;
	}

	for (i = start; i < k; i++) {
		list[i] = mergedList[i];
	}
}

int main()
{
	int list1[8] = { 3,19,8,0,48,4,5,12 };
	std::cout << "Insetrion: Input array ...\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << list1[i] << "\t";
	}

	insertionSort(list1, 8);

	std::cout << "\nInsetrionSort: Sorted array ... \n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << list1[i] << "\t";
	}
	std::cout << std::endl << std::endl;

	int list2[8] = { 3,19,8,0,48,4,5,12 };
	std::cout << "ShellSort: Input array ...\n";
	for (int i = 0; i < 6; i++)
	{
		std::cout << list2[i] << "\t";
	}

	shellSort(list2, 8);

	std::cout << "\nShellSort: Sorted array ... \n";
	for (int i = 0; i < 6; i++)
	{
		std::cout << list2[i] << "\t";
	}
	std::cout << std::endl << std::endl;

	int list3[8] = { 3,19,8,0,48,4,5,12 };
	std::cout << "MergeSort: Input array ...\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << list3[i] << "\t";
	}
	mergeSort(list3, 0, 7);
	std::cout << "\nMergeSort: Sorted array ... \n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << list3[i] << "\t";
	}

	return 0;
}