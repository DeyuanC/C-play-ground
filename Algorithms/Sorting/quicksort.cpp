#include<iostream>

using namespace std;


void quickSort(int* s, int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
				j--;
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
				i++;
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}

void myquickSort(int *s,const int left,const int right){
	if (left<right) { //else, array is sorted already

	int key = s[left];
	int i = left;
	int j = right;
	while(i<j){
		while (i<j&&s[j]>=key)
			j--;
		s[i]=s[j];
		i++;
		while(i<j&&s[i]<=key)
			i++;
		s[j]=s[i];
		j--;
	}
	s[i]=key;
	myquickSort(s,left,i-1);
	myquickSort(s,i+1,right);
}
}
int main()
{
	int array[]={2,3,3,3,1,1,1},k;
	int len=sizeof(array)/sizeof(int);
	cout<<"The orginal arrayare:"<<endl;
	for(k=0;k<len;k++)
		cout<<array[k]<<",";
	cout<<endl;
	myquickSort(array,0,len-1);
	cout<<"The sorted arrayare:"<<endl;
	for(k=0;k<len;k++)
		cout<<array[k]<<",";
	cout<<endl;
	system("pause");
	return 0;
}
