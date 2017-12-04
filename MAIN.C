#include<stdio.h>
#include<string.h>
#include<dir.h>
#include<conio.h>
#define L 100
#define I 100

main()
{
	int done,x,c,b,n;
	char list[L][I];
	struct ffblk a;
	char curdir[MAXPATH];
	while(1)
	{
		clrscr();
		textbackground(0);
		background();
		done = findfirst("*.*",&a,0);
		n=0; textcolor(1); textbackground(7);
		while(!done && n <= 44)
		{
		    strcpy(list[n],a.ff_name);
		    done= findnext(&a);
		    n++;
		}
		c=8; b=5;
		gotoxy(c,b);
		for(x=0;x<n;x++)
		{
			cprintf("%s",list[x]);
		    b=b+1;
		    gotoxy(c,b);
			if(b==20)
			{
		      	c=c+25; b=5;
		      	gotoxy(c,b);
	         }
		}
		n=cursor(list);
		load(list[n]);
		getch();
	}
}

int background()
{
   int x=3,y=2;
   char direct[100];
   gotoxy(x,y); textbackground(3);
   cprintf("                                                                        ");
   y=3;
   while(y<=20)
   {
     gotoxy(x,y); cprintf("  ");
     gotoxy(73,y); cprintf("  ");
     y++;
   }
   gotoxy(3,21);
   cprintf("                                                                        ");
   gotoxy(5,3); textbackground(4);
   cprintf("                                                                    ");
   textcolor(7);
   gotoxy(6,3); cprintf("DIRECTORY: %s",getcwd(direct, 100));
   y=4;
   while(y<=20)
   {
     textbackground(7);
     gotoxy(5,y);
     cprintf("                                                                    ");
     y++;
   }
   return(0);
}

int cursor(char list[L][I])
{
   int x,y, c,n2,n;
   c='\0';
   x=7;
   y=5;
   n2=0;
   gotoxy(x,y);
   textcolor(7);
   textbackground(4);
   cprintf("               "); gotoxy(x,y);
   cprintf(" %s ",list[n2]);

   while(c!=13)
   {
       c=getch();
       if (c==80){
       gotoxy(x,y);
       textcolor(1);
       textbackground(7);
       cprintf("               "); gotoxy(x,y);
       cprintf(" %s ",list[n2]);
       y=y+1;
       n2=n2+1;
       if (y==20)
       {
		  n2=n2-15;
		  y=5;
		  gotoxy(x,y);
       }
       gotoxy(x,y);
       textcolor(7);
       textbackground(4);
       cprintf("               "); gotoxy(x,y);
       cprintf(" %s " ,list[n2]);
   }
   if (c==72)
   {
      gotoxy(x,y);
      textcolor(1);
      textbackground(7);
      cprintf("               "); gotoxy(x,y);
      cprintf(" %s ",list[n2]);
      y=y-1;
      n2=n2-1;
      if(y==4)
      {
		 y=19;
		 n2=n2+15;
      }
      gotoxy(x,y);
      textcolor(7);
      textbackground(4);
      cprintf("               "); gotoxy(x,y);
      cprintf(" %s ",list[n2]);
   }
   if(c==77)
   {
      gotoxy(x,y);
      textcolor(1);
      textbackground(7);
      cprintf("               "); gotoxy(x,y);
      cprintf(" %s ",list[n2]);
      x=x+25;
      n2=n2+15;
      if(x>75)
      {
		x=7;
		n2=n2-45;
      }
      gotoxy(x,y);
      textcolor(7);
      textbackground(4);
      cprintf("               "); gotoxy(x,y);
      cprintf(" %s ",list[n2]);
   }
   if(c==75)
   {
      gotoxy(x,y);
      textcolor(1);
      textbackground(7);
      cprintf("               "); gotoxy(x,y);
      cprintf(" %s ",list[n2]);
      x=x-25;
      n2=n2-15;
      if(x<7)
      {
		x=57;
		n2=n2+45;
      }
	  gotoxy(x,y);
	  textcolor(7);
	  textbackground(4);
   	  cprintf("               "); gotoxy(x,y);
	  cprintf(" %s ",list[n2]);
   }
   if(c==27)
   {
      exit(0);
   }
 }
 return n2;
}

int load(char *p)
{
   char path[100];
   textbackground(0);
   clrscr();
   printf("%s\\%s\n",getcwd(path,100),p);
   system(p);
   textbackground(0);
}