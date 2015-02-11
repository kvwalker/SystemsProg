//set pin numbers
const int row1Pin = 0;
const int row2Pin = 0;
const int row3Pin = 0;
const int row4Pin = 0;
const int col1Pin = 0;
const int col2Pin = 0;
const int col3Pin = 0;

//declare a variable to determine if button is pressed or not
int buttonPressed = LOW;
int wasbuttonPressed = LOW; //was the button previously pressed

long debounceTime = 100; //this is the time to actually debounce

void setup()
{
  pinMode(row1Pin, INPUT);
  pinMode(row2Pin, INPUT);
  pinMode(row3Pin, INPUT);
  pinMode(row4Pin, INPUT);
  pinMode(col1Pin, INPUT);
  pinMode(col2Pin, INPUT);
  pinMode(col3Pin, INPUT);
}

void loop()
{
  
  
}
