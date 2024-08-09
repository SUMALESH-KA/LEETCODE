bool lemonadeChange(int* s, int billsSize) {
    
    int ten=0,five=0;

    for(int i =0 ;i < billsSize ; i++){
        if(s[i]==5){
            five++;
        }
        else if(s[i]==10){
            if(five){
                five--;
                ten++;
            }
            else{
                return false;
            }
        }
        else{
            if(ten>=1 && five>=1){
                ten--;
                five--;
            }
            else if(five >=3){
                five-=3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}