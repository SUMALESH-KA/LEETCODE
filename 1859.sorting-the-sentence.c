char * sortSentence(char * s){

    int len = strlen(s);
    char * words[len];
    int indices[len];
    int wordcount = 0;

    char *token=strtok(s," ");

    while(token!=NULL){
        int len=strlen(token);
        int index = token[len-1]-'0';

        token[len-1]='\0';

        words[index-1] = strdup(token);
        indices[wordcount++]=index;

        token = strtok(NULL," ");
    }

    int tlen=0;
    for(int i=0;i<wordcount;i++){
        tlen += strlen(words[i])+1;
    }

    char *result = (char *)malloc(tlen *sizeof(char));
    result[0]='\0';

    for(int i=0;i<wordcount;i++){
        strcat(result,words[i]);
        if(i < wordcount -1){
            strcat(result," ");
        }
        free(words[i]);
    }

    return result;
}