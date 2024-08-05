int min(int a , int b){
    if(a>b){
        return b;
    }
    return a;
}

int trap(int* height, int n) {
    int prefix[n];
    int suffix[n];
    
    prefix[0] = height[0];

    for(int i=1 ;i < n ;i++){
        if(height[i] > prefix[i-1]){
            prefix[i]=height[i];
        }
        else{
            prefix[i]=prefix[i - 1];
        }
    }

    suffix[n-1]=height[n-1];
    for(int i=n-2 ;i >=0 ;i--){
        if(height[i] > suffix[i+1]){
            suffix[i]=height[i];
        }
        else{
            suffix[i]=suffix[i + 1];
        }
    }

    int total=0;

    for(int i=0;i<n;i++){
        if(height[i]<prefix[i] && height[i]<suffix[i]){
            total+=min(prefix[i],suffix[i])-height[i];
        }
    }

    return total;
}