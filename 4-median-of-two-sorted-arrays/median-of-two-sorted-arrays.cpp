class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int p=n+m;
        int count=0;
        int i=0;
        double ans1=0;
        double ans2 =0;
       
        int j=0;
        while(count<=p/2){
            ans1= ans2;
          if(i<n && j<m && nums1[i]<=nums2[j] ){
            ans2= nums1[i];
            i++;
          }else if(j<m && i<n && nums2[j]<nums1[i] ){
ans2 = nums2[j];
j++;
          }else if( i==n  ){
            ans2 = nums2[j];
            j++;
          }else if( j==m ){
            ans2 = nums1[i];
            i++;
          }
          count++;
        }
        double ans=0.00;
     if(p%2==0 ){
        ans = (ans1+ans2)/2;
     }else{
        ans = ans2;
     }

     return ans;

    }
};