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


class WolfDelaymaster {
public:
	string check(string s) {
	
		int l = s.length();
		
		for(int i=0; i<l; )
		{
			int c = 0;
			if(s[i] == 'w')
			{
				while(s[i] == 'w')
				{
					c++;
					i++;
					
					if(i == l)
						return "INVALID";
				}
				
				int tmp = c;
				
				while(tmp--)
				{
					if(i<l && s[i] == 'o')
						i++;
					else
						return "INVALID";
				}
				
				tmp = c;
				
				while(tmp--)
				{
					if(i<l && s[i] == 'l')
						i++;
					else
						return "INVALID";
				}
				
				tmp = c;
				
				while(tmp--)
				{
					if(i<l && s[i] == 'f')
						i++;
					else
						return "INVALID";
				}
				
			}
			else
				return "INVALID";
		}
		
		return "VALID";
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
