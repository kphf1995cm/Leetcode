# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> res;
		if (k > nums1.size() + nums2.size())
			return res;
		parse(res, nums1, 0, nums2, 0, k);
		return res;
	}
	void parse(vector<int>&res, vector<int>& nums1,int nums1_s,vector<int>& nums2, int nums2_s,int k){
		if (k != 0)
		{
			int maxNums1Index;
			int maxNums1Value;
			bool isNums2 = false;

			int nums1Len = nums1.size() - nums1_s;
			int nums2Len = nums2.size() - nums2_s;

			int nums1IterEnd = k > nums2Len ? nums1.size() - (k - nums2Len)+1 : nums1.size();
			int nums2IterEnd = k > nums1Len ? nums2.size() - (k - nums1Len)+1 : nums2.size();

			if (nums1_s < nums1.size())
			{
				maxNums1Index = nums1_s;
				maxNums1Value = nums1[nums1_s];
				if (maxNums1Value != 9)
				{
					for (size_t i = nums1_s + 1; i < nums1IterEnd; i++)
					{
						if (maxNums1Value < nums1[i])
						{
							maxNums1Index = i;
							maxNums1Value = nums1[i];
							if (maxNums1Value == 9)
								break;
						}
					}
				}
			}
			if (nums2_s < nums2.size())
			{
				maxNumsIndex = nums1_s;
				maxNums2Value = nums1[nums1_s];
				if (maxNums1Value != 9)
				{
					for (size_t i = nums1_s + 1; i < nums1IterEnd; i++)
					{
						if (maxNums1Value < nums1[i])
						{
							maxNums1Index = i;
							maxNums1Value = nums1[i];
							if (maxNums1Value == 9)
								break;
						}
					}
				}
			}
			else
			{
				if (nums2_s < nums2.size())
				{
					maxNums1Index = nums2_s;
					maxNums1Value = nums2[nums2_s];
					isNums2 = true;
				}
			}
			if (maxNums1Value != 9)
			{
				for (size_t i = nums2_s; i < nums2IterEnd; i++)
				{
					if (maxNums1Value < nums2[i])
					{
						isNums2 = true;
						maxNums1Index = i;
						maxNums1Value = nums2[i];
						if (maxNums1Value == 9)
							break;
					}
				}
				res.push_back(maxNums1Value);
				if (isNums2)
					parse(res, nums1, nums1_s, nums2, maxNums1Index + 1, k - 1);
				else
					parse(res, nums1, maxNums1Index + 1, nums2, nums2_s, k - 1);
			}
			else
			{
				res.push_back(maxNums1Value);
				parse(res, nums1, maxNums1Index + 1, nums2, nums2_s, k - 1);
			}
		}
	}
};

void test()
{
	Solution s;
	vector<int> nums1 = {3,4,6,5};
	vector<int> nums2 = {9,1,2,5,8,3};
	vector<int> res = s.maxNumber(nums1,nums2,5);
	for (size_t i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
}

int main()
{
	test();
}

