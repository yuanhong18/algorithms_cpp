/*
把长度为n的输入序列分成两个长度为n/2的子序列；
对这两个子序列分别采用归并排序；
将两个排序好的子序列合并成一个最终的排序序列。
*/
void merge(vector<int>& vec, int left, int mid, int right, vector<int>& temp)
{
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
			temp[k++] = vec[i++];
		else
			temp[k++] = vec[j++];
	}
	while (i <= mid)
		temp[k++] = vec[i++];
	while (j <= right)
		temp[k++] = vec[j++];
	for (int m = 0; m < k; m++)
		vec[left + m] = temp[m];
}
void merge_sort(vector<int>& vec, int beg, int end, vector<int>& temp)
{
	if (beg >= end)
		return;
	int mid = beg + (end - beg) / 2;		// 避免溢出
	merge_sort(vec, beg, mid, temp);
	merge_sort(vec, mid + 1, end, temp);
	merge(vec, beg, mid, end, temp);
}
