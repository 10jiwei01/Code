#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

pair<int,int> patition_divide(vector<int>& v,int l,int r)
{
	//����ȡ��
	int m=l+(r-l)/2;
	if(v[l]>v[r])
		swap(v[l],v[r]);
	if(v[l]>v[m])
		swap(v[l],v[m]);
	if(v[m]>v[r])
		swap(v[m],v[r]);
		
	//��Ԫ���������λ��
		swap(v[r],v[m]);
		
	int pivot = v[r];
	/*
	while(a<b)
	{
		while(a<b && c<=v[b])
			b--;
		//�滻���潻�����Ż�����Ҫ�Ľ���
		v[a]=v[b];
		while(a<b && c>=v[a])
			a++;
		v[b]=v[a];
	}
	v[a]=c;
	*/

	//�ֶε�һ�ַ�����˫ָ�루������󹫿��Σ�����Ϊ���Σ�<= pivot , > pivot
	//�����������������Ԫ��ȫ�����ʱ��low��highָ���ͣ�������ཻ��Ԫ�أ����Ա�֤ÿ��patition�ֵ��Ƚ��м��λ�ã�ʹ�����帴�Ӷ�NlogN
	/*
	int low = a+1;
	int high = b;
	for(;;)
	{
		while(v[low] < c)
			low++;
		while(v[high] > c)
			high--;
		if(low < high)
			swap(v[low],v[high]);
		else
			break;
	}

	swap(v[high],v[a]);
	return high;
	*/

	//
	//�ֶεڶ��ַ����������������⣬��Ϊ���� < pivot, = pivot, > pivot������������ڶ���ظ�Ԫ���ǣ����Խ���ʱ�临�Ӷȣ�
	int less = l - 1;
	int cur = l;
	int more = r;
	while(cur < more)
	{
		if(v[cur] < pivot)
			swap(v[++less],v[cur++]);
		else if(v[cur] > pivot)
			swap(v[--more],v[cur]);
		else
			cur++;
	}

	swap(v[more],v[r]);
	more++;

	return make_pair(less+1,more-1);
}

void Quick_Sort(vector<int>& vc,int l,int r)
{
	if(l >= r)
	{
		return;
	}

	pair<int,int> pr = patition_divide(vc,l,r);
	Quick_Sort(vc,l,pr.first-1);
	Quick_Sort(vc,pr.second+1,r);
}


/********����������*********/
int main()
{
	vector<int> vec;
	int n;
	fstream input("test.txt");
	while (input >> n)
	{
		for (int i=0;i<n;i++)
		{
			int a;
			input >> a;
			vec.push_back(a);
		}

		int len = vec.size();
		Quick_Sort(vec,0,len-1);

		for (int i=0;i<len;i++)
		{
			cout << vec[i] << ' ';
		}

		vec.clear();
		system("pause");
	}
	return 0;
}



