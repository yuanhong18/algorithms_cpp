/*
从数列中挑出一个元素，称为"基准"（pivot）；
重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
*/
void quick_sort(vector<int>& vec, int beg, int end)
{
	if (beg >= end)
		return;
	int first = beg;
	int last = end;
	int key = vec[end];
	while (first < last)
	{
		while (first < last && vec[first] <= key)
		{
			first++;
		}
		vec[last] = vec[first];
		while (first < last && vec[last] >= key)
		{
			last--;
		}
		vec[first] = vec[last];
	}
	vec[first] = key;
	quick_sort(vec, beg, first - 1);
	quick_sort(vec, first + 1, end);
}
