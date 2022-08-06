#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> //sleep()
#include<dirent.h> //directory kontrolü için kullanýlýr.  


typedef struct{
	char name[8];
	int cap;
}plane_information;                 


typedef struct{
	plane_information plane;
	char company[15];
}port_information;


void add_port(char *directory_name){  
    
	char full_name[30];
	char port1[]="/PORT_1.txt";
	char port2[]="/PORT_2.txt";
	char port3[]="/PORT_3.txt";
	//directory_name -> 11.22.2022  we add the end of name /port1 /port2 /port3..
	
	//port1..
	strcpy(full_name,directory_name);
	strcat(full_name,port1);
	FILE *p1=fopen(full_name,"w");
	fprintf(p1,"0----------------------------------------\n                   |  |\n                   |  |\n                   |  |\n                   /  |\n                |--    ------\nP0RT_1          |---------");
	strcpy(full_name,"");
	
	//port2..
	strcpy(full_name,directory_name);
	strcat(full_name,port2);
	FILE *p2=fopen(full_name,"w");
	fprintf(p2,"0----------------------------------------\n                   |  |\n                   |  |\n                   |  |\n                   /  |\n                |--    ------\nP0RT_2          |---------");
	strcpy(full_name,"");
	
	//port3..
	strcpy(full_name,directory_name);
	strcat(full_name,port3);
	FILE *p3=fopen(full_name,"w");
	fprintf(p3,"0----------------------------------------\n                   |  |\n                   |  |\n                   |  |\n                   /  |\n                |--    ------\nP0RT_3          |---------");
	strcpy(full_name,"");
	if(!fclose(p1) && !fclose(p2) && !fclose(p3))
	puts("ports closed.");
}
void add_date(){
	
	puts("dates loading..");
	FILE *p1=fopen("tarih.txt","r+");
	FILE *p2=fopen("dates.txt","r+");
	if(p1!=NULL && p2!=NULL)
	puts("dates opened.");
	int bir,iki;
	rewind(p1);
	bir=fgetc(p1);
	iki=fgetc(p1);
	bir=bir-'0';
	iki=iki-'0';
	bir*=10;
	int sayi=bir+iki;
	if(sayi<30){
		sayi++;
	}
	else{
		sayi=01;
		fseek(p1,3,SEEK_SET);
	    bir=fgetc(p1);
	    iki=fgetc(p1);
	    iki=iki-'0';
	    iki++;
	    iki=iki+'0';
	    fseek(p1,3,SEEK_SET);
	    fprintf(p1,"%c%c",bir,iki);
	}
	
	bir=sayi/10;
	iki=sayi%10;
	bir=bir+'0';
	iki=iki+'0';
	rewind(p1);
	fprintf(p1,"%c%c",bir,iki);
	rewind(p1);
	char dizi[15];
	fscanf(p1,"%s",&dizi);
	mkdir(dizi);
	add_port(dizi);
	fseek(p2,0,SEEK_END);
	fprintf(p2,"%s\n",dizi);
	if(fclose(p2)==0 && fclose(p1)==0){
		puts("dates closed");
		sleep(2);
		system("cls");
	}
}

