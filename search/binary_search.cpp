/*
二分查找
*/
int binary_search(vector<int>& vec, int value)
{
	int left = 0;
	int right = vec.size() - 1;
	int mid = 0;
	while (left <= right)
	{
		if (vec[left] == value)
			return left;
		if (vec[right] == value)
			return right;
		mid = left + (right - left) / 2;		// 避免溢出
		if (vec[mid] == value)
			return mid;
		if (vec[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (left > right)
		return -1;
}
