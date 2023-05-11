#include <bits/stdc++.h>
using namespace std;

int minmumresourses(vector<int>& start, vector<int> finish, int n)
    {
    	sort(start.begin(),start.end());
    	sort(finish.begin(),finish.end());
    	int resourses_needed = 1;
    	int resourses = 1;
    	int i=1;
    	int j=0;
    	while(i<n && j<n){
    	    if(start[i]<=finish[j]){
    	        resourses_needed++;
    	        i++;
    	    }
    	    else if(start[i]>finish[j]){
    	        resourses_needed--;
    	        j++;
    	    }
    	    if(resourses_needed>resourses) resourses = resourses_needed;
    	}
    	return resourses;
    }

int main() {
	int intervals ;
	cout<<"enter number of intervals \n";
	cin>>intervals;
	vector<int>start;
	vector<int> finish;
	for(int i=0;i<intervals;i++)
	{
		int x,y;
		cout<<"enter starting and finising time for "<<i+1<<" th interval ";
		cin>>x>>y;
		start.push_back(x);
		finish.push_back(y);
	}
    
    int minimum_resourses_needed = minmumresourses(start,finish,intervals );
    
    cout<<"Minimum resourses needed for a train at a station is "<<minimum_resourses_needed;
}
