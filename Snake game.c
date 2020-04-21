#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
#define ULINE (loop>=0 && loop<=14)
#define DLINE (loop>=90 && loop<=105)

int randomise(int size,int b[])   // STACK MEMORY USING BUT ULTIMate solution of rando
{                     //ize problem
     unsigned short int temp,food=0;
     randomize();
   ran: food=rand()%89; // It can 0 to 88 number anything
   if(food<15)
   food=food+15;
   for(temp=0; temp<size; temp++)
	       if(food==b[52-temp])
		goto ran;

   switch(food)
	{
	case 44: case 59:case 74: case 89: case 29:case 15:case 30:case 45:
	case 60: case 75: case 90:case 91: case 92: case 93: case 94: case 95:
	case 96: case 97: case 98: case 99: case 100: case 101: case 102: case 103:
	case 104: case 105:    // cases of '|' and line
	       goto ran;
	}
   return food;
}

void main()
{
	     char *a=NULL,move2='6';
	     int loop=0,food=0,fun=4,time=0;
	     int *b=NULL,size=1,temp=0,storemove=0; // size of snake and temp to determine the eats
	     register char move; // to determine what user typed
	     struct time t;
	     b=(int*)malloc(106*sizeof(int));
	     a=(char*)malloc(106*sizeof(char));
	     gettime(&t);
	     if(a==NULL|| b==NULL)
	    {
	     cprintf("SORRY GAME CAN'T BE PLAYED DUE TO LESS SPACE");
	     exit(1);
	    }

	      b[52]=52;          //HEAD
	       a=NULL;
	       clrscr();

	      for(time=0; 1; time++)
 {            clrscr();
	     // flushall();
	      textcolor(GREEN );
	     printf("To [Exit] Press \"ESC\" Anytime Of The Game\t\t Time:%02d:%02d\n",\
	      (t.ti_hour>12?t.ti_hour-12:t.ti_hour), t.ti_min);
	   cprintf("By ZEALOT #003 ");
	   printf("(SIMPLE SNAKE GAME).\n\n"); // CHANGE IT IF CHANGING THE LOCATION OF 1st LINE
	      gettime(&t);
	      if(size<50 && temp==0)
	 {  printf("To Unlock Stop Size Stage = (%d) Eats\n\n\t\t",50-size); }
	 else if(temp>0)
		{ cong:printf("Congrats you cracked the ultimate level.\n\t\t");
		 size=50;
		}
	 else if(size==50)
	 { temp++;
	  goto cong;
	 }

	       for(loop=0; loop<105; loop++) {
		while(food==0)
	       food=randomise(size,b);

	      switch(loop)
	{
	case 44: case 59:case 74: case 89: case 29:case 15:case 30:case 45:
	case 60: case 75: case 90:    // cases of '|' and line
	       fun=1;
	       break;
	default:
	fun=0;
	break;
	}
	       if(ULINE)
		 a[loop]=',';
	       else if(DLINE)
		a[loop]='`';
	      else if(fun==1 )
	       a[loop]= '|';
	      else if(loop!=food)
		a[loop]=' '; 	    // so the space will be empty
	      else
	      a[loop]='.';      // it mean that d==loop and it will print . (FOOD)


	      if(loop%15==0 && loop!=0)
	      printf("\n\t\t");         // it will print a new line after every

	       if(time>=0)
		  for(fun=0;fun<=size; fun++)
		 {     if(fun==0);
		       else if(fun==size)
		       a[b[52]]= 1;
		       else
		       a[b[52-fun]]='=';
		}


	       textcolor(19);
	       highvideo();         // sets the pixels to HIGH RESOLUTION
	      cprintf("%c",a[loop]);


    }//closing of inner for-loop
	      printf("\n\n\nDirect Your Snake\n\n\
Controls = W,A,S,D\n\tOr\nControls = 2,4,6,8\n");

	      // it will increment to next moves
	      gettime(&t);         //GETTING THE CURRENT TIME
	      storemove=t.ti_sec;   //GETTING THE CURRENT MILISECONDS

	      while(!kbhit()) {           //WHILE USER DOESN"T TYPE.
		gettime(&t);              //COMPARING STORED TIME WITH CURR.
	       if(storemove+1<t.ti_sec ) {
		move=move2;
		goto swi;
	       } //IF CLOSING
	   } //WHILE KBHIT CLOSING

		 move=getch();
		 flushall();
		again :
		swi:   switch(move){
		   case '8':
		   case 'w':
		   case 'W':
		   if(b[52]-15==b[51])
		   goto def;               //default
		   for(fun=52-size; fun<52; fun++)     // fun=0; fun<4
		    b[fun]=b[fun+1];
		   b[52]=b[52]-15;
		   move2=move;
		 break;
					     //b1=48
		 case '6':
		 case 'd':
		 case 'D':
		 if(b[52]+1==b[51])
		 goto def;
		 for(fun=52-size; fun<52; fun++)     // fun=0; fun<4
		    b[fun]=b[fun+1];
		 b[52]=b[52]+1;
		 move2=move;
		 break;

		 case '4':
		 case 'a':
		 case 'A':
		 if(b[52]-1==b[51])
		 goto def;
		 for(fun=52-size; fun<52; fun++)     // fun=0; fun<4
		  {  b[fun]=b[fun+1];    }
		 b[52]=b[52]-1;
		 move2=move;
		 break;

		 case '2':
		 case 's':
		 case 'S':
		 if(b[52]+15==b[51])
		 goto def;
		 for(fun=52-size; fun<52; fun++)     // fun=0; fun<4
		  {  b[fun]=b[fun+1];    }
		 b[52]=b[52]+15;
		 move2=move;
		 break;

		 case 27:     //exiting case
		 move='\0';
		 cprintf("Exiting . . .");
		 a=NULL;
		 sleep(1);
		 textcolor(8+BLINK);
		 printf("\tFreeing Consumed memory %s.",a);
		 sound(1500);
		 free(a);
		 free(b);
		 sleep(1);
		 nosound();
		 exit(1);
		 move2=move;
		 break;

		 default:
		 def:
		 move=move2;
		 goto again;
	}// switch case closing

		    if(time>=0)

	{     if(a[b[52]]=='`' || a[b[52]]=='|' ||a[b[52]]==','|| a[b[52]]=='=')
	      { textcolor(BLACK + BLINK);
	       highvideo();
	       cprintf("\nSorry! You Loss The Game\t Try Again Your Luck\t");
	       for(fun=100; fun<3500; fun++)
	       {
		 sound(fun);
		 delay(1);
		 }
	       sleep(2);
	       nosound();
	       exit(1);
	      }

		else if(a[b[52]]=='.')
	     {  food=0;
		size++;
		sound(3500);
		delay(50);
		nosound();
	     }

	}

   }
}
