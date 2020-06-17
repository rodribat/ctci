#include<iostream>
#include<set>

using namespace std;

main()
{
    set<char> S = set<char>();
    S.insert('A');
    S.insert('B');
    S.insert('C');

    if (S.find('A') != S.end())
        cout << "EXISTE" << endl;

    // listar
    set<char>::iterator it;
    cout << "Set Content: ";
    for (it=S.begin(); it!=S.end(); it++)
        cout << *it << " ";
    cout << endl;
    
    cout << S.size() << endl;;
    S.erase('A');
    cout << S.size() << endl;

    int qtd_b = S.count('B');
    cout << qtd_b << endl;

    S.clear();
}
