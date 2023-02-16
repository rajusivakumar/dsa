#include<iostream.h>
#include<conio.h>
void main()
{
int i,num,first,last,middle,n;
clrscr();
cout<<"\nEnter the number of elements in array:";
cin>>n;
int *arr=new int(n);
cout<<"\nEnter "<<n<<" elements in ascending order:";
for(i=0;i<n;i++)
cin>>arr[i];
cout<<"\nEnter the element to be searched";
cin>>num;
first=0;
last=n-1;
middle=(first+last)/2;
while(first<=last)
{
if(arr[middle]<num)
first=middle+1;
else if(arr[middle]==num)
{
cout<<"\nThe number "<<num<<" is found at position "<<middle+1;
break;
}
else
last=middle+1;
middle=(first+last)/2;
}
if(first>last)
cout<<"\nThe number "<<num<<" is not found in given array!";
getch();
}