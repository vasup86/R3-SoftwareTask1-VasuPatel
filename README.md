# R3-SoftwareTask1-VasuPatel
R3 Software Training Module 1 Repo

The arduino project uses a UNO R3 Module to display potentiometer output on two 7-segment display

The project is implemented on TinkerCAD using a UNO R3 board, 2 breadboard, 1 LED light, 1 potentiomenter, 1 buzzer, 2 7-segment display, 2 7-segment decoder (CD4511) and resistors.

The project is the output of a potentiometer value mapped between 0 to 99 and displayed on 2 7-segment display as the potentiometer value is changing. If the value is greater than 94, the LED flashes and the buzzer sounds indicating DANGER!!.

The potentiometer output is read using analogRead() and then mapped using map function to a range between 0 to 99 from 0 to 1023. The mapped value is converted to two variables: *ones* and *tenth*, which stores the ones digit and the tenth place digit of the mapped number respectively. The ones and tenth place decoder pins are stored in an array from input pin 1 to 4 in *onePins* and *tenthPins*. As the value of the potentiomenter is changing, the digit and the pins related to the place digit are send to the function *displayNumber* with the appropriate pin array set for the decoder. For example if the number is 53, then the number is stored as *tenth* would be 5 and *ones* would be 3, then the function *displayNumber* is called to display the number to it's respective display. The function is a for loop that uses displayWrite to intialize each decoder pin as HIGH or LOW based on the digit passedto be displayed as an argument. The function is called twice for tenth digit (left display) and for one's digit (right display). The base 10 number 0-9's binary equivalent is saved in a 2D array called *decToBinPreset*, where the rows are the base 10 value and each column representing its binary equivalent. The 2D array is used as a preset for the decoder pins to be turned HIGH or LOW based on the digit to be displayed. The piezo buzzer and LED flashes if the value is greater than 95 to indicate danger. 

The Schematic and the link to the project is below. 

TinkerCAD Link: https://www.tinkercad.com/things/frKJt7A5PiL-r3-module-1-preset/editel

![Screenshot (161)](https://user-images.githubusercontent.com/83378929/136676823-01efdb2d-0285-445f-aa34-16a03d58cf66.png)
