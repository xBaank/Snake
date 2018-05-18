#include <stdio.h>
#include <windows.h>
#define arriba 72
#define abajo 80 
#define izquierda 75
#define derecha 77
typedef struct {
		char m[20][40];
        int x,i;
        int a,b,p,n;
        int w,aa,s,d;
        int j[100];
        int y[100];
        int c,c2;
        int c3[100];
} campoc;
campoc c;
void teclas ();
void campo ();
void serpiente ();
void arribaz ();
void abajoz ();
void derechaz ();
void izquierdaz ();
void manzana ();

int main() {
	c.p = 1;
	c.n = 3; 
	c.c = 99;
	c.j[0] = 10;
	c.y[0] = 20; 
	c.j[1] = 10;
	c.y[1] = 19; 
	c.j[2] = 10;
	c.y[2] = 18; 
	c.c3[1] = 1;
	c.c3[2] = 1;
	
	for (c.c2 = 3; c.c2 < 100 ; c.c2++) {
		c.c3[c.c2] = 0;
	}
	
	campo () ;
	
}
void campo () {
	system("cls");
	    for (c.x = 0; c.x < 20; c.x++) {
    	for (c.i = 0; c.i < 40; c.i++) {
    		c.m[c.x][c.i] = ' ';
    	}
    }
    manzana();
    serpiente();
    for (c.x = 0; c.x < 20; c.x++) {
    	for (c.i = 0; c.i < 40; c.i++) {
    		if (c.i == 0 || c.i == 39) {
    			c.m[c.x][c.i] = '|' ;
    			printf("%c",c.m[c.x][c.i]);
    		}
    		else {
    		if (c.x == 0 || c.x == 19) {
    			c.m[c.x][c.i] = '-';
    			printf("%c",c.m[c.x][c.i]);
    			
    		}
    		else {
    			
    			printf("%c",c.m[c.x][c.i]);
    		}
    	}
    	}
    	printf("\n");
    }
    teclas ();
}
void teclas () {
	int tecla,n;
    while (!kbhit()) {
    	Sleep(70);
    	if (c.d == 1) {
    		derechaz();
    		campo();
    	}
    	if (c.aa == 1) {
    		izquierdaz();
    		campo();
    	}
    	if (c.w == 1) {
    		arribaz();
    		campo();
    	}
    	if (c.s == 1) {
    		abajoz();
    		campo();
    	}
    	
    	
    }
    if (tecla != 27) {
    for (n = 0; n < 2; n ++) {
 	tecla = getch();
 	switch (tecla) {
 	case arriba: 
 	if (c.s == 1) {
 		abajoz();
 		break;
 	}
	 arribaz ();
	 c.w = 1;
	 c.s = 0;
	 c.aa = 0;
	 c.d = 0;
	 break;
 	case abajo: 
 	if (c.w == 1) {
 		arribaz();
 		break;
 	}
	 abajoz();
	   c.w = 0;
	 c.s = 1;
	 c.aa = 0;
	 c.d = 0;
	 break;
 	case izquierda: 
 	if (c.d == 1) {
 		derechaz();
 		break;
 	}
	 izquierdaz();
	 c.w = 0;
	 c.s = 0;
	 c.aa = 1;
	 c.d = 0;
	 break;
 	case derecha:
 	if (c.aa == 1) {
 	    izquierdaz();
 	    break;
 	}
	 derechaz();
	 c.w = 0;
	 c.s = 0;
	 c.aa = 0;
	 c.d = 1;
	 break;
    }
    campo();
 }
 	
 }
}
void serpiente () {	
     c.m[c.j[0]][c.y[0]] = 'x'; 
	 c.m[c.j[1]][c.y[1]] = 'o';
	 c.m[c.j[2]][c.y[2]] = 'o';
	 c.p = 0;
	 if (c.j[0] == c.a && c.y[0] == c.b) {
	 	c.m[c.j[c.n]][c.y[c.n]] = 'o';
	 	c.c3[c.n] = 1;
	 	c.p = 1;
	 	c.n = c.n + 1;
	 	
	 }
	 for (c.c2 = 3; c.c2 < 100 ; c.c2++) {
	 	if (c.c3[c.c2] == 1) {
	 		c.m[c.j[c.c2]][c.y[c.c2]] = 'o';
	 	}
	 }
	 for (c.c2 = 1; c.c2 <100 ; c.c2++) {
	 if (c.m[c.j[0]][c.y[0]] == c.m[c.j[c.c2]][c.y[c.c2]] && (c.c3[c.c2] == 1) ) {
	 	printf("Perdiste\n");
	 	system("pause");
	 	main();
	 }
}
	 if (c.j[0] == 0 || c.j[0] == 19 || c.y[0] == 0 || c.y[0] == 39 ) {
	    printf("Perdiste\n");
	 	system("pause");
	 	main();
	 }
}
void arribaz () {
 for (c.c = 99; c.c > 0; c.c-- ) {
 		c.j[c.c] = c.j[c.c - 1];
 		c.y[c.c] = c.y[c.c - 1];
 		
 }
  c.j[0] = c.j[0] - 1;
}
void abajoz () {
 for (c.c = 99; c.c > 0; c.c-- ) {
 		c.j[c.c] = c.j[c.c - 1];
 		c.y[c.c] = c.y[c.c - 1];
 		
 }
  c.j[0] = c.j[0] + 1;
}
void derechaz () {
 for (c.c = 99; c.c > 0; c.c-- ) {
 		c.j[c.c] = c.j[c.c - 1];
 		c.y[c.c] = c.y[c.c - 1];
 		
 }
  c.y[0] = c.y[0] + 1;
}
void izquierdaz () {
 for (c.c = 99; c.c > 0; c.c-- ) {
 		c.j[c.c] = c.j[c.c - 1];
 		c.y[c.c] = c.y[c.c - 1];
 		
 }
  c.y[0] = c.y[0] - 1;
}
void manzana () {
	if (c.p == 1) {
	do {
	srand(time(NULL));
	c.a = rand()%18+1;
	c.b = rand()%38+1;
   }
   while (c.m[c.a][c.b] == 'x' || c.m[c.a][c.b] == 'o');
}
   if (c.m[c.a][c.b] != 'x'|| c.m[c.a][c.b] != 'o') {
   	c.m[c.a][c.b] = 'G';
   }
}
