#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
struct pt{
    int row, col;
    pt(int row = 0, int col = 0) : row(row), col(col) {}

    bool operator<(const pt& other) const {
        return tie(row, col) < tie(other.row, other.col);
    }
};

bool valid(const pt& f, const pt& t, const set<pt>& grid) {
    if (t== f ||grid.find(t) == grid.end()) {
        return false;
    }
    if (f.row !=t.row) {
        return false;
    }
    if (f.col == t.col) {
        return false;
    }
    return true;
}

void find(set<pt> grid, pt cur, vector<pt> rt,vector<vector<pt>>& all_rt, pt ini) {
    if (cur== ini && rt.size() > 1) {
        all_rt.push_back(rt);
        return;
    }

    for (auto pos : grid) {
        if (valid(cur, pos, grid)) {
            vector<pt> new_rt = rt;
            new_rt.push_back(pos);
            set<pt> new_grid = grid;
            new_grid.erase(pos);
            find(new_grid, pos, new_rt, all_rt, ini);
        }
    }
}

int main() {
    int sc;
    cout <<"Enter the number of soldiers- ";
    cin >>sc;


    set<pt>grid;



    for (int i =0;i <sc;i++) {
        int x, y;
        cout<<"Enter for soldier "<<i+1<<"(format x y)- ";
        cin>>x>>y;
        grid.insert(pt(x,y));
    }

    int castle_row, castle_col;
    cout << "Enter for special castle (format x y)- ";
    cin >> castle_row >> castle_col;
    pt ini(castle_row, castle_col);

    vector<vector<pt>> all_rt;
    find(grid,ini,{ ini },all_rt, ini);

    cout << " There are"<<all_rt.size() << "unique paths for your'special_castle'" << endl;
    return 0;
}
