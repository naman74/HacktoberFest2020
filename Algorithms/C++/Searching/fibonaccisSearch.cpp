#include<iostream.h>
#include<conio.h>
int min(int x, int y)
{
    return (x<=y)? x : y;
}
int fibonaccianSearch(int arr[], int x, int n)
{
    int fbM2 = 0;  
    int fbM1 = 1;  
    int fbM = fbM2 + fbM1;  
    int offset = -1;
    while (fbM < n)
    {
        fbM2 = fbM1;
        fbM1 = fbM;
        fbM  = fbM2 + fbM1;
    }
    while (fbM > 1)
    {
    int i = min(offset+fbM2, n-1);
   
    if (arr[i] < x)
    {
        fbM  = fbM1;
        fbM1 = fbM2;
        fbM2 = fbM - fbM1;
        offset = i;
    }
    
    else if (arr[i] > x)
    {
        fbM  = fbM2;
        fbM1 = fbM1 - fbM2;
        fbM2 = fbM - fbM1;
    }
    
    else return i;
    }
    
    if(fbM1 && arr[offset+1]==x)
    return offset+1;
    
    return -1;
}

int main(void)
{
    clrscr();
    int l;
    cout<<"\nEnter the number of elements in array which should be less than 10";
    cin>>l;
    int arr[10];
    cout<<"Enter elements in array";
    for(int i=0;i<l;i++)
    {
    cin>>arr[i];
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"\nEnter element to be searched :" ;
    cin>>x;
    cout<<"Found at index:"<<fib1onaccianSearch(arr, x, n);
    getch();
    return 0;
}