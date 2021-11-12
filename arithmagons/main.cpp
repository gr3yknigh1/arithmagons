// https://nrich.maths.org/2670

#include <iostream>
#include <cmath>


inline const int next(const int& i, const int& count)
{
	return i + 1 >= count ? 0 : i + 1;
}


inline const int prev(const int& i, const int& count) 
{
	return i - 1 < 0 ? count - 1 : i - 1;
}


inline const bool is_last(const int& i, const int& count)
{
	return i == count - 1;
}


template<typename T>
void print_array(T* arr, const int& size, 
	const char* endl=", ", const char* last_endl=" ",
	const char* start = "{ ", const char* end = "}\n")
{
	std::cout << start;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << (is_last(i, size) ? last_endl : endl);
	}
	std::cout << end;
}

template<typename T>
void fill_array(T* arr, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "]: ";
		std::cin >> arr[i];
	}
}


int main() 
{
	const int COUNT = 3;
	int verts[COUNT] = { 0 };
	int edges[COUNT] = { 0 };

	std::cout << "Enter 3 initial verts value:\n";
	fill_array(verts, COUNT);
	std::cout << "Inputed verts: ";
	print_array(verts, COUNT);

	// ----
	for (int i = 0; i < COUNT; i++)
	{
		edges[i] = verts[i] + verts[next(i, COUNT)];
	}
	std::cout << "Counted edges: ";
	print_array(edges, COUNT);


	// ----
	int edges2[COUNT] = { 0 };
	std::cout << "Fill edges2:\n";
	fill_array(edges2, COUNT);
	int verts2[COUNT] = { 0 };

	for (int i = 0; i < COUNT; i++)
	{
		verts2[i] = floor((edges2[i] + edges2[prev(i, COUNT)] - edges2[next(i, COUNT)]) / 2);
	}
	std::cout << "Counted verts: ";
	print_array(verts2, COUNT);

	return 0;
}