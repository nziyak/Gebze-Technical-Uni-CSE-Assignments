#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

#define MAX 20


int main(){

    char portArdunio = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );
    char selection;

    printf("^_^    WELCOME TO GTU ARDUINO LAB ^_^  \n");      
    printf("^_^    STUDENT NAME: NURI ZIYA KIRTEPE ^_^ \n");
    printf("^_^    PLEASE SELECT FROM THE FOLLOWING ^_^\n");
    
    do{

        printf("\n   MENU :  \n");
	    printf("[1] TURN ON LED ON ARDUINO\n");
	    printf("[2] TURN OFF LED ON ARDUINO\n");
	    printf("[3] FLASH ARDUINO LED 2 TIMES\n");
	    printf("[4] SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n");
	    printf("[0] EXIT\n");
	    

        printf("SELECT MENU(0-4):");
        scanf("%c",&selection);
        switch (selection)
        {
            case '1':
                
                portArdunio = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );
                write(portArdunio,"1", 2);	
                printf("      LED TURNED ON      \n");
	            
                close(portArdunio);
                break;
            
            case '2':
                portArdunio = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );

                write(portArdunio,"2",2);														

	            
	            printf("       LED TURNED OFF      \n");
	           
                close(portArdunio);
                break;
            
            case '3':
                
                portArdunio = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );
                
                write(portArdunio,"3",2);														

	            
	            printf("  LED FLASHED 2 TIMES ON ARDUNIO  \n");
	            
                close(portArdunio);
                break;

            case '4':
            
                portArdunio = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY ); 
                sleep(1);

                write(portArdunio,"4",2);														

                char num[10];      						    //takes number from user
                        
                int lenght;		//the length of the number which received from user
                char receive_data[MAX];  //the place that result of the calculation of arduino will be saved
                char read_byte;		//the place that all the bytes read stored
                int result;		//Sonucun atanacagi degisken 

                printf("----------------------------\n");		
                printf("Enter the number :  ");
                scanf("%s",num);							//number that user wants to calculate		

                lenght=strlen(num);							//length is known by strlen

               
                portArdunio = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );
                write(portArdunio,num,lenght);

                printf(".....Calculating.....\n");	
                        
                sleep(1);							//time for arduino to calculate 
                                        
                read_byte = read(portArdunio,receive_data,9);		//reads datas from arduino	
                        
                result = atoi(receive_data);						//String to integer
                printf("________________________\n");    
                printf("=  Square of %s^2 : %d  =\n",num,result);	//prints the result to screen
                printf("________________________\n");		

                close(portArdunio);
                
                break;
            
           
            
            case '0':
	            printf(" How sad! You have killed me! Goodbye World!   \n");
	            
                break;
            
            default:
                break;
        }
        
    }while(selection !='0');

    return 0;
}



 

