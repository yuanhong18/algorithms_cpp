/*
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
以此类推，直到所有元素均排序完毕。
*/
void choose_sort(vector<int>& vec)
{
	int len = vec.size();
	for (int i = 0; i < len - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < len; j++)
		{
			if (vec[j] < vec[min_index])
			{
				min_index = j;
			}
		}
		int temp = vec[i];
		vec[i] = vec[min_index];
		vec[min_index] = temp;
	}
}
