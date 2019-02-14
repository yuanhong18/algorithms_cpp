/*
从第一个元素开始，该元素可以认为已经被排序；
取出下一个元素，在已经排序的元素序列中从后向前扫描；
如果该元素（已排序）大于新元素，将该元素移到下一位置；
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
将新元素插入到该位置后；
重复步骤2~5。
*/
void insert_sort(vector<int>& vec)
{
	int len = vec.size();
	for (int i = 1; i < len; i++)
	{
		int curr_value = vec[i];
		int pre_index = i - 1;
		while (pre_index >= 0 && vec[pre_index] > curr_value)
		{
			vec[pre_index + 1] = vec[pre_index];
			pre_index--;
		}
		vec[pre_index + 1] = curr_value;
	}
}
