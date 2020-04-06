

#include <SPI.h> //library
#include <Wire.h> //library
#include <Adafruit_GFX.h> //library
#include <Adafruit_SSD1306.h> //library

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define LOGO_HEIGHT   16  //starting logo of adafruit  
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =  //binary representation of logo
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
 
 
  testnametext();    // Draw name  text
  testgraphicstext(); // shows subject name



}

void loop() {
}

//calling function
void testnametext(void) {
  display.clearDisplay();

  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE); //colour
  display.setCursor(5, 0);//from where to start in display
  display.println(("FIRE FIGTING ROBOT"));// command is for printing text
display.println(("   "));
display.println(("BY:-"));
display.println(("GROUP 2"));
display.println(("    "));
display.println(("TO :-"));
display.println(("PROFESSOR MIKE "));
  display.display();      // Show initial text
  delay(3000); // after 3 sec it will move to next function 



}
 void testgraphicstext (void)
 {
     display.clearDisplay();

  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(2, 0);
  display.println(("  LAMBTON COLLEGE"));     
  display.println(("   "));
  display.println(("   "));
  display.setTextSize(2);
  display.println(("EMBT 4009"));
    display.display();      // Show initial text
  
 }

   





