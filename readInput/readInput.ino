int lastRow=1; //button pressed originally
int lastColumn=1; //button pressed originally
int rowArray[20]; //not needed
int columnArray[20]; //not needed
int rowCount=0; //when 20, confirm that button was pressed
int columnCount=0; //when 20, confirm that button was pressed
int scan=0;

char mapping[4][3] = {
                     {'#','0','*'},
                     {'9','8','7'},
                     {'6','5','4'},
                     {'3','2','1'}
                     }; //2D array of keypad [opposite of keypad because this is how pins are set up]

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  
  pinMode(2, OUTPUT); //column 3 
  pinMode(3, OUTPUT); //column 2 
  pinMode(4, OUTPUT); //column 1 
  pinMode(5, INPUT_PULLUP); //Row 4; when pressed, INPUT_PULLUP changes to 0
  pinMode(6, INPUT_PULLUP); //Row 3
  pinMode(7, INPUT_PULLUP); //Row 2
  pinMode(8, INPUT_PULLUP); //Row 1
  
  //+---+---+---+---+
  //|   | 4 | 3 | 2 |
  //+---+---+---+---+
  //| 8 ] 1 | 2 | 3 |
  //| 7 ] 4 | 5 | 6 |
  //| 6 ] 7 | 8 | 9 |
  //| 5 ] * | 0 | # |
}

// the loop function runs over and over again forever
void loop() {
  //run through every column
  for(int i=2;i<5;i++){
    digitalWrite(((i-1)%3)+2,HIGH);
    digitalWrite((i%3)+2,HIGH);
    digitalWrite(i,LOW);
    //when one column on, run through every row
    for(int j=5;j<9;j++){
      if(digitalRead(j) == 0){ //when digitalRead(j)=0, the button was pressed
       scan = 0;
       printNum(j,i);
      }else{
       if(scan == 12){
       lastRow = 1;
       lastColumn = 1;
       }else{
       scan++;
     } 
      }
    }
  }
}


void printNum(int row, int column){
  delay(10);
  //Serial.println(mapping[row-5][column-2]);
  if(row != lastRow || column !=lastColumn){
    lastRow = row;
    lastColumn = column;
    Serial.println(mapping[row-5][column-2]);
  }
}
