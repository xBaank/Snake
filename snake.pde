
 int x = 255;
 int y = 155;
 int xapl;
 int yapl;
 int spd = 2;
 int etn = 0;
 int apletn = 1;
 void setup () {
  size (600,400);
  noStroke();
}

void draw () {
  clear();
  background(#8D8D8D); 
  text(etn,10,15); //contador
  square(); //personaje
  squaremove(); //movimiento personaje
  //si el personaje esta en el rango de la manzana entoces manzana comida es uno y a manzanas comidas se le añade uno
  if (((x-xapl) < 19 && (x-xapl) > -19) && (y - yapl) < 19 && (y - yapl) > -19 ) {
  apletn = 1;
  etn += 1;
  }
  //si mazana es comida
  if (apletn == 1) {
  apple(); //nueva posicion manzana y  manzana comida es cero / falso
  }
  drawapple();// dibujar manzana
}

void square() {
  fill(#CD00FF);
  rect(x,y,20,20); 
}

void squaremove () {
  //movimiento, ez
if (keyCode == UP) {
    y -= spd;
  }
  if (keyCode == DOWN) {
    y += spd;
  }
  if (keyCode == RIGHT) {
    x += spd;
  }
  if (keyCode == LEFT) {
    x -= spd;
  }

}

void apple () {
  xapl = (int) random(560)+20; //valor random en el eje x para la nueva posicion de la manzana, solo dentro de esos valores, y se añade 20 porque su diametro es de 20, asi no se queda fuera de la pantalla
  yapl = (int) random(360)+20; // valor random en el eje y
  apletn = 0; //manzana comida es cero /falso 
}

void drawapple() {
  fill(#DC1717);
  ellipse(xapl,yapl,20,20);
}
