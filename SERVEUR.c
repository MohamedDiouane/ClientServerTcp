#include<stdio.h>
#include<winsock2.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

#pragma comment(lib,"ws2_32.lib") 
#define BUFLEN 512	
#define PORT 1235	

    SOCKET s;
	struct sockaddr_in server, si_other;
	int slen , recv_len;
	char buf[BUFLEN];
	char buf2[BUFLEN];
	char buf4[BUFLEN];
    char buffee[BUFLEN];
	int som=0;
	WSADATA wsa;
	int j=0;
		   int i=0;
		   float x=0;
		   float somme=0;
		   int k=0;
		   int l=0;

		slen = sizeof(si_other); 
	
	void initialisesocket(){
	
	
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		 system("pause");
		exit(EXIT_FAILURE);
	}
	
    } 

    void creesocket(){
	
	if((s = socket(AF_INET , SOCK_DGRAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
		 system("pause");
	}
	
    } 
    void configuresocket(){
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( PORT );
    }
    
    void ecoutesocket(){
	
	if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d" , WSAGetLastError());
		 system("pause");
		exit(EXIT_FAILURE);
	}
	
    }
    
    void recoiesocket(){
		
		printf("en attente des clients:...\n");
		fflush(stdout);
		memset(buf,'\0', BUFLEN);
		if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code : %d" , WSAGetLastError());
		
         system("pause");
			exit(EXIT_FAILURE);
		}
	
	     }
    
    void envoiesocket(char buf[]){
		
		if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d" , WSAGetLastError());
			 system("pause");
			exit(EXIT_FAILURE);
		}
		
	}
    
    void fermesocket(){
    	
    	closesocket(s);
	    WSACleanup();
    	
    }
