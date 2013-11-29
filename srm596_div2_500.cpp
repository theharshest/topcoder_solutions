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


class ColorfulRoad {
public:
	bool comp(char a, char b)
	{
		if(a=='R' && b=='G')
			return 1;
		if(a=='G' && b=='B')
			return 1;
		if(a=='B' && b=='R')
			return 1;
			
		return 0;
	}

	int getMin(string rd) {
		
		vector<int> cost;
		int l = rd.length();
		cost.resize(l, 100000);
		
		cost[0] = 0;
		
		for(int i=1; i<l; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(comp(rd[j], rd[i]))
					cost[i] = min(cost[i], cost[j] + (i-j)*(i-j));
			}
		}
		
		if(cost[l-1] != 100000)
			return cost[l-1];
		else
			return -1;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
