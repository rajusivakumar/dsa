#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int i,n,arr[100],s,flag=1;
cout<<"Enter the size of array";
cin>>n;
cout<<"\nEnter the values in ascending order:";
for(i=0;i<n;i++){
cout<<"Enter the value for "<<i+1<<" :";
cin>>arr[i];
}
cout<<"Enter the number you want to search:";
cin>>s;
for(i=0;i<n;i++){
if(arr[i]==s){
cout<<"\n\t\tSEARCH SUCCESSFUL";
cout<<"\nThe given number at:"<<i+1;
flag=0;
break;
}}
if(flag==1){
cout<<"\n\t\tSEARCH UNSUCCESSFUL";
}
getch();
}