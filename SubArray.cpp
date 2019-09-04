#include<bits/stdc++.h>
using namespace std;

int main()
{
	clock_t start,end;
	start = clock();
	int N,n,*a;
	cout<<"Enter the number of elements in the array"<<endl;
	cin>>N;
	a = new int[N];
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<N;i++) cin>>a[i];
	cout<<"Enter the sum to be checked for"<<endl;
	cin>>n;
	
	int sum=0,len=0,index=0;
	unordered_map<int,int> map;
	for(int i=0;i<N;i++)
	{
		sum += a[i];
		if(sum == n)
		{
			len = i+1;
			index = 0;
		}
		if(map.find(sum) == map.end())
		{
			map[sum] = i;
		}
		if(map.find(sum-n) != map.end())
		{
			if(len<(i-map[sum-n]))
			{
				len = i-map[sum-n];
				index = map[sum-n]+1;
			}
		}
	}
	if(len)
	{
		cout<<"Length of longest subarray is "<<len<<endl;
		cout<<"Index from "<<index<<" to "<<index+len-1<<"."<<endl;
	}
	else
	{
		cout<<"Not Found"<<endl;
	}
	end = clock();
	cout<<"Total execution time: "<<float(end-start)/CLOCKS_PER_SEC<<" seconds.";
	return 0;
}
