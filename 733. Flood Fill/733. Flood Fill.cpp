class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if (originalColor != color) {

            dfs(image, sr, sc, originalColor, color);

        }

        return image;

    }

private:

    void dfs(vector<vector<int>>& image, int r, int c, int originalColor, int newColor) {

        // Check boundary conditions

        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != originalColor) {

            return;

        }

        

        // Change the color of the current pixel

        image[r][c] = newColor;

        // Recursively call dfs on all 4-directionally connected pixels
        dfs(image, r + 1, c, originalColor, newColor);
        dfs(image, r - 1, c, originalColor, newColor);
        dfs(image, r, c + 1, originalColor, newColor);
        dfs(image, r, c - 1, originalColor, newColor);
        
    }
};