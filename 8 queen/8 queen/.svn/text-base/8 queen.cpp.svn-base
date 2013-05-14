#include <iostream>
#include <vector>
using namespace std;


const int BOARD_SIZE = 8;
const int QUEEN = 1;
const int BLANK = 0;

//for cache purpose
int cachedResults[500][BOARD_SIZE];
int cacheIndex = 0;

//layout a board based on a configuration
void layout_board(int arrange[], int board[][BOARD_SIZE]){
        for(int i = 0; i<BOARD_SIZE; i++)
        {
                for(int j = 0; j<BOARD_SIZE; j++)
                {
                        board[i][j] = BLANK;
                }
        }
        for(int j = 0; j<BOARD_SIZE; j++)
        {
                //place the queens randomly
                board[arrange[j]/500][arrange[j]%500] = QUEEN;
        }
}


void print_board(int board[][BOARD_SIZE])
{
        for (int i = 0; i<BOARD_SIZE*2+1; i++)
        {
                cout<<"-";
        }
        cout<<endl;
        for (int row = 0; row<BOARD_SIZE; row++)
        {
                for(int col = 0; col<BOARD_SIZE; col++)
                {
                        cout<<"|";
                        cout<< (board[row][col] == QUEEN ? "Q":" ");
                }
                cout<<"|"<<endl;
                for (int i = 0; i<BOARD_SIZE*2+1; i++)
                {
                        cout<<"-";
                }
                cout<<endl;
        }
}


void copy_board(int source[][BOARD_SIZE], int target[][BOARD_SIZE])
{for (int i=0;i<BOARD_SIZE;i++)
for(int j=0;j<BOARD_SIZE;j++)
target[i][j]=source[i][j];

}


void swap(int& a, int& b)
{
        int tmp = a;
        a = b;
        b = tmp;
}


void flip_top_and_bottom(int board[][BOARD_SIZE])
{
	int k=0,q=0;
	for (int i=0;i<BOARD_SIZE;i++){
		k=0;
		for(int j=0;j<BOARD_SIZE;j++){
			if (k==0)
			{
				if (board[j][i]==1)
				{
				   swap( board[j][i],board[BOARD_SIZE-j-1][i]);
				   k=1;
				//TODO: complete this function
				}
			}
		}
	}
}


void flip_left_and_right(int board[][BOARD_SIZE])
{
int k=0;
int j=0;
for (int i=0;i<BOARD_SIZE;i++)
        for( j=0;j<BOARD_SIZE;j++)
                if (board[i][j] ==1){
                     k=BOARD_SIZE-j-1;
 
					  board[i][k]=1;
					 board[i][j]=0;
                   ////////////////////////////////

                      j=BOARD_SIZE;
                        }
}
/*
 this function flips the board along the diagonal axis, for example, it
can change:
 ---------      ---------
 | | | | |      | |Q| | |
 ---------      ---------
 |Q| | | |      | | | |Q|
 ---------  to  ---------
 | | | | |      | | | | |
 ---------      ---------
 | |Q| | |      | | | | |
 ---------      ---------
 */
void transpose(int board[][BOARD_SIZE])
{
	for(int row = 0; row < BOARD_SIZE; row++)
        for(int col = 0; col < row; col++)
          swap(board[row][col],board[col][row]);

}
//this function returns true, if board1 and board2 are identical,otherwise, it returns false
bool are_they_identical(int board1[][BOARD_SIZE], int board2[][BOARD_SIZE])
{
        for(int row = 0; row < BOARD_SIZE; row++)
        {
                for(int col = 0; col < BOARD_SIZE; col++)
                {
                        if(board1[row][col] != board2[row][col])
                                return false;
                }
        }
        return true;
}

//this function returns true, if we can rotate or flip them to make them identical, otherwise, returns false
bool are_they_the_same_by_rotation_flip(int board1[][BOARD_SIZE], int board2[][BOARD_SIZE])
{
        int temp_board[BOARD_SIZE][BOARD_SIZE];
        for(int i = 0; i<2; i++)
        {
                for(int j = 0; j<2; j++)
                {
                        for(int k = 0; k<2; k++)
                        {
                                copy_board(board1, temp_board);
                                if(i == 0)
                                {
                                        flip_top_and_bottom(temp_board);
                                }
                                if(j == 0)
                                {
                                        flip_left_and_right(temp_board);
                                }
                                if(k == 0)
                                {
                                        transpose(temp_board);
                                }
                                if(are_they_identical(board2, temp_board))
                                {
                                        return true;
                                }
                        }
                }
        }
        return false;
}

//this function returns true if each column contains exactly one queen,otherwise returns false
bool is_vertal_safe(int board[][BOARD_SIZE])

{    int k=0;
     for (int i=0;i<BOARD_SIZE;i++)
     {
			 k=0;
           for (int j=0;j<BOARD_SIZE;j++)
           {
			   if (board[j][i] !=0)
                  k++;
			   if (k>1)
               return false;
		   }
		   if(k==0)
			   return false;           
	 }
        //TODO: complete this function
        return true;
}

