#include <stdio.h>

#define m_w 5
#define m_h 5
#define k_w 3
#define k_h 3

int img[m_w][m_h];/*需要運算矩陣*/
int kernel[k_w][k_h];/*卷積核*/ 
int result[m_w-k_w+1][m_h-k_h+1];/*vaild下的輸出 */

int main()
{
	int i,j;
	int img[m_w][m_h] = {{1,2,3,4,1},
	                     {5,6,7,8,1},
	                     {8,7,6,5,2},
	                     {4,3,2,1,3},
	                     {6,7,4,5,2}};
	
	printf("請輸入要運算的矩陣：\n");
	for(i=0;i<m_w;i++)
    {
    	for(j=0;j<m_h;j++)
	    {
	    	printf("%d",img[i][j]);
		}	
		printf("\n");
	}
	printf("\n");
	int kernel[k_w][k_h] = {{1,0,0},
	                        {0,1,0},
	                        {0,0,-1}};
	printf("請輸入卷積核：\n");
	for(i=0;i<k_w;i++)
    {
    	for(j=0;j<k_h;j++)
	    {
	    	printf("%d",kernel[i][j]);
		}	
		printf("\n");
	}
	
	convolution(img,kernel,result); /*卷積運算 */
	
	printf("結果輸出(valid)：\n");
	for(i=0;i<m_w-k_w+1;i++)
    {
    	for(j=0;j<m_h-k_h+1;j++)
	    {
	    	printf("%d ",result[i][j]);
		}	
		
		printf("\n");
	}
	
	return 0;
 } 
 
 void convolution(int img[m_w][m_h], int kernel[k_w][k_h],int result[m_w-k_w+1][m_h-k_h+1])
{
    int i,j;
    int n,m;
    for(i=0; i<m_w-k_w+1; i++)
    {
        for(j=0; j<m_h-k_h+1; j++)
        {
            int temp = 0;
            for(m=0; m<k_w; m++)
            {
                for(n=0; n<k_h; n++)
                { 
                    temp+=img[i+m][j+n]*kernel[m][n];
                }
            } 
            result[i][j]=temp;
        }
    } 
}

