#include<stdio.h>

		struct record
		{
			char Name[20];
			int Rollno;
			int Phoneno;
			char Address[100];
		};
		 
	void addStudent()
	
	{ 
		struct record student;
		FILE *ptr;
			fflush(stdin);
			
			  printf(" \n Enter the record=");
			  printf("\n Enter the Name=");
			  gets(student.Name);
			  
			  fflush(stdin);
			  printf("\n Enter the Rollno.=");
			  scanf("%d",&student.Rollno);
			    
			  fflush(stdin);
			  printf("\n Enter the Phoneno.=");  
			  scanf("%d",&student.Phoneno);
			  
			  fflush(stdin);
			  printf("\n Enter the Address=");
			  gets(student.Address);
			  
		 ptr=fopen("student.txt","a");
		fwrite((char*)&student,sizeof(student),1,ptr);
		fclose(ptr);
	}
	
	void deleteStudent()
	{
		int r;
       struct record student;
         FILE *ptr, *ptr2;
          int found = 0;
          ptr = fopen("student.txt", "r");
          ptr2 = fopen("stud.txt", "w");
          printf("Enter the Rollno to delete: ");
          scanf("%d", &r);

    
    while (fread(&student, sizeof(student), 1, ptr)) 
	{
        if (student.Rollno != r)
	    {
            fwrite(&student, sizeof(student), 1, ptr2);
         } 
		else
		{
		
            found = 1;
        }
    }

    fclose(ptr);
    fclose(ptr2);

     
       if (found)
	    {
           remove("student.txt");
           rename("stud.txt", "student.txt");
           printf("Record deleted successfully.\n");
        } 
    	else 
	    {
           remove("stud.txt");
           printf("Record not found.\n");
        }
		
	}
	
	void searchStudent()
	{
		int r;
		struct record student;
		FILE *ptr;
		ptr=fopen("student.txt","r");
		printf("Enter the Rollno=");
			scanf("%d",&r);
	
		while(fread(&student,sizeof(student),1,ptr))
		{
			if(student.Rollno==r)
			{
					printf("\n %s %d %d %f",student.Name,student.Rollno,student.Phoneno,student.Address);
		    }
		    else
		    {
		    	printf("Sorry ,record not found");
			}
			
		}
		
		fclose(ptr);

		
	}
	
	void displayStudent()
	{
		struct record student;
		FILE *ptr;
		ptr=fopen("student.txt","r");
		
	
		while(fread(&student,sizeof(student),1,ptr))
		{
			printf("\n %s %d %d %f",student.Name,student.Rollno,student.Phoneno,student.Address);
		}
		
		fclose(ptr);
		

		
		
	}
	main()
	{
		int choice;
		do
		{
			printf("\n\t\t\t\t\t\t Students Record System");
			printf("\n\t\t\t\t\t\t Press 1: For insertion");
			printf("\n\t\t\t\t\t\t Press 2: For deletion");
			printf("\n\t\t\t\t\t\t Press 3: For searching");
			printf("\n\t\t\t\t\t\t Press 4: For displaying");
			printf("\n\t\t\t\t\t\t Press 5: For exit");
			printf("\n\t\t\t\t\t\t Enter your choice:-");
			scanf("%d",&choice);
				
				switch(choice)
				{
					case 1:
						addStudent();
						break;
					case 2:
						deleteStudent();
						break;
					case 3:
						searchStudent();
						break;
					case 4:
						displayStudent();
						break;
					case 5:
						printf("\n\t\t\t\t\t\tExit");
						break;
					default:
						printf("\n\t\t\t\t\t\t Sorry,Try Again");
				}
		}
		while(choice!=5);
			
	}
