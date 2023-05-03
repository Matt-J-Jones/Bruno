#define A 2
#define B 3
#define C 4
#define D 5

#define E 6
#define F 7
#define G 8
#define H 9
 
#define NUMBER_OF_STEPS_PER_REV 512

void setup(){
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);

pinMode(E,OUTPUT);
pinMode(F,OUTPUT);
pinMode(G,OUTPUT);
pinMode(H,OUTPUT);
}

void write(int a,int b,int c,int d, int e, int f, int g, int h){
digitalWrite(A,a);
digitalWrite(B,b);
digitalWrite(C,c);
digitalWrite(D,d);

digitalWrite(E,e);
digitalWrite(F,f);
digitalWrite(G,g);
digitalWrite(H,h);
}

void onestep(){
int del = 1;

write(1,0,0,0,1,0,0,1);
delay(del);
write(1,1,0,0,0,0,0,1);
delay(del);
write(0,1,0,0,0,0,1,1);
delay(del);
write(0,1,1,0,0,0,1,0);
delay(del);
write(0,0,1,0,0,1,1,0);
delay(del);
write(0,0,1,1,0,1,0,0);
delay(del);
write(0,0,0,1,1,1,0,0);
delay(del);
write(1,0,0,1,1,0,0,0);
delay(del);
}

void loop(){
int i;
i=0;
while(i<NUMBER_OF_STEPS_PER_REV){
onestep();
i++;
}
}
