// Derek Cook
// CS 2336
// Lab 22

// function template prototype
template<typename T>
const T *binarySearch(const T *first, const T *last, T itemToFind)
{
	const T *mid;

	if (first > last)
	{

		return 0;

	}
	mid = first + (last - first) / 2;
	if (itemToFind == *mid)
	{

		return mid;

	}
	else if (itemToFind > *mid)
	{

		return binarySearch(mid + 1, last, itemToFind);

	}
	else 
	{

		return binarySearch(first, mid - 1, itemToFind);

	}
}
