
#include "table.h"
#include <vector>

using std::pair;
using std::cin;
using std::vector;

int turn = 1;

int main()
{
    //    Table t;
    //
    //    t.show_vector();
    //    pair<char,int> cord_i;
    //    pair<char,int> cord_f;
    //    while(1){
    //        cin >> cord_i.first >> cord_i.second;
    //        cin >> cord_f.first >> cord_f.second;
    //        t.make_move(cord_i,cord_f,turn);
    //        t.show_table();
    //        turn=-turn;
    //    }


    vector<pair<int, int>> mutari;
    for (int i = 1; i <= 8; i++) {
        mutari.push_back({ i,i });
        mutari.push_back({ -i,i });
        mutari.push_back({ -i,-i });
        mutari.push_back({ i,-i });
        //    mutari.push_back({0,i});
        //    mutari.push_back({0,-i});
        //    mutari.push_back({i,0});
        //    mutari.push_back({-i,0});
    }

    for (pair<int, int> mutare : mutari)
        cout << "{" << mutare.first << "," << mutare.second << "},";

    return 0;
}



///TABLA

///  4  3  2  6  5  2  3  4
///  1  1  1  1  1  1  1  1
///  0  0  0  0  0  0  0  0
///  0  0  0  0  0  0  0  0
///  0  0  0  0  0  0  0  0
///  0  0  0  0  0  0  0  0
/// -1 -1 -1 -1 -1 -1 -1 -1
/// -4 -3 -2 -6 -5 -2 -3 -4
