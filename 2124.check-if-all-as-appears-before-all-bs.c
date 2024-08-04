bool checkString(char* s) {
    if(s[0])

    for(int i=0;i <strlen(s)-1;i++){
        if(s[i]=='b'){
            if(s[i+1]=='a'){
                return false;
            }
        }
    }
    return true;
}
