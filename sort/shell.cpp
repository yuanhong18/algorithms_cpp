/*
先取一个小于n的整数d1作为第一个增量，把文件的全部记录分组。所有距离为d1的倍数的记录放在同一个组中。
先在各组内进行直接插入排序；然后，取第二个增量d2<d1重复上述的分组和排序，直至所取的增量  =1(  <  …<d2<d1)，
即所有记录放在同一组中进行直接插入排序为止。
*/
void shell_sort(vector<int>& vec)
{
	int len = vec.size();
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < len; i++)
		{
			int temp = vec[i];
			int j = i - gap;
			for (; j >= 0 && vec[j] > temp; j -= gap)
			{
				vec[j + gap] = vec[j];
			}
			vec[j + gap] = temp;
		}
	}
}
