#include <stdio.h>
#include <stdlib.h>
#define m 49
#define n 1
#define x 49
#define num_data 11
#define num_inputs 5
#define N 7
int weighted_matrix[m][x];
int test_pattern[num_inputs][m][n];
int input[num_data][m][n];
 int output[num_data][x][n];
char set[num_data]={'G','H','S','A', 'I', 'L', 'M', 'P', 'X', /*'C','E',*/'B','D'};

//G highly matches with C
//L highly matches with E if E is inserted
int test_pattern[num_inputs][m][n]=
{
               {-1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,
                1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1}, // A

                {-1,1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,
                -1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,-1}, //I

                 {1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
                 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,1}, //L

                  {-1,1,1,-1,1,1,-1,
                  1,-1,-1,1,-1,-1,-1,
                  1,-1,-1,-1,-1,1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,1,-1,1,1,
                  1,1,-1,-1,-1,-1,1,
                  -1,1,1,-1,1,1,1
                 } ,//G

                /*   {-1,1,1,1,1,1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  -1,1,1,1,1,1,-1
                 },*/ //C

                 {-1,-1,1,1,1,1,-1,
                  -1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,1,-1,
                  -1,1,1,1,1,1,-1,
                  -1,-1,1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,1,-1,
                  -1,1,-1,1,1,-1,1
                 } //S*/

};


int input[num_data][m][n]={
                 {-1,1,1,1,1,1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,1,1,1,1,
                  1,-1,-1,-1,-1,-1,1,
                  -1,1,1,1,1,1,1
                 }, //G


                {1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,1,1,1,1,1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1
                 }, //H

                 {-1,-1,1,1,1,1,-1,
                  -1,1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,-1,
                  -1,1,1,1,1,1,-1,
                  -1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,1,-1,
                  -1,1,1,1,1,-1,-1
                 }, //S


                {-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,1,
                1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1}, // A

                {-1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,
                -1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1}, //I

                 {1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,
                 1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1}, //L

                  {1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,
                  -1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1}, //M

                 {1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,
                 -1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1}, //P

                 {1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,
                 1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1}, //X

               /* {-1,1,1,1,1,1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  -1,1,1,1,1,1,-1
                 }, //C
                 {1,1,1,1,1,1,1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,1,1,1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,1,1,1,1,1,1
                 }, */  //E

                 {1,1,1,1,1,-1,-1,
                  1,-1,-1,-1,-1,1,-1,
                  1,-1,-1,-1,-1,-1,1,
                  1,1,1,1,1,1,-1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,1,-1,
                  1,1,1,1,1,-1,-1
                 } ,//B

                { 1,1,1,1,1,-1,-1,
                  -1,1,-1,-1,-1,1,-1,
                  -1,1,-1,-1,-1,-1,1,
                  -1,1,-1,-1,-1,-1,1,
                  -1,1,-1,-1,-1,-1,1,
                  -1,1,-1,-1,-1,1,-1,
                   1,1,1,1,1,-1,-1
                 } //D





                            };
    int output[num_data][x][n]={
                              {-1,1,1,1,1,1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,1,1,1,1,
                  1,-1,-1,-1,-1,-1,1,
                  -1,1,1,1,1,1,1
                 }, //G


                {1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,1,1,1,1,1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,1
                 }, //H

                 {-1,-1,1,1,1,1,-1,
                  -1,1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,-1,-1,
                  -1,1,1,1,1,1,-1,
                  -1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,1,-1,
                  -1,1,1,1,1,-1,-1
                 }, //S


                {-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,1,
                1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1}, // A

                {-1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,
                -1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1}, //I

                 {1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,
                 1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1}, //L

                  {1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,
                  -1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1}, //M

                 {1,1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,
                 -1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1}, //P

                 {1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,-1,
                 1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1}, //X

               /* {-1,1,1,1,1,1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  -1,1,1,1,1,1,-1
                 }, //C
                 {1,1,1,1,1,1,1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,1,1,1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,-1,-1,-1,-1,-1,-1,
                  1,1,1,1,1,1,1
                 }, */  //E

                 {1,1,1,1,1,-1,-1,
                  1,-1,-1,-1,-1,1,-1,
                  1,-1,-1,-1,-1,-1,1,
                  1,1,1,1,1,1,-1,
                  1,-1,-1,-1,-1,-1,1,
                  1,-1,-1,-1,-1,1,-1,
                  1,1,1,1,1,-1,-1
                 } ,//B

                { 1,1,1,1,1,-1,-1,
                  -1,1,-1,-1,-1,1,-1,
                  -1,1,-1,-1,-1,-1,1,
                  -1,1,-1,-1,-1,-1,1,
                  -1,1,-1,-1,-1,-1,1,
                  -1,1,-1,-1,-1,1,-1,
                   1,1,1,1,1,-1,-1
                 } //D



                                };




void CheckErrorRate(int op[m][n])
{
    //printf("hiii");
    float count=0;
    int i,j;
    int itr=0;
    float max;
    char ch;
    while(itr<num_data)
    {
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(op[i][j]==input[itr][i][j])
            {
                count++;
            }
        }
    }

     printf("\nTest pattern matching percentage with %c is : %f\n",set[itr],100*(float)(count/m));
    itr++;
    count=0;
   // printf("\nTest pattern most matches to %c ",ch);
    }



}
void Print2DArray(int weighted_matrix[m][x])
{
    int i,j;
 for(i=0;i<m;i++)
 {
     for(j=0;j<x;j++)
     {
         printf("%d ",weighted_matrix[i][j]);
     }
     printf("\n");
 }
}
int Converge(int output_itr[x][n],int output_itr1[x][n], int input_itr[m][n],int input_itr1[m][n] )
{
    int flag1=0;
    int flag2=0;
    int flag=0;
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<n;j++)
        {
            if(output_itr[i][j]==output_itr1[i][j])

                flag1=1;
            else
            {
                flag1=0;
                break;
            }

        }
        if(flag1==0)
            break;
    }

     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(input_itr[i][j]==input_itr1[i][j])

                flag2=1;
            else
            {
                flag2=0;
                break;

            }

        }
        if(flag2==0)
            break;
    }
    if(flag1==1 && flag2==1)
        flag=1;
    return flag;
}