void company_registration(port_information *ports){
	
	int i,control=0;
	int port_number;
	int port_position[6];
	char date[19],temp[19],addport[]="/PORT_";
	
	puts("What date would you like to save?");
	gets(date);
	strcat(date,addport); //11.22.2022/PORT_
	strcpy(temp,date);
	strcat(date,"1.txt");
		FILE *p1=fopen(date,"r+");
	strcpy(date,temp);
	strcat(date,"2.txt");
		FILE *p2=fopen(date,"r+");
	strcpy(date,temp);
	strcat(date,"3.txt");
		FILE *p3=fopen(date,"r+");
		
		if(p1!=NULL && p2!=NULL && p3!=NULL){
			puts("being checked..");
			//sleep(1);
			//puts("files opened.");
		}
		
		puts("what your company name?");
	    scanf("%s",&ports[0].company);
		rewind(p1);
		rewind(p2);
		rewind(p3);
		
		if(fgetc(p1)=='0'){
			port_position[0]=0;
		}
		else{
			port_position[0]=1;
		}
		if(fgetc(p2)=='0'){
			port_position[1]=0;
		}
		else{
			port_position[1]=1;
		}
		if(fgetc(p3)=='0'){
			port_position[2]=0;
		}
		else{
			port_position[2]=1;
		}
		
		for(i=0;i<3;i++){
			if(port_position[i]==0){
				printf("%d ",i+1);
				control=1;
			}
		}
	if(control==1){
	puts(" ports are empty..");
	printf("which one do you want? ");
	scanf("%d",&port_number);
	control=0;
	switch(port_number){
		case 1:
			if(port_position[0]==0){
				rewind(p1);
				fputc('1',p1);
				control=1;
				fseek(p1,1,SEEK_END);               
			    fprintf(p1," ****  \n                           *    *\n                          *      *\n                         *        *\n              ************        **************\n              *           OOO  OOO             *\n              *           OOO  OOO             *\n              ************OOO  OOO**************\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *        *\n                          *      *\n                           ******");
			    puts("what is the number of plane you want add to this port?");
			    fseek(p1,3,SEEK_CUR);
			    scanf("%s",&ports[0].plane.name);
			    fputs(ports[0].plane.name,p1);
				fseek(p1,5,SEEK_END);
			    fputs("company:",p1);
				fputs(ports[0].company,p1);
				
			}
			else{
				puts("this port is full..");
			}
			break;
		case 2:
			if(port_position[1]==0){
				rewind(p2);
				fputc('1',p2);
				control=1;
				fseek(p2,1,SEEK_END);               
			    fprintf(p2," ****  \n                           *    *\n                          *      *\n                         *        *\n              ************        **************\n              *           OOO  OOO             *\n              *           OOO  OOO             *\n              ************OOO  OOO**************\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *        *\n                          *      *\n                           ******");
			    puts("what is the number of plane you want add to this port?");
			    fseek(p2,3,SEEK_CUR);
			    scanf("%s",&ports[1].plane.name);
			    fputs(ports[1].plane.name,p2);
			    fseek(p2,5,SEEK_END);
			    fputs("company:",p2);
				fputs(ports[0].company,p2);
			}
			else{
				puts("this port is full..");
			}
			break;
		case 3:
			if(port_position[2]==0){
				rewind(p3);
				fputc('1',p3);
				control=1;
				fseek(p3,1,SEEK_END);               
			    fprintf(p3," ****  \n                           *    *\n                          *      *\n                         *        *\n              ************        **************\n              *           OOO  OOO             *\n              *           OOO  OOO             *\n              ************OOO  OOO**************\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *OOO  OOO*\n                         *        *\n                          *      *\n                           ******");
			    puts("what is the number of plane you want add to this port?");
			    fseek(p3,3,SEEK_CUR);
			    scanf("%s",&ports[2].plane.name);
			    fputs(ports[2].plane.name,p3);
			    fseek(p3,5,SEEK_END);
			    fputs("company:",p3);
				fputs(ports[0].company,p3);
			}
			else{
				puts("this port is full..");
			}
			break;
		default:
			puts("wrong keystroke!");
			break;
	}
	if(control==1){
		puts("receiving information..");
	    sleep(1);
	    puts("Congratulations! We'll very happy with you.");
	    sleep(1);
		system("cls");
	}
	}
	else{
		puts("all ports are full, sorry about that..");
		sleep(2);
		system("cls");
	}
	fclose(p1);
	fclose(p2);
	fclose(p3);
	
}

