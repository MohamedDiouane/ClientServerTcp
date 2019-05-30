
#include<stdio.h>
#include<winsock2.h>
#include<stdlib.h>
#include<string.h>

#pragma comment(lib,"ws2_32.lib") 

#define SERVER "127.0.0.1"	
#define BUFLEN 512	
#define PORT 1235


	struct sockaddr_in si_other;
	int s, slen=sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa ;
    int choix ;
    int nb[BUFLEN];
    char minmaj[BUFLEN];
    
void Initialisecreatesetup(){
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		system("pause");
		exit(EXIT_FAILURE);
	}
	
		if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d" , WSAGetLastError());
				system("pause");
		exit(EXIT_FAILURE);
	}
	
	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
}

void sendsocket(char message[0]){
     if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
					system("pause");
			exit(EXIT_FAILURE);
		}
     }

    void reveive(){
               if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code : %d" , WSAGetLastError());
			
			exit(EXIT_FAILURE);
		}
		}


	void menu(){
	system("cls");

printf("\n\t  ********************* Options ***********************\n"); 
printf(" -------------------> 1 Recuperer la date et l'heure du serveur\n");  
printf(" -------------------> 2 Convertire une chaine de caractere en majuscule \n");
printf(" -------------------> 3 Effectuer la somme de plusieurs nombres \n");
printf("--------------------> 4 Effectuer la difference de plusieurs nombres  \n");
printf("--------------------> 5 Effectuer la division de deux nombres  \n");
printf("--------------------> 7 Quitter  \n");
  
  
  

	
   
	}

void conc(char* su, char* x,char* y)
{
        strcat(su,x);
        strcat(su,"+");
        strcat(su,y);
}

    int main(void)
{
        
	for(;;)
	{  
            Initialisecreatesetup();
            menu(); 
            printf("\n Veuillez entrer votre choix:");
            scanf("%d",&choix);
 switch(choix){
 	
 		case 7:
 			
 			  printf("veuillez saisir votre 1er nombre:");
             char xx[BUFLEN];
              char yy[BUFLEN];
             scanf(" %s",&xx); getchar();
             printf("veuillez saisir votre 2eme nombre:(diff de zero)  :");
             scanf(" %s",&yy);            
             getchar();
             char mes111[BUFLEN]="7";
             conc(mes111,xx,yy);
             if (sendto(s, mes111, strlen(mes111) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
               memset(buf,'\0', BUFLEN);
               free(mes111);
               reveive();
               puts("\n la div de deux nombre est: ");
		       puts(buf);
		       system("pause");
	           break; 
 			
		case 2:
			
			  printf("\n Veuillez entrer votre chaine:");
			 // fgets(minmaj, sizeof minmaj, stdin);
			  scanf(" %s",&minmaj);
			  char mes6[BUFLEN]="2";
		   	  strcat(mes6,minmaj);
		   	  
			  if (sendto(s, mes6, strlen(mes6) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
               reveive();
               puts("\n le resultat  ");
		       puts(buf);
		       system("pause");
		       break;
		                   
	    case 1:  
	           sendsocket("##1");
		      
               reveive();
               
	           puts("la date du serveur est:");
	           puts(buf);
	            memset(buf,'\0', BUFLEN);
		       system("pause");
	           break;
                         
           case 4:

             printf("veuillez saisir votre premier nombre:");
             char x1[BUFLEN];
             scanf(" %s",&x1); getchar();
             printf("veuillez saisir  votre second nombre:");
              char y1[BUFLEN];
             scanf(" %s",&y1);            
             getchar();
             char mes2[BUFLEN]="4";
             conc(mes2,x1,y1);
             if (sendto(s, mes2, strlen(mes2) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
               memset(buf,'\0', BUFLEN);
               free(mes2);
               reveive();
               puts("\n la difference des deux nombre est: ");
		       puts(buf);
		       system("pause");
	           break;             
        case 5:

             printf("veuillez saisir nombre N:");
             char yu[BUFLEN];
             scanf(" %s",&yu); getchar();
             int cpt=0 , c=0 , j=0 , k=0;
             c=atoi(yu);
             char mes3[BUFLEN]="5";
             strcat(mes3,yu);
             for (k=0;k<c;k++)
             {
            printf("veuillez saisir votre  nombre:");
            char nbr2[BUFLEN];
            scanf(" %s",&nbr2);
            strcat(mes3,nbr2);   
            strcat(mes3,"A");
             }
           getchar();
           
             if (sendto(s, mes3, strlen(mes3) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
               memset(buf,'\0', BUFLEN);
               free(mes2);
               reveive();
               puts("\n la somme de tous les nombres est: ");
		       puts(buf);
		       system("pause");
	           break;
			   
			   
		case 6:
             

             printf("veuillez saisir nombre N:");
             char yuu[BUFLEN];
             scanf(" %s",&yuu); getchar();
             int cptt=0 , cc=0 , jj=0 , kk=0;
             c=atoi(yuu);
             char mes33[BUFLEN]="6";
             strcat(mes33,yuu);    
             for (kk=0;kk<c;kk++)
             {
            printf("veuillez saisir votre  nombre:");
            char nbr22[BUFLEN];
            scanf(" %s",&nbr22);
            strcat(mes33,nbr22);   
            strcat(mes33,"A");
             }
            getchar();
           
             if (sendto(s, mes33, strlen(mes33) , 0 , (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
			exit(EXIT_FAILURE);
		}
               memset(buf,'\0', BUFLEN);
               free(mes2);
               reveive();
               puts("\n la diff de tous les nombres est: ");
		       puts(buf);
		       system("pause");
	           break;	                
             }
    }
	
        closesocket(s);
	    WSACleanup();
	    
        return 0;
}

