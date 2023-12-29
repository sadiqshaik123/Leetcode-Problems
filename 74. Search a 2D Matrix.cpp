class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int left = 0, right = matrix.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] < target) left = mid + 1;
            else right = mid;
        }
        int tmp = (right > 0) ? (right - 1) : right;
        left = 0;
        right = matrix[tmp].size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (matrix[tmp][mid] == target) return true;
            if (matrix[tmp][mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
