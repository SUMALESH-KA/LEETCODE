char* minWindow(char* s, char* t) {
    
    int hash[256]={0};

    for(int i=0;i<strlen(t);i++){
        hash[t[i]]++;
    }
    int start=-1;
    int l=0;
    int r=0;
    int minimum= INT_MAX;
    int count=0;

    for (int r = 0; r < strlen(s); r++) {
        if(hash[s[r]]>0){
            count++;  //////////
        }
        hash[s[r]]--;
        while(count==strlen(t)){
            if(r-l+1 < minimum){
                minimum=r-l+1;
                start=l;
            }

            hash[s[l]]++; //hash[s[l]]--
            if(hash[s[l]]>0){
                count--;
            }
            l++;
        }
    }

   if (start == -1) {
        return ""; 
    }

    char* result = (char*)malloc((minimum + 1) * sizeof(char));
    strncpy(result, s + start, minimum);
    result[minimum] = '\0';
    return result;
}
