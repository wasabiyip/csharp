#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(),v.end());
	vector<int> v_backup(v.size());
	copy(v.begin(),v.end(), v_backup.begin());


	for (vector<int>::iterator it = v_backup.begin(); it!=v_backup.end(); ++it)
	{
		cout<< (*it) <<endl;
	}
	cout<< (*(v.begin()+5)) <<endl;
	return 0;
}