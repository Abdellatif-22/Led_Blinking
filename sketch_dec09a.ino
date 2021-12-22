uint8_t j,rep,p,k,tik,m,tok,pin_max,pin_min,flash_rep,snake_rep;
uint16_t ms;
boolean level;
void setup() {
  // put your setup code here, to run once:

for(uint8_t i=0;i>10;i++){
  pinMode(i,OUTPUT);
  
}


m=0;
rep=0;
ms=500;
j=2;
p=6;k=5;
tik=0;

tok=1;
pin_min=1;
pin_max=4;
}

void loop() {
  // put your main code here, to run repeatedly:
 level=true;
   
up_down();
level=!level;

up_down();


right_left();
level=!level;
right_left();

snake();

all();

}



void UP(uint8_t ms,uint8_t level){
  while(j<10){
  digitalWrite(j,level);
  delay(ms);
  j++;
}
j--;
}


void DOWN(uint8_t ms,uint8_t level){
  while(j>1){
  digitalWrite(j,level);
  delay(ms);
   j--;
}
j++;
}
void up_down(){
 
  
  while(rep<7){
    
  digitalWrite(13,1);
    
  UP(ms,level);
  level=!level;
  DOWN(ms,level);
  if(ms>100) ms-=40;
  rep++;
  level=!level;
}
rep=0;
}


void right(){
  while(tik<4){

  digitalWrite(k,level);
  digitalWrite(p,level);
  delay(ms);
  p++;
  k--;
  tik++;
  }
  p--;
  k++;
  tik=0;
}

void left(){
  while(tik<4){
    digitalWrite(k,level);
  digitalWrite(p,level);
  delay(ms);
  p--;
  k++;
  tik++;
  }
  p++;
  k--;
  tik=0;
}
void right_left(){
  while(rep<7){
    right();
    level=!level;
    left();
    level=!level;
    rep++;
  }
  rep=0;

}


void forward(){
while(rep<9){
digitalWrite(m-1,0);
digitalWrite(m+1,1);
delay(ms);
m++;
rep++;
}
rep=0;
  
}
void back(){
  while(rep<9){
    digitalWrite(m-1,1);
    digitalWrite(m+1,0);
    delay(ms);
    m--;
    rep++;
  }
  rep=0;
}

void snake(){
  while(snake_rep<4){
    forward();
    back();
    snake_rep++;
  }
  snake_rep=0;
  
  
}


void flash( uint8_t pin_max,uint8_t pin_min){
   while(rep<7){
  tok=pin_min;
  while(tok<=pin_max){
    digitalWrite(tok,1);
    tok++;
  }
  
  delay(ms);
  while(tok>=pin_min){
    digitalWrite(tok,0);
    tok--;
  }
  tok++;
  delay(ms);
  rep++;
   }
   rep=0;
}


void all(){
 
  while( flash_rep<7){
    flash(5,2);
    flash(9,6);
    flash(7,4);
    flash(9,2);
    
  }
 

  
 flash_rep=0;

  
}





