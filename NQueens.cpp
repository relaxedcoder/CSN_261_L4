#include<bits/stdc++.h>
using namespace std;

int counter = 0;

/** This function prints the board representing the positions of the queens.
* @param positions 1-D Array containing positions of the queens
* @param n Number of queens
*/
void printboard(int * positions,int n)
{
	for(int i=0;i<n;i++)
	{
		int pos = positions[i]-1;
		for(int j=0;j<n;j++)
		{
			if(j==pos) cout<<"1 ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}

/** This function checks the condition for conflict in diagonals.
* @param positions 1-D Array containing positions of the queens
* @param n Number of queens
*/
bool checkattack(int * positions,int n)
{
	for(int i=0;i<n;i++)
	{
		int x1 = i+1;
		int y1 = positions[i];
		int x2,y2;
		for(int j=0;j<n;j++)
		{
			x2 = j+1;
			y2 = positions[j];
			if(x1!=x2 && y1!=y2)
			{
				if(abs(x1-x2)==abs(y1-y2)) return 1;
			}
		}
	}
	return 0;
}

/** This function generates all the possible permutations for a given array
* @param a The array containing the elements
* @param l Left index
* @param r Right index
* @param n Size of array
*/
void permute(int * a,int l,int r,int n)
{
	if(l == r)
	{
		if(!checkattack(a,n))
		{
			counter++;
			cout<<"Combination "<<counter<<":"<<endl;
			printboard(a,n);
			cout<<endl;
		}
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(a[l],a[i]);
			permute(a,l+1,r,n);
			swap(a[l],a[i]);
		}
	}
}

/** This function returns the total number of possible solutions of the N-Queens problem.
* @param n Number of queens
*/
int countNQueens(int n)
{
	int * positions = new int[n];
	for(int i=0;i<n;i++)
	{
		positions[i] = i+1;
	}
	permute(positions,0,n-1,n);
	return counter;
}

int main()
{
	clock_t start,end;
	start = clock();
	int n;
	cout<<"Enter the value of n."<<endl;
	cin>>n;
	int sol = countNQueens(n);
	cout<<"Total number of combinations: "<<counter<<endl;
	end = clock();
	cout<<"Total execution time: "<<float(end-start)/CLOCKS_PER_SEC<<" seconds.";
	return 0;
}
