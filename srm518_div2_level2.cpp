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


class LargestSubsequence {
public:
	char cbig(string s){
		int len = s.length();
		
		if(!len){
			return '\0';
		}
		
		char c = 'a';
		
		for(int i=0; i<len; i++)
		{
			if(s[i] > c)
			{
				c = s[i];
			}
		}
		
		return c;
	}

	string getLargest(string s) {
		
		string final = "";
		
		while(cbig(s))
		{
			final += cbig(s);
			s = s.substr(s.find(cbig(s))+1);
		}
		
		return final;
	}
};