#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class ZigZag {
public:
	int longestZigZag(vector <int> v) {
		
		int sz1 = v.size();
		int s[sz1][3];
		
		
		for(int i=0; i<sz1; i++)
		{
			s[i][0]=1;
		}
		
		s[0][1]=v[0];
		s[0][2]=1;
		
		for(int i=1; i<sz1; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(((v[i] - s[j][1]) < 0) && ((s[j][2] == 1) || (s[j][2] == 2)))
				{
					if((s[j][0] + 1) > s[i][0])
					{
						s[i][0] = s[j][0] + 1;
						s[i][1] = v[i];
						s[i][2] = 3;
					}
				}
				else if(((v[i] - s[j][1]) > 0) && ((s[j][2] == 1) || (s[j][2] == 3)))
				{
					if((s[j][0] + 1) > s[i][0])
					{
						s[i][0] = s[j][0] + 1;
						s[i][1] = v[i];
						s[i][2] = 2;
					}
				}
			}
		}
		
		int maxi = s[0][0];
						
		for(int i=1; i<sz1; i++)
		{
			maxi = max(maxi, s[i][0]);
		}
		
		return maxi;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!