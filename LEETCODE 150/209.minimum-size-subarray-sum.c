int min(int a , int b){
    if(a<b){
        return a;
    }
    return b;
}
int minSubArrayLen(int target, int* nums, int numsSize) {
    int l = 0 ;
    int ans = INT_MAX;
    int sum = 0;

    for(int i = 0 ; i < numsSize ; i++){
        sum += nums[i];
        while(l <= i && sum >= target){
            ans = min(ans , i-l+1);
            sum -= nums[l++];
        }
    } 
    if(ans==INT_MAX){
        return 0;
    }
    return ans;
}
