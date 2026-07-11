class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m1=nums1.size();
        int m2=nums2.size();
        int n=nums1.size()+nums2.size();
        int count =0;
        int indx2=n/2;
        int ind1el=-1;
        int ind2el=-1;
        int indx1=indx2-1;;
        int i=0;
        int j=0;
        while(i<m1 &&j<m2)
        {
            if(nums1[i]<nums2[j])
            {
                if(count==indx1)ind1el=nums1[i];
                if(count==indx2)ind2el=nums1[i];
                i++;
                count++;
            }
            else
            {
                if(count==indx1)ind1el=nums2[j];
                if(count==indx2)ind2el=nums2[j];
                j++;
                count++;
            }
        }
        while(i<m1)
        {
            if(count==indx1)ind1el=nums1[i];
            if(count==indx2)ind2el=nums1[i];
            i++;
            count++;
        }
         while(j<m2)
        {
            if(count==indx1)ind1el=nums2[j];
            if(count==indx2)ind2el=nums2[j];
            j++;
            count++;
        }
        if(n%2==0)return (ind1el+ind2el)/2.0;
        return ind2el;
    
        
    }
};