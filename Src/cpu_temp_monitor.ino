#include <Wire.h>                      // I2C arduino library for serial communication protocol
#include <LiquidCrystal_I2C.h>        // LCD library for I2C 16x2 display

#define TEMP_SENSOR_PIN A0            // Analog pin connected to LM35 going into arduino ADC pin AO

// Initialize LCD at I2C address 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Function prototypes

void setup_interfaces(void);
float read_temperature_celsius(void);
void display_temperature(float temp_c);

void setup(void) {
    setup_interfaces();               // Initialize LCD, Serial, and pin modes
}

void loop(void) {
    float temp = read_temperature_celsius();  // Read temperature from sensor
    display_temperature(temp);                // Output to LCD and Serial
    delay(1000);                              // Wait 1 second
}

void setup_interfaces(void) {
    Serial.begin(9600);                       // Initialize serial at 9600 baud rate

    lcd.init();                               // Initialize LCD
    lcd.backlight();                          // Turn on LCD backlight
    lcd.clear();                              // Clear LCD screen
    lcd.setCursor(0, 0);                      // Set cursor to top-left
    lcd.print("CPU Temp Monitor");           // Display header
    delay(1000);                              // Pause to show message

    pinMode(TEMP_SENSOR_PIN, INPUT);          // Set temp sensor pin as input
}

float read_temperature_celsius(void) {
    int analog_value = analogRead(TEMP_SENSOR_PIN);        // Read analog input
    float voltage = (analog_value / 1023.0f) * 5.0f;        // Convert to voltage
    return voltage * 100.0f;                                // Convert to °C (LM35: 10mV per °C)
}

void display_temperature(float temp_c) {

    // Print to LCD
    lcd.setCursor(0, 1);             // Move to second line
    lcd.print("Temp: ");
    lcd.print(temp_c, 1);            // Show temperature with 1 decimal place
    lcd.print(" C   ");              // Pad spaces to clear previous text
}