void login_company(port_information *ports){
	
	char want[15];
	int control=0;
	puts("please enter your company name:");
	gets(want);
	
	
	//20.02.2022/PORT_1  
	//20.02.2022/PORT_2
	//20.02.2022/PORT_3
	
	//21.02.2022/PORT_1
	//21.02.2022/PORT_2.txt
	//21.02.2022/PORT_3.txt
	
	
	
	FILE *d=fopen("dates.txt","r");
	char d_name[10];
	char c_name[15];
	
	if(d!=NULL){
		
		while(!feof(d)){
			
			fgets(d_name,12,d);
			
			char temp[20];
			strcpy(temp,d_name); //11.02.2022
			strcat(temp,"/PORT_1.txt");
			FILE *p1=fopen(temp,"r");
			strcpy(temp,d_name);
			strcat(temp,"/PORT_2.txt");
			FILE *p2=fopen(temp,"r");
			strcpy(temp,d_name);
			strcat(temp,"/PORT_3.txt");
			FILE *p3=fopen(temp,"r");
			if(fgetc(p1)=='1'){
			rewind(p1);
			rewind(p2);
			rewind(p3);
			
			fseek(p1,812,SEEK_SET);
			fseek(p2,812,SEEK_SET);
			fseek(p3,812,SEEK_SET);
			
			fscanf(p1,"%s",&c_name);
			fscanf(p1,"%s",&c_name);
			puts(c_name);
			
			if(strcmp(want,c_name)==0){
				control++;
			}
			
			fscanf(p2,"%s",&c_name);
			fscanf(p2,"%s",&c_name);
			puts(c_name);
			
			if(strcmp(want,c_name)==0){
				control++;
			}
			
			fscanf(p3,"%s",&c_name);
			fscanf(p3,"%s",&c_name);
			puts(c_name);
			
			if(strcmp(want,c_name)==0){
				control++;
			}
			
			fclose(p1);
			fclose(p2);
			fclose(p3);	
			}
		}
		
		
	}
	if(control!=0){
		printf("welcome sir, you have a %d plane in this airport\n",control);
	}
	else{
		puts("back off nigga!");
	}
	
	if(!fclose(d)==0){
		puts("have a nice day..");
	}
	
	
	
	
}

void passengers_regulation(char dates[]){
	
	char date_temp[28];
	char seat2[2],seat[2];
	char date2[10],date[10];
	char plane2[8],plane[8];
	int want2,want,i=0;
	char name[10],name2[10];
	char surname[10],surname2[10];
	
	strcpy(date_temp,dates);
	strcat(date_temp,"/passengers.txt");
	FILE *p1=fopen(date_temp,"r+");
	strcpy(date_temp,dates);
	strcat(date_temp,"/regulationed.txt");
	FILE *p2=fopen(date_temp,"w");
	strcpy(date_temp,dates);
	strcat(date_temp,"/temp.txt");
	FILE *p3=fopen(date_temp,"w+");
	
	
	
	if(p1!=NULL && p2!=NULL && p3!=NULL){
		puts("edit process opened.");
		
		while(!feof(p1)){
			fscanf(p1,"%s%s%s%d%s%s",&name,&surname,&seat,&want,&date,&plane);
			i++;
		}
		i-=1;
		int ch;
		rewind(p1);
		do{
			ch=fgetc(p1);
			fputc(ch,p3);
		}
		while(!feof(p1));
	fseek(p3,-1,SEEK_CUR);//55
	fputc(' ',p3);
		
		
		for(i;i>0;i--){
			rewind(p1);
		    fscanf(p1,"%s%s%s%d%s%s",&name,&surname,&seat,&want,&date,&plane);//most small
		
		while(!feof(p1)){
			fscanf(p1,"%s%s%s%d%s%s",&name2,&surname2,&seat2,&want2,&date2,&plane2);
			
			if(name[0]>name2[0]){
				strcpy(name,name2);
				strcpy(surname,surname2);
				strcpy(seat,seat2);
				want=want2;
				strcpy(date,date2);
				strcpy(plane,plane2);
			}
		}
		
		fprintf(p2,"%s\t%s\t%s\t%d\t%s\t%s\n",name,surname,seat,want,date,plane);
		
		rewind(p1);
		
		while(!feof(p1)){
			fscanf(p1,"%s%s",&name2,&surname2);
			if(strcmp(name,name2)==0 && strcmp(surname,surname2)==0){
				fseek(p1,-(strlen(name2)+strlen(surname2)+1),SEEK_CUR);
				fputc('|',p1);
				break;
			}
		}
		}
		
	}
	
	rewind(p1);
	rewind(p3);
		char buffer[61];
		
		while(!feof(p3)){
			fgets(buffer,60,p3);
			fputs(buffer,p1);
		}
		
	if(!fclose(p1) && !fclose(p2) && !fclose(p3)){
		puts("edit process closed.");
	}

}

void passengers_info(char seat[],char name[],int want,char date[],char *plane){
	//18.02.2022/passengers.txt
	
	char date_temp[28];
	strcpy(date_temp,date);
	strcat(date_temp,"/passengers.txt");
	puts(date_temp);
	FILE *h=fopen(date_temp,"a");//--------------------
	FILE *t=fopen("Passengers_info.txt","r+");
	
	if(h!=NULL && t!=NULL){
	fseek(t,0,SEEK_END);
	fprintf(t,"%s\t%s\t%d\t%s\t%s\n",name,seat,want,date,plane);
	fprintf(h,"\n%s\t%s\t%d\t%s\t%s\n",name,seat,want,date,plane);
	fclose(t);
	fclose(h);
	passengers_regulation(date);
	puts("ticket registered!");
	sleep(3);
	system("cls");
	}
}

