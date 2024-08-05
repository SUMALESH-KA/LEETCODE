void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    

    int j = 0;
    int k = m;
    for (int i = k; i < m + n; i++) {
        nums1[i] = nums2[j];
        j++;
    }
        
    for(int i=0;i<m+n;i++){
        for(int j=i+1;j<m+n;j++){
            if(nums1[i]>nums1[j]){
                int temp=nums1[i];
                nums1[i]=nums1[j];
                nums1[j]=temp;
            }
        }
    }


}