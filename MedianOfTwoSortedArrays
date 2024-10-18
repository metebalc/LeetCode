class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> newArr(nums1.size() + nums2.size());
        int newSize = newArr.size();

        int j = 0, k = 0;
        for (int i = 0; i < newSize; ++i)
        {
            if (j < nums1.size() && (k >= nums2.size() || nums1[j] <= nums2[k] ))
            {
                newArr[i] = nums1[j++];
            }
            else
            {
                newArr[i] = nums2[k++];
            }
        }
        
        if (newSize % 2 != 0)
        {
            return newArr[newSize/2];
        }
        else
        {
            double median1 = newArr[(newSize/2) -1]; //Arrays start at 0
            double median2 = newArr[newSize/2];

            double average = (median1 + median2)/2;
            return average;
        }
    }
};
