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


class LittleElephantAndString {
public:
	int getNumber(string a, string b) {
		string sa, sb;
		sa=a;
		sb=b;
		sort(sa.begin(), sa.end());
		sort(sb.begin(), sb.end());
		
		if(sa != sb)
			return -1;
			
		int l = a.length() - 1;
		int c = 0;
		int i=l;
		int j=l;
		
		for(i=l; i>=0;)
		{
			while(i>=0 && a[i] != b[j])
			{
				i--;
				c++;
			}
			j--;
			i--;
		}
		
		return c;
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
