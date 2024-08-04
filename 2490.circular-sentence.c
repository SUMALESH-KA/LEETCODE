bool isCircularSentence(char* sentence) {
    int n = strlen(sentence);
    if(sentence[n-1]!=sentence[0]){
        return false;
    }

    char* token = strtok(sentence," ");
    char ** tokens = malloc(n * sizeof(char*));
    int k=0;
    while(token != NULL){
        tokens[k++]=strdup(token);
        token = strtok(NULL," ");
    }

    int i=0;
    int j=1;
    while(i<k && j<k){
        int len=strlen(tokens[i])-1;
        if(tokens[i][len]!=tokens[j][0]){
            return false;
        }
        i++;
        j++;
    }

    return true;
}
