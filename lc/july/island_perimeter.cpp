#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countNeighbors(int lin, int col, const vector<vector<int>>& grid)
    {
        return grid[lin-1][col] + grid[lin+1][col] + grid[lin][col-1] + grid[lin][col+1];
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        // expand grid
        for (int lin=0; lin<grid.size(); ++lin)
        {
            grid[lin].push_back(0);
            grid[lin].insert(grid[lin].begin(), 0);
        }
        grid.push_back(vector<int>(grid[0].size(), 0));
        grid.insert(grid.begin(), vector<int>(grid[0].size(), 0));
        
        // calculate the perimeter
        int perimeter = 0;
        for (int lin=1; lin<grid.size()-1; ++lin)
            for (int col=1; col<grid[lin].size()-1; ++col)
                if (grid[lin][col] == 1)
                    perimeter += 4 - countNeighbors(lin, col, grid);
        
        return perimeter;
    }
};

int main()
{
    vector<vector<int>> v({{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}});
    Solution s;
    cout << "Perimeter: " << to_string(s.islandPerimeter(v)) << endl;

    return 0;
}