#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct info {
char name[50];
int id,qu;

}; //DONE
void insertBook( struct info *information, int numberofbooks) {

FILE *pointerToBooks=fopen("books.txt","a");

   if(pointerToBooks!=NULL){
fflush(stdin);
printf("Enter book name :  ");
gets(information[numberofbooks].name);


printf("\n Enter book ID : ");
scanf("%d",&information[numberofbooks].id);


printf("Enter book quantity : ");
scanf("%d",&information[numberofbooks].qu);

fprintf(pointerToBooks,"\n %s %d %d",information[numberofbooks].name,information[numberofbooks].id,information[numberofbooks].qu);



}
  else{
   printf("ERROR IN OPINING FILE");
   }

fclose(pointerToBooks);


} // Display all books unsorted

void DisplayAllUNSORTED(struct info *information,int size){

for(int i=0;i<size;i++){
    printf(" ID:%d quantity:%d BOOK NAME :%s\n",information[i].id,information[i].qu,information[i].name);

}
} //DONE
int searchBYid(struct info *information,int size ,int id,int u){

for(;u<size;u++){
if(information[u].id==id){//fflush(stdin);


   printf("BOOK NAME :%s ID:%d quantity:%d \n",information[u].name,information[u].id,information[u].qu);
return 0 ;
}
if(information[u].id!=id){u++;
return searchBYid(information,size,id,u);
}

} printf("ID NOT FOUND \n");

}
void searchbyname(struct info *information,char * bookname,int size,int low){


 struct info h;
 for(int i=0;i<size-1;i++){

 int res = strcmp(information[i].name,information[i+1].name) ;

if(res>0){
h=information[i+1];
information[i+1]=information[i];
information[i]=h;

 }
 }






while(low<=size){ int mid=(size+low)/2;
 int res = strcmp(information[mid].name,bookname) ;
 printf("%d",res);
if(res==0){
   printf("BOOK NAME :%s ID:%d quantity:%d \n",information[mid].name,information[mid].id,information[mid].qu);
return ;

}

if(res>0){
 size= mid - 1;
}
if(res<0){
  low= mid + 1;
}
}
printf(" NOT FOUND \n");


}
void sortingbyname(struct info *information,int size){



 struct info h;
  struct info newarray[50];// new struct array to not effect the orginal array in case user want to unsorted array again
for(int i=0;i<size;i++){
newarray[i]=information[i];

}
for(int p=1;p<size;p++){
 for(int i=0;i<size-p;i++){

 int res = strcmp(newarray[i].name,newarray[i+1].name) ;

if(res>0){
h=newarray[i+1];
newarray[i+1]=newarray[i];
newarray[i]=h;

 }
 }
}
for(int i=0;i<size;i++){
    printf(" ID:%d quantity:%d BOOK NAME :%s\n",newarray[i].id,newarray[i].qu,newarray[i].name);

}
 }//end of sorting by name


void deletebookbyid(struct info *information,int size){
int id;
struct info f[20];


printf("Enter id for deleting:");
scanf("%d",&id);
for(int i=0;i<size;i++){
if (information[i].id==id){
for(int a=i;a<size;a++){
information[a]=information[a+1];
}
}
}

FILE *pointerToBooks=fopen("books","w");

   if(pointerToBooks!=NULL){

for(int i=0;i<size-1;i++){
fprintf(pointerToBooks,"%s %d %d \n",information[i].name,information[i].id,information[i].qu);
}
printf("book deleted \n");




}
  else{
   printf("ERROR IN OPINING FILE");
   }
   fclose(pointerToBooks);

}
int main()
{
struct info information [20]; // struct  name
int i =0;
int numberOFbooks=4;
int choose; // user choice
char another[5]; // if he want another operation
int id;
char book[50]; // in search by name function
char yes;
int y;
int x;
FILE *pointerToBooks=fopen("books","r");

   if(pointerToBooks!=NULL){

char line[256];

while(fgets(line, sizeof(line), pointerToBooks) != NULL){

    sscanf(line, "%d %d %[^\n]", &information[i].id, &information[i].qu,information[i].name);
    /* Where do the numbers end... */
  // size_t numbers_end = strspn(line, "1234567890 ");
    /* And get the name */
   // information[i].name = line + numbers_end;
  //strcpy(information[i].name, line+numbers_end);
  printf("%d %d %s\n",information[i].id, information[i].qu,information[i].name);

    i++;
}

}
  else{
   printf("ERROR IN OPINING FILE");
   }
 do{
   printf("choose the number of whatever you want\n 1- insert a book \n 2-Delet a book by id\n 3- search a book by id \n 4- searh a book by name\n 5- Display all books sorted by name \n 6- Display all books unsorted\n number of choice: ");
   scanf("%d", &choose);
   switch(choose){
   case 1 :
    insertBook(information,numberOFbooks);

    break;
    case 2: deletebookbyid(information,numberOFbooks);
    break;
    case 3:

printf("Enter book ID : ");
scanf("%d",&id);
int u=0;
searchBYid(information,numberOFbooks,id,u);
break;
case 4:
printf("ENTER BOOK NAME :");
gets(book);
searchbyname(information,book,numberOFbooks,0);
break;
case 5: sortingbyname(information, numberOFbooks);
break;
case 6: DisplayAllUNSORTED(information,numberOFbooks);
break;
   }
   printf("do you want to perform any addition operator [y/n]\n");
   scanf("%s",another);


 x=strcmp(another,"yes");
 y=strcmp(another,"Yes");


   } while(x==0||y==0);
fclose(pointerToBooks);//end of programe

    return 0;
}

