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


class BinPackingEasy {
public:
	int minBins(vector <int> a) {
		vector<int> b;
		int la = a.size();
		int c = 0;
		
		for(int i=0; i<la; i++)
		{
			if(a[i] >= 200)
				c++;
			else
				b.push_back(a[i]);
		}
		
		sort(b.begin(), b.end());
		
		int lb = b.size();
		
		for(int i=0, j=lb-1; i<=j;)
		{
			if(300-b[j]>=b[i])
			{
				i++;
				j--;
				c++;
			}
			else
			{
				j--;
				c++;
			}
		}
		
		return c;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
