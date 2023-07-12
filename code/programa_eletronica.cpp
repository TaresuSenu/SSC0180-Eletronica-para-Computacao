#define pedra1 4
#define papel1 3
#define tesoura1 2
#define pedra2 7
#define papel2 6
#define tesoura2 5
 
#define showPedra1 11
#define showPapel1 12
#define showTesoura1 13
#define showPedra2 8
#define showPapel2 9
#define showTesoura2 10
 
bool wasPressed1=0;
bool wasPressed2=0;
 
int play1;
int play2;
 
void setup()
{
  pinMode(pedra1, INPUT);
  pinMode(pedra2, INPUT);
  pinMode(tesoura1, INPUT);
  pinMode(tesoura2, INPUT);
  pinMode(papel1, INPUT);
  pinMode(papel2, INPUT);
 
  pinMode(showPedra1, OUTPUT);
  pinMode(showPapel1, OUTPUT);
  pinMode(showTesoura1, OUTPUT);
  pinMode(showPedra2, OUTPUT);
  pinMode(showPapel2, OUTPUT);
  pinMode(showTesoura2, OUTPUT);
}
 
void loop()
{
  if(!wasPressed1){
    int pe=digitalRead(pedra1);
  	int pa=digitalRead(papel1);
  	int te=digitalRead(tesoura1);
 
    if(pe==HIGH){
      play1=1;
      wasPressed1=true;
    }else if(te==HIGH){
      play1=3;
      wasPressed1=true;
    }else if(pa==HIGH){
      play1=2;
      wasPressed1=true;
    }
  }
  if(!wasPressed2){
    int pe=digitalRead(pedra2);
  	int pa=digitalRead(papel2);
  	int te=digitalRead(tesoura2);
 
    if(pe==HIGH){
      play2=1;
      wasPressed2=true;
    }else if(te==HIGH){
      play2=3;
      wasPressed2=true;
    }else if(pa==HIGH){
      play2=2;
      wasPressed2=true;
    }
  }
 
  if(wasPressed1 && wasPressed2){
  	delay(100);
 
    if(play1==1)
    	digitalWrite(showPedra1, HIGH);
    if(play1==2)
      	digitalWrite(showPapel1, HIGH);
    if(play1==3)
    	digitalWrite(showTesoura1, HIGH);
 
    if(play2==1)
    	digitalWrite(showPedra2, HIGH);
    if(play2==2)
      	digitalWrite(showPapel2, HIGH);
    if(play2==3)
    	digitalWrite(showTesoura2, HIGH);
 
    delay(1000);
 
    if(play1==play2){
      draw();
    }else{
      if(play1==1){
        if(play2==2){
          digitalWrite(showPedra1, LOW);
          win2();
        }else if(play2==3){
          digitalWrite(showTesoura2, LOW);
          win1();
        }
      }else if(play1==2){
      	if(play2==1){
          digitalWrite(showPedra2, LOW);
          win1();
        }else if(play2==3){
          digitalWrite(showPapel1, LOW);
          win2();
        }
      }else if(play1==3){
      	if(play2==1){
          digitalWrite(showTesoura1, LOW);
          win2();
        }else if(play2==2){
          digitalWrite(showPapel2, LOW);
          win1();
        }
      }
   	}
    wasPressed1=wasPressed2=false;
  }
 
}
void win1(){
  digitalWrite(showPedra1, HIGH);digitalWrite(showPapel1, HIGH);digitalWrite(showTesoura1, HIGH);
  delay(500);
  digitalWrite(showPedra1, LOW);digitalWrite(showPapel1, LOW);digitalWrite(showTesoura1, LOW);
  delay(500);
  digitalWrite(showPedra1, HIGH);digitalWrite(showPapel1, HIGH);digitalWrite(showTesoura1, HIGH);
  delay(500);
  digitalWrite(showPedra1, LOW);digitalWrite(showPapel1, LOW);digitalWrite(showTesoura1, LOW);
  delay(500);
  digitalWrite(showPedra1, HIGH);digitalWrite(showPapel1, HIGH);digitalWrite(showTesoura1, HIGH);
  delay(500);
  digitalWrite(showPedra1, LOW);digitalWrite(showPapel1, LOW);digitalWrite(showTesoura1, LOW);
}
void win2(){
  digitalWrite(showPedra2, HIGH);digitalWrite(showPapel2, HIGH);digitalWrite(showTesoura2, HIGH);
  delay(500);
  digitalWrite(showPedra2, LOW);digitalWrite(showPapel2, LOW);digitalWrite(showTesoura2, LOW);
  delay(500);
   digitalWrite(showPedra2, HIGH);digitalWrite(showPapel2, HIGH);digitalWrite(showTesoura2, HIGH);
  delay(500);
  digitalWrite(showPedra2, LOW);digitalWrite(showPapel2, LOW);digitalWrite(showTesoura2, LOW);
  delay(500);
   digitalWrite(showPedra2, HIGH);digitalWrite(showPapel2, HIGH);digitalWrite(showTesoura2, HIGH);
  delay(500);
  digitalWrite(showPedra2, LOW);digitalWrite(showPapel2, LOW);digitalWrite(showTesoura2, LOW);
}
 
void draw(){
  digitalWrite(showPedra1, HIGH);digitalWrite(showPapel1, HIGH);digitalWrite(showTesoura1, HIGH);
  digitalWrite(showPedra2, HIGH);digitalWrite(showPapel2, HIGH);digitalWrite(showTesoura2, HIGH);
  delay(500);
  digitalWrite(showPedra1, LOW);digitalWrite(showPapel1, LOW);digitalWrite(showTesoura1, LOW);
  digitalWrite(showPedra2, LOW);digitalWrite(showPapel2, LOW);digitalWrite(showTesoura2, LOW);
  delay(500);
  digitalWrite(showPedra1, HIGH);digitalWrite(showPapel1, HIGH);digitalWrite(showTesoura1, HIGH);
  digitalWrite(showPedra2, HIGH);digitalWrite(showPapel2, HIGH);digitalWrite(showTesoura2, HIGH);
  delay(500);
  digitalWrite(showPedra1, LOW);digitalWrite(showPapel1, LOW);digitalWrite(showTesoura1, LOW);
  digitalWrite(showPedra2, LOW);digitalWrite(showPapel2, LOW);digitalWrite(showTesoura2, LOW);
  delay(500);
  digitalWrite(showPedra1, HIGH);digitalWrite(showPapel1, HIGH);digitalWrite(showTesoura1, HIGH);
  digitalWrite(showPedra2, HIGH);digitalWrite(showPapel2, HIGH);digitalWrite(showTesoura2, HIGH);
  delay(500);
  digitalWrite(showPedra1, LOW);digitalWrite(showPapel1, LOW);digitalWrite(showTesoura1, LOW);
  digitalWrite(showPedra2, LOW);digitalWrite(showPapel2, LOW);digitalWrite(showTesoura2, LOW);
}
