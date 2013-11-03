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


class KingSort {
public:
	
	int getnum(string s)
	{
		map<string, int> val;
		val["I"] = 1;
		val["II"] = 2;
		val["III"] = 3;
		val["IV"] = 4;
		val["V"] = 5;
		val["VI"] = 6;
		val["VII"] = 7;
		val["VIII"] = 8;
		val["IX"] = 9;
		val["X"] = 10;
		val["XX"] = 20;
		val["XXX"] = 30;
		val["XL"] = 40;
		val["L"] = 50;

		if(val.find(s) != val.end())
			return val[s];

		if(s.find("XXX") == 0)
			return (30 + val[s.substr(3)]);
		else if(s.find("XX") == 0)
			return (20 + val[s.substr(2)]);
		else if(s.find("XL") == 0)
			return (40 + val[s.substr(2)]);
		else if(s.find("X") == 0)
			return (10 + val[s.substr(1)]);
		else if(s.find("L") == 0)
			return (50 + val[s.substr(1)]);
	}

	vector <string> getSortedList(vector <string> k) {
		vector<string> res;
		map<string, map<int, string> > dat;
		int sz = k.size();
		
		for(int i=0; i<sz; i++)
		{
			istringstream ss(k[i]);
			string name, num;
			ss >> name;
			ss >> num;
			
			if(dat.find(name) != dat.end())
			{
				dat[name][getnum(num)] = num;
			}
			else
			{
				map<int, string> v;
				v[getnum(num)] = num;
				dat[name]=v;
			}
		}
		
		map<string, map<int, string> >::iterator j;
		map<int, string>::iterator l;

		for(j=dat.begin(); j!=dat.end(); j++)
		{
			map<int, string> tmp;
			tmp = ((*j).second);
			for(l=tmp.begin(); l!=tmp.end(); l++)
			{
				string tmp1 = ((*j).first) + " " + ((*l).second);
				res.push_back(tmp1);
			}	
		}
		
		return res;
	}
};