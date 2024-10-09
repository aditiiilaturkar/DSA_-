#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class SparseVector
{
public:
    unordered_map<int, int> mp;
    SparseVector(std::vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                mp[i] = nums[i];
            }
        }
    }

    // Return the dot product of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        int res = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (vec.mp.find(itr->first) != vec.mp.end())
            {
                res += itr->second * vec.mp[itr->first];
            }
        }
        return res;
    }
};

// Example usage
int main()
{
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(2);
    nums1.push_back(3);

    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(3);
    nums2.push_back(0);
    nums2.push_back(4);
    nums2.push_back(0);
    SparseVector vec1(nums1);
    SparseVector vec2(nums2);

    int result = vec1.dotProduct(vec2);
    std::cout << "Dot Product: " << result << std::endl; // Output: 8

    return 0;
}
