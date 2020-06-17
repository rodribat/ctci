
#include<iostream>
#include<set>

using namespace std;

// using additional data structure
bool isUnique(string w)
{
    set<char> s = set<char>();
    for (int i=0; i<w.size(); ++i)
    {
        if (s.find(w[i]) != s.end())
            return false; // previously inserted element found

        s.insert(w[i]);
    }

    return true;
}

// without additional data structure
bool isUnique2(string w)
{
    for (int i=0; i<w.size(); ++i)
        for (int j=i+1; j<w.size(); ++j)
            if (w[i] == w[j])
                return false;

    return true;
}

main()
{
    string s;
    cin >> s;

    if (isUnique2(s))
        cout << "IS UNIQUE" << endl;
    else
        cout << "NOT UNIQUE" << endl;
    
}