include <stdio.h>

int main()
{
  int a[] = {1,2,3,4,5,6,7,8,1,1,2,1,3,1,5};

  int i=0;
  int j=sizeof(a)/sizeof(a[0]);

  while(i<j)
  {
    if(a[i] == 1)
    {
      while((j-1 > i) && (a[j-1] == 1))
      {
        j--;
      }
      a[i++] = a[--j];
    }
    else
    {
      i++;
    }
  }

  for(i=0; i<j; i++)
  {
    printf(" %d ", a[i]);
  }
  printf("\n");
}
