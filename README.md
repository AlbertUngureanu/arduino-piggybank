I developed a piggy bank using an Arduino UNO, an LCD, a servo motor, 3 leds and a keyboard.
The code was written in C++, using object-oriented programming concepts, each component having both a header file and a .cpp in which I defined its class and the necessary methods.

Using the keyboard, we can choose from the following functionalities:

* \# -> open / close the roof of the piggy bank (if we want to open we will be asked for a pin)

* \* -> change the pin

* A -> add money to the piggy bank


For the last facility, adding money, I created a sensor using a LED and a photoresistor. 
Thus, when pressing the A key, we will be asked if we insert 50 or 10 coins. 
Then, the LED will light up and will count with the help of the resistance of the photoresistor how many times objects (coins) will pass between them.
Also, when a coin is detected, the green LED will light up.
We can stop the count using key D.

The LCD will help us both with monitoring the value in the piggy bank and with the previously presented options.