//this function returns true if each row contains exactly one queen,otherwise returns false
bool is_horizontal_safe(int board[][BOARD_SIZE])
{
	int k=0;
     for (int i=0;i<BOARD_SIZE;i++)
     {
			k=0;
           for (int j=0;j<BOARD_SIZE;j++)//wrong
           {
			   if (board[i][j] !=0)
                           k++;
			   if (k>1)
			   return false;
		   }
		   if(k==0) return false;
           
		  
	 }
        //TODO: complete this function
        return true;
}
//this function returns true if each diagonal line contains at most one queen, otherwise return false
bool is_diagonal_safe(int board[][BOARD_SIZE])
{
        for(int row = -BOARD_SIZE; row < BOARD_SIZE*2; row++)
        {
                int sum_down = 0;
                int sum_up = 0;
                if(row<BOARD_SIZE)
                {
                        for(int col = 0; col < BOARD_SIZE; col++)
                        {
                                if(0<=row+col && row+col<BOARD_SIZE)
                                        sum_down+=board[row+col][col];
                        }
                }
                if(row>=0)
                {
                        for(int col = 0; col < BOARD_SIZE; col++)
                        {
                                if(0<=row-col && row-col<BOARD_SIZE)
                                        sum_up+=board[row-col][col];
                        }
                }
                if(sum_down > 1 || sum_up > 1)
                        return false;
        }
        return true;
}
//this function returns true, if the queens on the board are all safe,otherwise, returns false
bool is_good_layout(int board[][BOARD_SIZE])
{
        if(!is_vertal_safe(board))
                return false;
        if(!is_horizontal_safe(board))
                return false;
        if(!is_diagonal_safe(board))
                return false;
        return true;
}

//this function returns true if we find that the input is already cached,otherwise, returns false
bool is_already_stored(int board[][BOARD_SIZE])
{
        //we check one by one in the cached list
        //see if any one of them are identical with the input, with somerotations or flips
        int temp_board[BOARD_SIZE][BOARD_SIZE];
        for(int i = 0; i<cacheIndex; i++)
        {
                layout_board(cachedResults[i], temp_board);
                if(are_they_the_same_by_rotation_flip(temp_board, board))
                {
                        return true;
                }
        }
        return false;
}

//this function store the the board in the cached list
void store(int arrange[BOARD_SIZE])
{
        for(int i = 0; i<BOARD_SIZE; i++ )
        {
                cachedResults[cacheIndex][i] = arrange[i];
        }
        cacheIndex ++;
}

//this function goes through every possible layout to find all the solutions
void search(){
        //check the "validity" of the layouts
        if(BOARD_SIZE<=4)
        {
                int total_count = 1;
                for(int i = 0; i<BOARD_SIZE; i++)
                {
                        total_count *=BOARD_SIZE;
                }
                for(int code = 0; code<total_count; code++)
                {
                        int board[BOARD_SIZE][BOARD_SIZE];
                        int arrange[BOARD_SIZE];
                        int remain = code;
                        for(int i = 0; i<BOARD_SIZE; i++){
                                arrange[i] = i*500+remain%BOARD_SIZE;
                                remain = remain/BOARD_SIZE;
                        }
                        layout_board(arrange, board);
                        if(is_good_layout(board) &&!is_already_stored(board))
                        {
                                store(arrange);
                        }
                        remain = code;
                        for(int i = 0; i<BOARD_SIZE; i++){
                                arrange[i] = remain%BOARD_SIZE*500+i;
                                remain = remain/BOARD_SIZE;
                        }
                        layout_board(arrange, board);
                        if(is_good_layout(board) &&!is_already_stored(board))
                        {
                                store(arrange);
                        }
                }
                return;
        }
        //if the size of board is larger than 4, to save time, we onlychoose all the cases when queens share no rows or columns
        else{
                int i = 1;
                int j = 1;
                int k = 1;
                int ptr[2*BOARD_SIZE] = {0};

                while((i <= BOARD_SIZE) && (j = j*i))
                {
                        for( ; k <= j; k++)
                        {
                                int begin = BOARD_SIZE;
                                int end = BOARD_SIZE;
                                int l = 1;
                                int n = k;
                                int m = 0;
                                int t = 1;

                                ptr[BOARD_SIZE] = l;

                                while(t < BOARD_SIZE)
                                {
                                        t++;
                                        l++;

                                        m = n%t+1;
                                        n = n/t;

                                        if( m == 1)
                                        {
                                                ptr[++begin] = l;
                                        }
                                        else
                                        {
                                                int move = 0;
                                                move = begin - (m - 1);
                                                if(move < end)
                                                {
                                                        ptr[move] = l;
                                                        end = move;
                                                }
                                                else
                                                {
                                                        for(int index =end; index<=move;index++)
                                                        {
                                                                ptr[index-1]=ptr[index];
                                                        }
                                                        ptr[move] = l;
                                                        end = end - 1;
                                                }
                                        }
                                }
                                //Please ignore the complex calculation above, just assume it is correct and
                                //we have found a combination now, test it:
                                int arrange[BOARD_SIZE];
                                int index = 0;
                                for(int tmp=end; tmp<=begin; tmp++)
                                {
                                        arrange[index] =index*500+ptr[tmp]-1;
                                        index++;
                                }
                                int board[BOARD_SIZE][BOARD_SIZE];
                                layout_board(arrange, board);
                                if(is_good_layout(board) &&!is_already_stored(board))
                                {
                                        store(arrange);
                                }
                        }
                        i++;
                }

        }
}


int main (int argc, char * const argv[])
{
	cout<<BOARD_SIZE<<endl;
        int arrange[BOARD_SIZE];
        for(int i = 0; i<BOARD_SIZE; i++)
        {
                arrange[i] = i;
        }
        search();

        int temp_board[BOARD_SIZE][BOARD_SIZE];
        for(int i = 0; i<cacheIndex; i++)
        {
                cout<<"solution #"<<i<<endl;
                layout_board(cachedResults[i], temp_board);
                print_board(temp_board);
        }
        cout<<"\ntotal solution # = "<<cacheIndex<<endl;
    return 0;
}


