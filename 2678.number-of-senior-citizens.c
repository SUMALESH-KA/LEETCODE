int countSeniors(char ** details, int detailsSize){
    int count=0;
    int j=0;
    while(j < detailsSize){
        int digit = (details[j][11]-'0') * 10;
        digit += (details[j][12]-'0');
        if(digit > 60){
            count++;
        }
        j++;
    }
    return count;
}