void check_in(){
	char us_name[10],us_surname[10];
	char take1[10],take2[10],temp[2],date[15],plane[8];
	int control=0,number;
	puts("please enter your name and surname:");
	scanf("%s%s",&us_name,&us_surname);
	puts("server waiting..");
	sleep(2);
	
	FILE *t=fopen("Passengers_info.txt","r");
	if(t!=NULL){
	
	while(!feof(t)){
		fscanf(t,"%s%s%s%d%s%s",&take1,&take2,&temp,&number,&date,&plane);                                       
		
		if(!strcmp(us_name,take1) && !strcmp(us_surname,take2)){
			control=1;
			break;
		}
	}
	
	if(control==1){
		puts("passengers founded..\nloading informations..");
		sleep(1);
		FILE *p1=fopen("passengers_ticket.txt","w");
		fprintf(p1,"------------------------------\nname:\t%s\nsurname:%s\nseat:\t%s\nport:\t%d\ndate:\t%s\nplane:\t%s\n------------------------------\n",take1,take2,temp,number,date,plane);
		fclose(p1);
	}
	
	else{
		puts("passengers is not found!");
	}
	fclose(t);
	sleep(1);
	system("cls");
}
}

void buy_ticket(port_information *ports){
	
	int port_position[3];
	int control=0,i,want;
	char seat[2];
	int number;
	char date[20],temp[20],temp2[20],addport[]="/PORT_";
	puts("What date would you like to buy your ticket for?");
	gets(date);
	strcpy(temp2,date);
	strcat(date,addport); //11.22.2022/PORT_
	strcpy(temp,date);
	strcat(date,"1.txt");
	FILE *p1=fopen(date,"r+");
	strcpy(date,temp);
	strcat(date,"2.txt");
	FILE *p2=fopen(date,"r+");
	strcpy(date,temp);
	strcat(date,"3.txt");
	FILE *p3=fopen(date,"r+");
		if(p1!=NULL && p2!=NULL && p3!=NULL){
			puts("being checked..");
			sleep(1);
			//puts("files opened.");
		rewind(p1);
		rewind(p2);
		rewind(p3);
		
		if(fgetc(p1)=='1'){
			port_position[0]=1;
		}
		else{
			port_position[0]=0;
		}
		if(fgetc(p2)=='1'){
			port_position[1]=1;
		}
		else{
			port_position[1]=0;
		}
		if(fgetc(p3)=='1'){
			port_position[2]=1;
		}
		else{
			port_position[2]=0;
		}
		printf("port with airplane:");
		for(i=0;i<3;i++){
			if(port_position[i]==1){
				printf("%d ",i+1);
				control=1;
			}
		}
		if(control==0){
			printf(" none");
			return;
		}
		else{
			char name[18];
			char plane[10];
			puts("\nwhich one do you want?");
			scanf("%d",&want);//2 olsun
			if(want==1){
				fseek(p1,812,SEEK_SET);
				fscanf(p1,"%s",&plane);
			}
			else if(want==2){
				fseek(p2,812,SEEK_SET);
				fscanf(p2,"%s",&plane);
			}
			else if(want==3){
				fseek(p3,812,SEEK_SET);
				fscanf(p3,"%s",&plane);
			}
			puts("Which seat would you like?");
			fflush(stdin);
			gets(seat);
			puts("what's your name and surname?");
			gets(name);
			puts("please wait..");
			sleep(1);			
			passengers_info(seat,name,want,temp2,plane); //kayýt
			number=seat[0]-'0';
			int karakter;
			rewind(p1);
			rewind(p2);
			rewind(p3);
			if(want==1){
				control=(number-1)*6;
				while(1){
					if(control>0){
						karakter=fgetc(p1);
					if(karakter=='O' || karakter=='X'){
						control--;
						
					}
				    }
					if(control==0){
						break;
					}
				}
				while(1){
					karakter=fgetc(p1);
					if(karakter=='O' || karakter=='X'){
						break;
					}
				}
				fseek(p1,-1,SEEK_CUR);
				switch(seat[1]){
					case 'A':
						fputc('X',p1);   //000  000
						break;
					case 'B':
						fseek(p1,1,SEEK_CUR);
						fputc('X',p1);
						break;
					case 'C':
						fseek(p1,2,SEEK_CUR);
						fputc('X',p1);
						break;
					case 'D':
						fseek(p1,5,SEEK_CUR);
						fputc('X',p1);
						break;
					case 'E':
						fseek(p1,6,SEEK_CUR);
						fputc('X',p1);
						break;
					case 'F':
						fseek(p1,7,SEEK_CUR);
						fputc('X',p1);
						break;
					default:
						break;
				}
			}
			else if(want==2){
				control=(number-1)*6;
				while(1){
					if(control>0){
						karakter=fgetc(p2);
					if(karakter=='O' || karakter=='X'){
						control--;
					
					}
				    }
					if(control==0){
						break;
					}

				}
				while(1){
					karakter=fgetc(p2);
					if(karakter=='O' || karakter=='X'){
						break;
					}
				}
				fseek(p2,-1,SEEK_CUR);
				switch(seat[1]){
					case 'A':
						fputc('X',p2);   //000  000
						break;
					case 'B':
						fseek(p2,1,SEEK_CUR);
						fputc('X',p2);
						break;
					case 'C':
						fseek(p2,2,SEEK_CUR);
						fputc('X',p2);
						break;
					case 'D':
						fseek(p2,5,SEEK_CUR);
						fputc('X',p2);
						break;
					case 'E':
						fseek(p2,6,SEEK_CUR);
						fputc('X',p2);
						break;
					case 'F':
						fseek(p2,7,SEEK_CUR);
						fputc('X',p2);
						break;
					default:
						break;
				}
			}
			else if(want==3){
				control=(number-1)*6;
				while(1){
					if(control>0){
						karakter=fgetc(p3);
					if(karakter=='O' || karakter=='X'){
						control--;
						
					}
				    }
					if(control==0){
						break;
					}
				}
				while(1){
					karakter=fgetc(p3);
					if(karakter=='O' || karakter=='X'){
						break;
					}
				}
				fseek(p3,-1,SEEK_CUR);
				switch(seat[1]){
					case 'A':
						fputc('X',p3);   //000  000
						break;
					case 'B':
						fseek(p3,1,SEEK_CUR);
						fputc('X',p3);
						break;
					case 'C':
						fseek(p3,2,SEEK_CUR);
						fputc('X',p3);
						break;
					case 'D':
						fseek(p3,5,SEEK_CUR);
						fputc('X',p3);
						break;
					case 'E':
						fseek(p3,6,SEEK_CUR);
						fputc('X',p3);
						break;
					case 'F':
						fseek(p3,7,SEEK_CUR);
						fputc('X',p3);
						break;
					default:
						break;
				}
			}
			fclose(p1);
			fclose(p2);
			fclose(p3);
		}
		}	
}

