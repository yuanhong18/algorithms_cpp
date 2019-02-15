/*
找出待排序的数组中最大和最小的元素；
统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
*/
void count_sort(vector<int>& vec, int max, int min, vector<int>& result)
{
	int len_1 = vec.size();
	int len_2 = max - min + 1;
	vector<int> count_vec(len_2, 0);
	for (int i = 0; i < len_1; i++)
		count_vec[vec[i]]++;
	for (int i = 1; i < len_2; i++)
		count_vec[i] += count_vec[i - 1];
	for (int i = 0; i < len_1; i++)
	{
		result[count_vec[vec[i]] - 1] = vec[i];
		count_vec[vec[i]]--;
	}
}
