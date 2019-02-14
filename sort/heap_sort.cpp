/*
将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，
得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
*/
void heap_adjust(vector<int>& vec, int i, int len)
{
	int largest = i;
	int left_child = 2 * i + 1;		// 左孩子
	int right_child = 2 * i + 2;		// 左孩子
	if (left_child < len && vec[left_child] > vec[largest])
		largest = left_child;
	if (right_child < len && vec[right_child] > vec[largest])
		largest = right_child;
	if (largest != i)
	{
		swap(vec[i], vec[largest]);
		heap_adjust(vec, largest, len);
	}
}
void heap_sort(vector<int>& vec, vector<int>& result)
{
	// 建最大堆
	for (int i = vec.size() / 2; i >= 0; i--)
		heap_adjust(vec, i, vec.size());
	
	for (int i = vec.size() - 1; i > 0; i--)
	{
		result[i] = vec[0];
		vec[0] = vec[i];
		heap_adjust(vec, 0, i);
	}
}