int main() {
	
	
	char log[10];
	port_information *ports=(port_information *)calloc(sizeof(port_information),6);
	add_date();
	do{
    puts("                                 INTERNATIONAL CUBUKCU AIRPORT                               \nWelcome..Please enter your process..\n");
	puts("      ---------------\n      1-Company Login\n      2-Guest Login\n      3-Out\n      ---------------");
	gets(log);
	if(strcmp(log,"company")==0){ 
		
		char ch[9];
		puts("\nDo you want to register or login?");
		gets(ch);
		if(strcmp(ch,"register")==0){
			puts("Okey, please waiting..\n");
			sleep(1);
			system("cls");
			company_registration(ports);
			
		}
		else if(strcmp(ch,"login")==0){
			puts("welcome login");
			login_company(ports);
		}
		else{
			puts("wrong keystroke.!");
			sleep(1);
			system("cls");
		}
	
	}
	
	

	else if(strcmp(log,"guest")==0){
	
		puts("welcome sir, check ticket or buy ticket(buy/check)?");
		gets(log);
		if(strcmp(log,"buy")==0){
			buy_ticket(ports);
		}
		else if(strcmp(log,"check")==0){
			check_in();
		}
		else{
			puts("wrong keystroke!");
			sleep(1);
			system("cls");
		}
	}
	
	else{
		puts("wrong keystroke..!");
		sleep(1);
		system("cls");
	}

	}while(strcmp(log,"out")!=0);
	
	
	return 0;
}
