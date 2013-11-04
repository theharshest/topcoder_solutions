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


class AvoidRoads {
public:
	int b[51][4];
	int n;

	bool isbad(int x1, int y1, int x2, int y2)
	{
		for(int i=0; i<n; i++)
		{
			if((b[i][0] == x1) && (b[i][1] == y1) && (b[i][2] == x2) && (b[i][3] == y2))
				return true;
			else if((b[i][0] == x2) && (b[i][1] == y2) && (b[i][2] == x1) && (b[i][3] == y1))
				return true;
		}
		return false;
	}

	long long numWays(int w, int h, vector <string> bad) {
		long long s[101][101] = {0};
		n = bad.size();
		
		for(int i=0; i<n; i++)
		{
			stringstream ss;
			ss << bad[i];
			int x1, y1, x2, y2;
			ss >> x1; ss >> y1; ss >> x2; ss >> y2;
			b[i][0] = x1; b[i][1] = y1; b[i][2] = x2; b[i][3] = y2;
		}
		
		for(int i=0; i<w; i++)
			if(!isbad(i, 0, i+1, 0))
				s[i+1][0] = 1;
			else
			{
				for(int j=i+1; j<=w; j++)
					s[j][0] = 0;
				break;
			}	
		
		for(int i=0; i<h; i++)
			if(!isbad(0, i, 0, i+1))
				s[0][i+1] = 1;
			else
			{
				for(int j=i+1; j<=h; j++)
					s[0][j] = 0;
				break;
			}
		
		for(int i=1; i<=w; i++)
		{
			for(int j=1; j<=h; j++)
			{
					if(!isbad(i-1, j, i, j))
						s[i][j] = s[i-1][j] + s[i][j];
					if(!isbad(i, j-1, i, j))
						s[i][j] = s[i][j-1] + s[i][j];
			}
		}
		
		return s[w][h];
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