void CheckTestPattern(int test_pattern[m][n], int weighted_matrix[m][x] )
{
   int output_itr[2000][x][n]={0};
    // output_itr[0][x][n]={0};
    int input_itr[2000][m][n]={0};
    //input_itr[0][m][n]={0};

   int i=0;

   do
   {
        i++;
    int i1,j,k;
    int wieghted_transpose[x][m];
    for(i1=0;i1<m;i1++)
    {
        for(j=0;j<x;j++)
        {
            wieghted_transpose[j][i1]=weighted_matrix[i1][j];
        }
    }
    int sum=0;
    for(i1=0;i1<x;i1++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                sum=sum+ wieghted_transpose[i1][k]*test_pattern[k][j];
            }
            output_itr[i][i1][j]=sum;
            if(output_itr[i][i1][j]<0)
                output_itr[i][i1][j]=-1;
            else
                output_itr[i][i1][j]=1;
            sum=0;
        }
    }


    int sum1=0;
    for(i1=0;i1<m;i1++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<x;k++)
            {
                sum1=sum1+ weighted_matrix[i1][k]*  output_itr[i][k][j];
            }
            input_itr[i][i1][j]=sum1;
            if(input_itr[i][i1][j]<0)
                input_itr[i][i1][j]=-1;
            else
                input_itr[i][i1][j]=1;
            sum1=0;
        }
    }
    //output_itr[i]= matrixmul_out(weighted_matrix,transpose,test_pattern, m, x , n  );
    //input_itr[i] = matrixmul_inp(weighted_matrix, transpose-1, output_itr, m ,x , n );

   }while(!Converge(output_itr[i],output_itr[i-1],input_itr[i],input_itr[i-1]) );

   /*int w,t;
   for(w=0;w<x;w++)
   {
       for(t=0;t<n;t++)
       {
           printf("%d ",output_itr[i-1][w][t]);
       }

   }*/
   CheckErrorRate(output_itr[i-1]);
}
void PrintTestingPattern()
{
     printf("\n");
    int a,b=0,c;
    int b1=0,c1=0;
    int ip[num_data][7][7];
    for(a=0;a<num_inputs;a++)
    {
          printf("\n");
        //printf("\n%d",a);
        for(b1=0;b1<7;b1++)
        {
            for(c1=0;c1<7;c1++)
            {
                ip[a][b1][c1]=test_pattern[a][b][0];
                b++;
                if(ip[a][b1][c1]<0)
                    printf(" ");
                else
                    printf("O");
            }
            printf("\n");

        }
        b=0;
          printf("____________\t\n");
           CheckTestPattern(test_pattern[a],weighted_matrix);
    }



}
void PrintinputPattern()
{
    int a,b=0,c;
    int b1=0,c1=0;
    int ip[num_data][7][7];
    for(a=0;a<num_data;a++)
    {
          printf("\n");
        //printf("\n%d",a);
        for(b1=0;b1<7;b1++)
        {
            for(c1=0;c1<7;c1++)
            {
                ip[a][b1][c1]=input[a][b][0];
                b++;
                if(ip[a][b1][c1]<0)
                    printf(" ");
                else
                    printf("O");
            }
            printf("\n");

        }
        b=0;
          printf("____________\t\n");
    }

}
// Function to get cofactor of mat[p][q] in temp[][]. n is current
// dimension of mat[][]
void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n1)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n1; row++)
    {
        for (int col = 0; col < n1; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n1 - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[N][N], int n1)
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n1 == 1)
        return mat[0][0];

    int temp[N][N]; // To store cofactors

    int sign = 1;  // To store sign multiplier

     // Iterate for each element of first row
    for (int f = 0; f < n1; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n1);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n1 - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}

/* function for displaying the matrix */
void display(int mat[N][N], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("  %d", mat[i][j]);
        printf("n");
    }
}
 void CheckLinearlyDependency()
 {
     int i,j,k,it=0,count=0;
     int mat[7][7];
     for(i=0;i<num_data;i++)
     {
         for(j=0;j<7;j++)
         {
             for(k=0;k<7;k++)
             {
                 mat[j][k]=input[i][it][0];
                 it++;
             }
         }
         it=0;
         int ans= determinantOfMatrix(mat, 7);
        // printf("ans : %d",ans);
     if(ans!=0)
        count++;


     }
          if(count==num_data)
        printf("Go for gram schmidt");
        else
             printf("cant Go for gram schmidt");
 }
int main()
{
    PrintinputPattern();
    //CheckLinearlyDependency();
    int i,k;
    int weighted_sum=0;
    int itr=0;


         for(i=0;i<m;i++)
        {

            for(k=0;k<x;k++)
            {
                     while(itr<num_data)
                      {
                    weighted_sum=weighted_sum+input[itr][i][0]*output[itr][k][0];
                     itr++;
                      }
                    weighted_matrix[i][k]=weighted_sum;
                     itr=0;
                     weighted_sum=0;
            }

        }
    //printf("Weighted matrix is :\n");
  //  Print2DArray(weighted_matrix);
    printf("\n");
   printf("pattern to be tested : \n");
   PrintTestingPattern();
   printf("\n");

    return 0;
}