int main()
{
     float som=0;
	for(;;)
	{
           initialisesocket();
	creesocket();
	configuresocket();
	ecoutesocket();
	recoiesocket();
	
	
	if (strncmp(buf,"##1",1)==0 )
		{
		 printf("client %s: connecte requete demandee: date du serveur.\n", inet_ntoa(si_other.sin_addr));	
         SYSTEMTIME t;
         GetSystemTime(&t);
         sprintf(buf2,"%d-%d-%d--",t.wDay,t.wMonth,t.wYear);
		 printf("client %s: connecte requete demandee: heure du serveur.\n", inet_ntoa(si_other.sin_addr));	
         GetSystemTime(&t);
         sprintf(buf4,"%d:%d:%d",t.wHour,t.wMinute,t.wSecond);
         strcat(buf2,buf4);
	     sendto(s, buf2, BUFLEN, 0, (struct sockaddr*) &si_other, slen);
	    }
	else if (strncmp(buf,"2",1)==0)

    	{
	    printf("client %s: connecte requete demandee: conv MIN TO MAJ \n", inet_ntoa(si_other.sin_addr));
	    buf[0]='>';
	    int len = strlen(buf);
        buf[len+1] = '\0';
		int i = 0;
   	    int counter=0;
	    char mychar;
/*
	while (buf[counter])
	{
		mychar=buf[counter];
		putchar (toupper(mychar));
		counter++;
	}*/
		
	/*	
		for (i=0; i<strlen(buf); i++) {
     buf[i]=toupper(buf[i]);
}*/

		
while(buf[i]!='\0')
{
	
buf[i] = toupper (buf[i]);
 i++;
}
	     sendto(s, buf, BUFLEN, 0, (struct sockaddr*) &si_other, slen);
	    memset(buf,'\0', BUFLEN);
	 
	 
	   
	}
	 else if (strncmp(buf,"3",1)==0)
	{
		
		printf("client %s: connecte requete demandee: somme de deux nombres.\n", inet_ntoa(si_other.sin_addr));
		buf[0]='0';
	    int i=0;
	     while(buf[i]!='+')
	    {
            i++;
        }
	    char buffe[240];
	    strncpy(buffe,buf,i);
	    char buff[240];
	    int j;
	    for( j=0;j<=i;j++)
	    {
                buf[j]='0';
                }
       strcpy(buff,buf);
	   float x=atof(buffe);
       float y=atof(buff);
       float z=0;
       z=x+y;
       sprintf(buf2,"%1f",z);
	    sendto(s, buf2, BUFLEN, 0, (struct sockaddr*) &si_other, slen);
	    memset(buf,'\0', BUFLEN);
	   
	}
	
	    
	 else if (strncmp(buf,"4",1)==0)
	{
		
		printf("client %s: connecte requete demandee: difference de deux nombres.\n", inet_ntoa(si_other.sin_addr));
		buf[0]='0';
	    int i=0;
	     while(buf[i]!='+')
	    {
            i++;
        }
	    char buffe[BUFLEN];
	    strncpy(buffe,buf,i);
	    char buff[BUFLEN];
	    int j;
	    for( j=0;j<=i;j++)
	    {
                buf[j]='0';
                }
       strcpy(buff,buf);
	    float x=atof(buffe);
        float y=atof(buff);
        float z=0;
        z=x-y;
        sprintf(buf2,"%1f",z);
	    sendto(s, buf2, BUFLEN, 0, (struct sockaddr*) &si_other, slen);
	    memset(buf,'\0', BUFLEN);
	   
	}
	
	 else if (strncmp(buf,"5",1)==0)
  {
	    

	    char cpt[BUFLEN];      
        printf("client %s: connecte requete demandee: somme N.\n", inet_ntoa(si_other.sin_addr));
	    buf[0]='0';
	    strncpy(cpt,buf,2);
        int c=0;
        c=atoi(cpt);
        buf[1]='0';
        	
           for(l=0;l<c;l++)                
        {
           while(buf[i]!='A')
        	    {
                    i++;
                }
	    
	    char buffe[BUFLEN];
	    strncpy(buffe,buf,i);	    
	    for( k=0;k<=i;k++)
	    {
                buf[k]='0';
        }	    
	     x=atof(buffe);
	     
         somme=somme+x;
          
         memset (buffe,'\0', sizeof (buffe));
         }   
                            
        sprintf(buf2,"%1f",somme);
        
	    sendto(s, buf2, BUFLEN, 0, (struct sockaddr*) &si_other, slen);
	    memset(buf,'\0', BUFLEN);
		                       
	}
	
	
	 else if (strncmp(buf,"7",1)==0)
	{
		
		printf("client %s: connecte requete demandee: somme de deux nombres.\n", inet_ntoa(si_other.sin_addr));
		buf[0]='0';
	    int i=0;
	     while(buf[i]!='+')
	    {
            i++;
        }
	    char buffe[240];
	    strncpy(buffe,buf,i);
	    
	    char buff[240];
	    int j;
	    for( j=0;j<=i;j++)
	    {
                buf[j]='0';
                }
       strcpy(buff,buf);
	    float x=atof(buffe);
    float y=atof(buff);
    float z=0;
    z=x/y;
    sprintf(buf2,"%1f",z);
	    sendto(s, buf2, BUFLEN, 0, (struct sockaddr*) &si_other, slen);
	    memset(buf,'\0', BUFLEN);
	   
	}
	
	
	else if (strncmp(buf,"6",1)==0)
  {
	    

	    char cpt[BUFLEN];      
        printf("client %s: connecte requete demandee: diff N.\n", inet_ntoa(si_other.sin_addr));
	    buf[0]='0';
	    strncpy(cpt,buf,2);
        int c=0;
        c=atoi(cpt);
        buf[1]='0';
        	
           for(l=0;l<c;l++)                
        {
           while(buf[i]!='A')
        	    {
                    i++;
                }
	    char buffe[BUFLEN];
	    strncpy(buffe,buf,i);	    
	    for( k=0;k<=i;k++)
	    {
                buf[k]='0';
        }	    
	     x=atof(buffe);
	     
         somme=somme-x;
          
         memset (buffe,'\0', sizeof (buffe));
         }   
                            
        sprintf(buf2,"%1f",somme);
        
	    sendto(s, buf2, BUFLEN, 0, (struct sockaddr*) &si_other, slen);
	    memset(buf,'\0', BUFLEN);
		                       
	}
    
                                
                                
      
    
    
    fermesocket();
}

	
              
	return 0;
}


