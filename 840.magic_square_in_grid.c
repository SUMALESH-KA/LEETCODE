int magicsquare(int **grid , int row , int col , int gridsize , int gridcolsize)
{
    int visited[16]={0};
    for(int i = row ;i < row + 3 ;i++){
        for(int j = col ; j < col + 3 ;j++){
            if(grid[i][j] < 1 || grid[i][j]>9 || visited[grid[i][j]]){
                return 0;
            }
            visited[grid[i][j]] = 1 ;
        }
        
    }


    int target = grid[row][col]+grid[row][col+1] + grid[row][col+2];

    for(int i =0 ;i < 3 ;i++){
        int rowsum=0;
        for(int j=0; j <3 ;j++){
            rowsum += grid[row+i][col+j];
        }
        if(rowsum!=target){
            return 0;
        }
        int colsum=0;
        for(int j=0; j <3 ;j++){
            colsum += grid[row+j][col+i];
        }
        if(colsum!=target){
            return 0;
        }

        int dig1 = grid[row][col] + grid[row + 1][col + 1] + grid[row+2][col+2];
        int dig2 =grid[row][col+2] + grid[row + 1][col+1] + grid[row+2][col];

        if(dig1 != target || dig2 != target){
            return 0;
        }
    }
    return 1;
}
int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    
    int count = 0;
    for(int i = 0;i < gridSize - 2 ; i++ ) {
        for(int j=0; j <*gridColSize - 2 ;j++){
            if(magicsquare(grid,i,j,gridSize,gridColSize)){
                count++;
            }
        }

    }
    return count;
}