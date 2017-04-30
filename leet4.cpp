class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		if (len1>len2) {
			return findMedianSortedArrays(nums2, nums1);
		}
		else {

			int start = 0, end = len1 - 1;
			int i = 0, j = 0;
			do {
				i = ((end == -1) ? -1 : (start + end) / 2);
				j = (len1 + len2 - 1) / 2 - (i + 1);
				if (i>-1 && nums1[i]>nums2[j + 1]) {
					end = (--i); ++j;
				}
				else if (i<(len1 - 1) && nums1[i + 1]<nums2[j]) {
					start = (++i); --j;
				}
				else {
					break;
				}
			} while (start <= end);

			int l = 0, r = 0;
			if (i == -1) l = nums2[j];
			else if (j == -1) l = nums1[i];
			else l = nums1[i]>nums2[j] ? nums1[i] : nums2[j];

			if ((len1 + len2) % 2)
				return l;

			if (i == len1 - 1) r = nums2[j + 1];
			else if (j == len2 - 1) r = nums1[i + 1];
			else r = nums1[i + 1]<nums2[j + 1] ? nums1[i + 1] : nums2[j + 1];

			return (l + r) / 2.0;
		}
	}
};