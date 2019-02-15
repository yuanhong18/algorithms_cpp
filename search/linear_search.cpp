/*
线性查找(修改了原容器)
*/
bool linear_search(vector<int>& vec, int value)
{
	vec.emplace_back(value);
	int i = 0;
	while (vec[i] != value)
		i++;
	if (i != vec.size() - 1)
		return true;
	return false;
}
