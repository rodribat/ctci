/*
    FB

    [1, 2, 3]
    [4, 0, 5]

    1*4 + 2*0 + 3*5 = 19
    
    long = ~10^9 in length
    sparse = ~10^6 non-zero entries

    list of (index, value)

    [(4, 5), (5, 6)]
    [(4, 3), (7, 6)]
            
    sum = 15


    [(1, 3), (4, 5), (5, 6)]
    [(2, 4), (4, 3), (7, 6)]
*/

#include<iostream>
#include<vector>

using namespace std;

class Val
{
    public:
    int index;
    int value;
    Val(int index, int value)
    {
        this->index = index;
        this->value = value;
    }
};

long dotProduct(const vector<Val>& x1, const vector<Val>& x2)
{
    long sum = 0;
    int counter = 0;
    int i = 0;
    int j = 0;

    while (i < x1.size() && j < x2.size())
    {
        if (x1[i].index == x2[j].index)
        {
            sum += x1[i].value * x2[j].value;
            i++;
            j++;
        }
        
        if (x1[i].index < x2[j].index)
            i++;
        
        if (x1[i].index > x2[j].index)
            j++;
    }
    
    return sum;
}

int main()
{
    vector<Val> x1;
    vector<Val> x2;

    x1.push_back(Val(1,3));
    x1.push_back(Val(4,5));
    x1.push_back(Val(5,6));

    x2.push_back(Val(2,4));
    x2.push_back(Val(4,3));
    x2.push_back(Val(7,6));

    long sum = dotProduct(x1, x2);

    cout << "Soma: " << sum << endl;
}