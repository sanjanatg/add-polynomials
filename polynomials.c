#include <stdio.h>
#include <stdlib.h>
#define CALLOC(p, type, n) \
    p = (type*)calloc(n, sizeof(type)); \
    if (p == NULL) { \
        printf("Insufficient memory\n"); \
        exit(0); \
    }
    
typedef struct
{
    int coeff,expo;
}POLYNOMIAL;

//funtion to add polynomials
void addpoly(POLYNOMIAL p[],int terms,POLYNOMIAL result[],int*resultTerms)
{
    int i,j,k=0; //counter variables
    int found;
    for(i=0;i<terms;i++)
    {
        found=0;
        for(j=0;j<k;j++)
        {// iterating and checking if degrees are equal
            if(result[j].expo==p[i].expo)
            {//if true  then add coefficients
                result[j].coeff+=p[i].coeff;
                found=1;
                break;
            }
        }
        if(!found)//if degree not found in the result array
        {
            result[k].coeff=p[i].coeff;
            result[k].expo=p[i].expo;
            k++;//update k value
        }
    }
    *resultTerms=k;//pointer to update the variables so the main function can access it
}

int main()
{
    int n1,*p1;
    printf("Enter the size of the array to store all polynomials:  ");
    scanf("%d",&n1);
    POLYNOMIAL *p, *result;
    // Dynamic memory allocation for p and result arrays
    CALLOC(p, POLYNOMIAL, n1);
    CALLOC(result, POLYNOMIAL, n1);
    int n,i,j,terms=0,resultTerms=0;
    int Numterms;

    
    printf("enter the number of polynomials : ");
    scanf("%d",&n);

    //reading values
    for(i=0;i<n;i++)
    {
        printf("\nEnter the number of terms in the polynomial %d: ",i+1);
        scanf("%d",&Numterms);
        
        for(j=0;j<Numterms;j++)
        {
            printf("Enter the degree of the term %d = ",j+1);
            scanf("%d",&p[terms+j].expo);
            printf("Enter the co-eff of x^%d= ",p[terms+j].expo);
            scanf("%d",&p[terms+j].coeff);
            
        }
        terms+=Numterms;
    }

    
    addpoly(p,terms,result,&resultTerms);//Function call;
    
    printf("\n-----------Resulting Polynomial----------- :\n");
    
    for(i=0;i<resultTerms;i++)
    {
        if(result[i].coeff!=0)
        {
            if(i>0&& result[i].coeff>0)
            { //checking for the positive and negative coeff
                printf("+");//prints + if coeff is positive
            }
            printf("%dx^%d",result[i].coeff,result[i].expo);
        }
    }
    printf("\n");
    return 0;
}
