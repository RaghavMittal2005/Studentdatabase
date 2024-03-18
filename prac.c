#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
struct sinfo{
    char first_name[50];
    char last_name[50];
    int roll;
    float cgpa;
    char course[50];
};
int num=0;
int findrollreturn;
struct sinfo s1[100];
void addinfo(){
    printf("Enter the First Name: ");
    scanf("%s",&( s1[num].first_name));
    printf("Enter the Last Name: ");
    scanf("%s",&(s1[num].last_name));
    printf("Enter Roll Number: ");
    scanf("%d",&(s1[num].roll));
    printf("Enter CGPA: ");
    scanf("%f",&(s1[num].cgpa));
    printf("Enter Course Name:");
    scanf("%s",&(s1[num].course));
    num+=1;
    printf("Information added sucessfully");
    choices();
}
void printinfo(int i){
    printf("Student Name: %s %s\n",s1[i].first_name,s1[i].last_name);
    printf("Roll Number:%d\n",s1[i].roll);
    printf("CGPA:%.2f\n",s1[i].cgpa);
    printf("Course Name:%s\n",s1[i].course);
    choices();
}
void deletesinfo(){
    int searchroll;
    printf("Enter Roll Number of Student to Delete: ");
    scanf("%d", &searchroll);
    int found = 0;
    
    // Find the index of the student to delete
    for(int i = 0; i < num; i++){
        if(searchroll == s1[i].roll){
            printf("Found it\n");
            found = 1;
            findrollreturn = i;
            break;
        }
    }
    
    if(found){
        // Shift all records above the found index one position downwards
        for(int a = findrollreturn; a < num - 1; a++){
            strcpy(s1[a].first_name, s1[a + 1].first_name);
            strcpy(s1[a].last_name, s1[a + 1].last_name);
            strcpy(s1[a].course, s1[a + 1].course);
            s1[a].roll;
            s1[a].cgpa = s1[a + 1].cgpa;
        }
        // Decrement the total number of records
        num--;
        printf("Student information deleted successfully.\n");
    } else {
        printf("Student with given roll number not found.\n");
    }
    choices();
}

int findfname(){
    char searchname[50];
    printf("Enter First Name of Student: ");
    scanf("%s",&searchname);
    for(int i=0;i<num;i++){
        int x=strcmp(searchname,s1[i].first_name);
        if(x==0){

            printf("Found it\n");
            printinfo(i);
            findrollreturn=i;
        }
        else
        {
            printf("Not Found\n");
        }      
    }
}
int findroll(){
    int searchroll;
    int se=0;
    printf("Enter Roll Number of Student: ");
    scanf("%d",&searchroll);
    for(int i=0;i<num;i++){
        if(searchroll==s1[i].roll){
            printf("Found it\n");
            printinfo(i);
            se=1;
            findrollreturn=i;
        }
    }
    if(se==0){
        printf("Not Found\n");
    }
}
int findsinfo(){
    int ch,x;
    printf("Choose how to Find student details\n");
    printf("1.First Name\n");
    printf("2.Roll Number\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case (1):
        x=findfname();
    
    case(2):
        x=findroll();
        break;
    
    default:
        printf("Invalid Choice");
        break;
    }
    return x;
}
void updatesinfo(){
    int searchroll;
    printf("Enter Roll Number of Student: ");
    scanf("%d",&searchroll);
    for(int i=0;i<num;i++){
        if(searchroll==s1[i].roll){
            printf("Found it\n");

            findrollreturn=i;
        }
    }
    char fname[50];
    printf("Enter Correct First Name:");
    scanf("%s",&(s1[findrollreturn].first_name));
    printf("Enter the Correct Last Name: ");
    scanf("%s",&(s1[findrollreturn].last_name));
    printf("Enter Correct Roll Number: ");
    scanf("%d",&(s1[findrollreturn].roll));
    printf("Enter Correct CGPA: ");
    scanf("%f",&(s1[findrollreturn].cgpa));
    printf("Enter Correct Course Name:");
    scanf("%s",&(s1[findrollreturn].course));
    printf("\nInformation Updated Successfully.\n");
    choices();

}
int choices(){
    int option;
    printf("\n1.Add Student Details\n");
    printf("2.Find Student Details\n");
    printf("3 Update Student Details\n");
    printf("4 Delete Student Details\n");
    printf("5.Exit\n");
    printf("Enter the Number corresponding to which operation is to be executed");
    scanf("%d",&option);
    switch(option){
        case(1):
          addinfo();
          break;
        case(2):
          findsinfo();
          break;
        case(3):
          updatesinfo();
          break;
        case(4):
          deletesinfo();
          break;
        case(5):
          exit;
          return 0;
        default:
          printf("Invalid Choice");
          break;
    }
}
int main(){
    int op;
    printf("Welcome to Student Database Management System");
    printf("\n1.Add Student Details\n");
    printf("2.Find Student Details\n");
    printf("3 Update Student Details\n");
    printf("4 Delete Student Details\n");
    printf("5.Exit\n");
    printf("Enter the Number corresponding to which operation is to be executed");
    scanf("%d",&op);
    switch(op){
        case(1):
          addinfo();
          break;
        case(2):
          findsinfo();
          break;
        case(3):
          updatesinfo();
          break;
        case(4):
          deletesinfo();
          break;
        case(5):
          printf("Thanks for visiting");
          return 0;
        default:
          printf("Invalid Choice");
          break;
    }
}

