char* kthDistinct(char** arr, int arrsize, int k) {
    
    int *visited = (int*)malloc(arrsize * sizeof(int));

    int found=0;
    int count=0;

    for(int i=0 ;i < arrsize ; i++){
        visited[i] = 0;
    }

    for(int i=0; i < arrsize ;i++){
        if(visited[i]==0){
            found=1;

            for(int j= i+1 ;j < arrsize ;j++){
                if(strcmp(arr[i],arr[j])==0){
                    found=0;
                    visited[j]=1;
                }
            }

            if(found){
                count++;
                if(count == k){
                    return arr[i];
                }
            }
        }
 
    }
    return "";
}