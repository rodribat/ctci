
#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

// using additional data structure - O(n)
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

// without additional data structure - O(n²)
bool isUnique2(string w)
{
    for (int i=0; i<w.size(); ++i)
        for (int j=i+1; j<w.size(); ++j)
            if (w[i] == w[j])
                return false;

    return true;
}

// using an array as char set - O(n) or O(min(c, n)) assuming the character set is fixed
bool isUnique3(string w)
{
    if (w.size() > 256) return false;

    bool char_set[256];
    for (int i=0; i<256; ++i) char_set[i] = false;

    for (int i=0; i<w.size(); ++i)
    {
        char val = w[i];
        if (char_set[val])
            return false; // already found this char in string

        char_set[val] = true;
    }

    return true;
}

// solving using a bit vector (here we assume only lowercase characters) - O(n)
bool isUnique4(string w)
{
    int bit_array = 0;

    for (int i=0; i<w.size(); ++i)
    {
        int val = w[i] - 'a';
        if ((bit_array & (1 << val)) > 0)
            return false;
        
        bit_array = bit_array | (1 << val);
    }

    return true;
}

// solving by sorting the array - O(n.logn)
bool isUnique5(string w)
{
    std::sort(w.begin(), w.end());

    cout << w << endl;
    
    for (int i=1; i<w.size(); ++i)
        if (w[i] == w[i-1])
            return false;

    return true;
}

main()
{
    string s;
    cin >> s;

    if (isUnique5(s))
        cout << "IS UNIQUE" << endl;
    else
        cout << "NOT UNIQUE" << endl;    
}