           //       BSEF19M011           fAHEEM kHALID
#include<iostream>
#include<vector>
using namespace std;
class set
{private:
	vector<int>myvector;
public:
	void create()                        //create function
	{
		vector<int>myvector;
	} 

	void insert(int a)                   //     insert function
	{
		myvector.push_back(a);
	}

	void remove(int a)                    //   remove function
	{
		for (int i = 0; i < myvector.size(); ++i)
		{
			if (myvector[i] == a)
			{
				myvector.erase(myvector.begin() + i);
			}
		}
	}
	void ismember(int a)                 //ismember function
	{
		for (int i = 0; i < myvector.size(); i++)
		{
			if (myvector[i] == a)
			{
				cout << "       This value is member of set" << endl;
			}
			else if (myvector[i] != a && i == myvector.size()-1)
			{
				cout << "       This value is  not member of set" << endl;
			}
			
		}
	}

	void print()
	{
		cout << "{";
		for (int i = 0; i < myvector.size(); i++)
		{
			cout << myvector[i] << ",";
		}
		cout << "}" << endl;
	}

	void intersection(set s)                    //intersection
	{
		cout << "After performing Intersection on sets" << endl;
		cout << " { ";
		for (int i = 0; i < myvector.size(); i++)
		{
			for (int j = 0; j < s.myvector.size(); j++)
			{
				if (myvector[i] == s.myvector[j])
				{
					cout << myvector[i] << ",";
				}
			}
		}
		cout << " }" << endl;
	}

	void Issubset(set s)
	{
		cout << "After performing Subset operation " << endl;
		int count = 0;
		for (int i = 0; i < myvector.size(); i++)
		{
			for (int j = 0; j < s.myvector.size(); j++)
			{
				if (myvector[i] == s.myvector[j])
				{
					count++;
				}
			}
		}
		if (count == myvector.size())
		{
			cout << "1st set is subset of 2nd set" << endl;
		}
		else
		{
			cout << " 1st set is not subset of 2nd set" << endl;
		}
	}

	void Union(set s)
	{
		cout << "After performing Union operation" << endl;
		cout << " { ";
		for (int i = 0; i < myvector.size(); i++)
		{
			for (int j = 0; j < s.myvector.size(); j++)
			{
				if (myvector[i] == s.myvector[j])
				{
					s.myvector.erase(s.myvector.begin() + j);
				}
			}
		}
		set temp;
		for (int i = 0; i < myvector.size(); i++)
		{
			temp.myvector.push_back(myvector[i]);
		}
		for (int i = 0; i < s.myvector.size(); i++)
		{
			temp.myvector.push_back(s.myvector[i]);
		}
		for (int i = 0; i < temp.myvector.size(); i++)
		{
			cout << temp.myvector[i] << ",";
		}
		cout << " } " << endl;
	}
};
int main()
{
	set s1;
	s1.insert(22);
	s1.insert(21);
	s1.insert(2);
	s1.insert(24);
	s1.insert(27);
	cout << "Set 1 is:" << endl;
	s1.print();
	cout << endl;
	cout << "After removing 21 from set 1";
	cout << endl;
	s1.remove(21);
	cout << endl;
	
	cout << "Set 1 is:" << endl;
	s1.print();
	cout << endl;
	cout << " After performing ISmember function" << endl;
	s1.ismember(21);
	cout << endl;

	set s2;
	s2.insert(22);
	s2.insert(11);
	s2.insert(2);
	s2.insert(24);
	cout << "Set 2 is:" << endl;
	s2.print();
	cout << endl;

	s1.intersection(s2);
	cout << endl;

	s1.Issubset(s2);
	cout << endl;

	s1.Union(s2);
	return 0;
}