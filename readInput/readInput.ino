/* 
   This is a program to interpret input from a numerical keypad.  
   Systems Programming Homework 5
   Si Chen, Joshua Shapiro, Abigail Shriver, Katherine Walker
*/

int lastRow=1; //button pressed originally
int lastColumn=1; //button pressed originally
int rowCount=0; //when 20, confirm that button was pressed
int columnCount=0; //when 20, confirm that button was pressed
int scan=0; //count to keep track of when button was pressed

char mapping[4][3] = {
                     {'#','0','*'},
                     {'9','8','7'},
                     {'6','5','4'},
                     {'3','2','1'}
                     }; //2D character array of keypad [opposite of keypad because this is how pins are set up]

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
  
   /* The above diagram depicts how the pins correspond to rows and columns. Pin 4 corresponds to column 1 4 7 *.
     Pin 8 corresponds to row 1 2 3. 
  */
}

//this function runs continuously 
void loop() {
  //run through every column, starting with pin 2 (column 3 6 9 #) and ending with pin 4 (column 1 4 7 *)
  for(int i=2;i<5;i++)
  {
    digitalWrite(((i-1)%3)+2,HIGH); //write high to the pins that are not the current column
    digitalWrite((i%3)+2,HIGH);
    digitalWrite(i,LOW);  //write low to the pin that is the current column
     //when one column is on, run through every row
    //start with pin 5 (row * 0 #) and end with pin 8 (row 1 2 3)
    for(int j=5;j<9;j++){
      if(digitalRead(j) == 0){ //when digitalRead(j)=0, the button was pressed
       scan = 0; //if a button is pressed right now, start the count over
       printNum(j,i);
      }else{
       if(scan == 12){ //if no button has been pressed, set lastRow and lastColumn to 1
       lastRow = 1;
       lastColumn = 1;
       }else{ //if a button has been pressed but is not currently pressed, increment the count
       scan++;
       } 
      }
    }
  }
}


void printNum(int row, int column){
  delay(10); //wait to make sure correct key was pressed [debouncing
  if(row != lastRow || column !=lastColumn){ //if row and column are valid and different from the previous values
    lastRow = row; //set lastrow to the current row
    lastColumn = column; //set lastcolumn to the current column
    Serial.println(mapping[row-5][column-2]); //print the number corresponding to the correct column and row
    //column - 2 because pins 2 - 4 are the columns
    //row - 5 because pins 5 - 8 are the rows
  }
}
