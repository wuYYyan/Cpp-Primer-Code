#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

auto test = [](auto& arr, auto& sort)
{
	static default_random_engine e(time(nullptr));
	uniform_int_distribution<remove_reference<decltype(arr)>::type::value_type> rand;
	generate(arr.begin(), arr.end(), [&] {return rand(e); });

	auto tic = clock();
	sort(arr.begin(), arr.end());
	cout << "used time: " << clock() - tic << "ms" << endl;
};

template<typename Iter>
void quick_sort1(Iter first, Iter last)
{
	if (last - first > 1)
	{
		auto i = first + 1, j = last - 1;

		while (i < j)
			if (*i < *first)
				++i;
			else if (*j > *first)
				--j;
			else
				swap(*i++, *j--);

		if (*first > *j)
			swap(*first, *j);

		quick_sort1(first, j);
		quick_sort1(j, last);
	}
}

template<typename Iter>
void quick_sort2(Iter first, Iter last)
{
	bool sorted = true;

	for (auto iter = first + 1; iter != last; ++iter)
	{
		if (*iter < *(iter - 1))
		{
			sorted = false;
			break;
		}
	}

	if (not sorted && last - first > 1)
	{
		auto i = first + 1, j = last - 1;

		while (i < j)
			if (*i < *first)
				++i;
			else if (*j > *first)
				--j;
			else
				swap(*i++, *j--);

		if (*first > *j)
			swap(*first, *j);

		quick_sort2(first, j);
		quick_sort2(j, last);
	}
}

auto&& quick_sort = [](auto first, auto last)
{
	auto&& three_get_mid = [](auto& a, auto& b, auto& c)
	{
		if (a > b)
			swap(a, b);
		if (b > c)
			swap(b, c);
		if (a > c)
			swap(a, c);
	};

	auto&& sort = [&](auto&& self, auto first, auto last)->void
	{
		bool sorted = true;

		for (auto iter = first + 1; iter != last; ++iter)
		{
			if (*iter < *(iter - 1))
			{
				sorted = false;
				break;
			}
		}

		if (not sorted && last - first > 1)
		{
			auto i = first + 1, j = last - 1;
			three_get_mid(*(first + ((last - first) >> 1)), *i, *j);

			while (i < j)
				if (*i < *first)
					++i;
				else if (*j > *first)
					--j;
				else
					swap(*i++, *j--);

			if (*first > *j)
				swap(*first, *j);

			self(self, first, j);
			self(self, j, last);
		}
	};

	sort(sort, first, last);
};

int main(void)
{
	for (size_t n = 1; n <= 1e8; n *= 10)
	{
		cout << "n: " << n << endl;

		vector<unsigned long long> arr(n);
		test(arr, sort<decltype(arr.begin())>); //std::sort
		test(arr, quick_sort1<decltype(arr.begin())>); //my fucking sort
        test(arr, quick_sort2<decltype(arr.begin())>); //my fucking sort
        // test(arr, quick_sort3<decltype(arr.begin())>); //my fucking sort

		cout << endl;
	}

	return 0;
}