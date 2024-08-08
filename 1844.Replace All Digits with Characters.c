char shift(char s , int n){
    char ch;
    ch = s;
    ch = ch + n - '0'; 
    if(ch > 'z') ch = ch - 26; 
    return ch;
}

char* replaceDigits(char* s) {
    
    for(int i =1 ;i < strlen(s) ;i++){
        if(isdigit(s[i])){
            s[i]=shift(s[i-1],s[i]);
        }
    }

    return s;
}