#pragma once

#include<iostream>
using namespace std;
#include<map>
#include<string>
#include<algorithm>
#include<vector>
//void Inerst()
//{
//	string fruits[] = { "苹果", "葡萄", "苹果", "葡萄", "香蕉", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "苹果", "苹果", "苹果", "苹果" };
//	map<string, int> countmap;
//	for (size_t i = 0; i < sizeof(fruits) / sizeof(fruits[0]); i++)
//	{
//		/*map<string, int>::iterator it = countmap.find(fruits[i]);
//		if (it != countmap.end())
//		{
//			it->second++;
//		}
//		else
//		{
//			countmap.insert(make_pair(fruits[i], 1));
//		}*/
//		pair<map<string, int>::iterator, bool> pr = countmap.insert(make_pair(fruits[i],1));
//		if (pr.second == false)
//		{
//			pr.first->second++;
//		}
//		/*countmap[fruits[i]]++;*/
//	}
//}

void Printmap(const map<string,int>& dict)
{
	map<string, int>::const_iterator dicit = dict.begin();
	while (dicit != dict.end())
	{
		cout << (*dicit).first << ":" << dicit->second << endl;
		++dicit;
	}
	cout << endl; 
}

void Top_K()
{
	string fruits[] = { "苹果", "葡萄", "苹果", "葡萄", "香蕉", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "苹果", "苹果", "苹果", "苹果" };
	map<string, int> CountMap;
	for (size_t i = 0; i < sizeof(fruits) / sizeof(fruits[0]); i++)
	{
		CountMap[fruits[i]]++;
	}
	Printmap(CountMap);

	vector<map<string, int>::iterator> vec;
	map<string, int>::iterator dict = CountMap.begin();
	while (dict != CountMap.end())
	{
		vec.push_back(dict);
		dict++;
	}
	struct Camper
	{
		bool operator()(const map<string, int>::iterator l, const map<string, int>::iterator r)
		{
			return(*l).second > (*r).second;
		}
	};

	sort(vec.begin(), vec.end(), Camper());
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i]->first << ":" << vec[i]->second << endl;
	}
	cout << endl;
}
