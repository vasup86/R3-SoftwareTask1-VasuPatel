# R3-SoftwareTask1-VasuPatel
R3 Software Training Module 1 Repo

The arduino project uses a UNO R3 Module to display potentiometer output on two 7-segment display

The project is implemented on TinkerCAD using a UNO R3 board, 2 breadboard, 1 LED light, 1 potentiomenter, 1 buzzer, 2 7-segment display, 2 7-segment decoder (CD4511) and resistors.

The project is the output of potentiometer value mapped between 0 to 99 and displayed on 2 7-segment display as the potentiometer value is changing. If the value is greater than 94, the LED flashes and the buzzer sounds indicating DANGER!!.

The potentiometer output is read using analogRead() and then mapped using map function to a range between 0 to 99 from 0 to 1023. The mapped value is convert to two variables: *ones* and *tenth*, which stores the ones place and the tenth place digit of the mapped number. The ones and tenth place decoder pins are stored in an array from pin 1 to 4 in *onePins* and *tenthPins*. The number and the pins  are send to the function *displayNumber* with the appropriate pin array set for the decoder. The function is a for loop that uses displayWrite to intialize each decoder pin as HIGH or LOW based on the number passed as an argument to be displayed. The base 10 number 0-9's binary equivalent is saved in a 2D array called *decToBinPreset*, where the rows are the base 10 value and each column representing its binary equivalent. The 2D array is used as a preset for the pin decoder to be turned HIGH or LOW based on the digit to be displayed. The piezo buzzer and lED flashes if the value is greater than 95 to indicate danger. 

The Schematic and the link to the project is below. 

TinkerCAD Link: https://www.tinkercad.com/things/frKJt7A5PiL-r3-module-1-preset/editel

![Screenshot (155)](https://user-images.githubusercontent.com/83378929/136640988-74e58b91-d93a-4c3a-96e5-9ef0b865acac.png)
