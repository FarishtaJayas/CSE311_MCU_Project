# Password-Based-Door-Lock-System-Using-8051-PIC-Microcontroller

Title: Password based door lock system using 8051/PIC microcontroller

If you are planning on taking CSE331 under RSF at NSU. You have full permission to copy this project.
Please overlook the names of the files. We were kids. 

Project Members:\
Farishta Jayas\
Maraj Hossain\
Syed Maaher Hossain

## Objective

Traditional lock systems using the lock and key mechanism are gradually being replaced by new
advanced door locking systems. These systems have integrated mechanical and electronic
devices, and are highly intelligent. One of the prominent features of these lock systems is their
simplicity and efficiency. So, the main objective of this project is to build a password based door
lock system. This is a simple system, which will use a password to unlock a door

## Application

This simple system can be used in organizations such as hospitals, mosques and schools, and
specially vaults in banks to ensure authorized access to highly secured places. It can even be
used at residential places to ensure better safety. It can be used in electrical appliances as well,
such as fridges. High security prison cells can also make use of this system

## Working Procedures

The main mechanism of the system is that the door will open only when the correct password is
entered, and it will not open if the wrong password is entered. We developed this system using
the 8051/PIC microcontroller. The system will take input from the keypad, and the output will be
displayed on a LCD screen. Along with two LEDs, a red one and a green one which will light up
depending on whether the correct input was entered or not.
Once the door is opened using a motor on entering the correct password, the concerned person
will be allowed access to the secured area, and the door will be closed once again using the same
motor. Again, if another person arrives, it will ask to enter the password. If the password is
wrong, the door will remain closed, denying access to the person.Pin Configuration:
### LCD Display
D0 - Port1, Pin 0\
D1 - Port1, Pin 1\
D2 - Port1, Pin 2\
D3 - Port1, Pin 3\
D4 - Port1, Pin 4\
D5 - Port1, Pin 5\
D6 - Port1, Pin 6\
D7 - Port1, Pin 7\
RS - Port 3, Pin 5\
RW - Port 3, Pin 6\
E - Por 3, Pin 7
### Motor
1 - Port 3, Pin 3\
2 - Port 3, Pin 4
### Red LED
1 - Port 2, Pin 5\
2 - Port 2, Pin 4
### Green LED
1 - Port 2, Pin 7\
2 - Port 2, Pin 6
### Keypad
A - Port 2, Pin 0\
B - Port 2, Pin 1\
C - Port 2, Pin 2\
D - Port 2, Pin 3\
1 - Port 3, Pin 0\
2 - Port 3, Pin 1\
3 - Port 3, Pin 2

## Discussion

The aim of the project was to design and implement an automatic door locking system using an
8051 microcontroller. A few issues were observed during implementation. For example, double
inputs were being registered for some of the digits being entered, this was solved by changing
the working frequency of the system from 12MHz to 8MHz.
Furthermore, we tried implementing two LEDs to indicate whether the user entered the right
password or not. We were not able to work the LEDs initially but later on figured out that LEDs
are active pins, after which we properly configured the pins to the ports of the MCU. Now the
green LED lights up when the user enters the right password while the red one lights up when an
incorrect password is entered.
Another issue that we faced in the system was with the motor which mechanically opens the
door for the user when the right pass is entered. Figuring out the direction of rotation and when
the motor would rotate was tricky at first, but the working principles were similar to that of the
LEDs, keeping that as reference we were also able to properly implement the motor.
Lastly, we tried to integrate a buzzer into our system, which would make a sound every time a
wrong password was entered. But we were unable to implement it as the buzzer was not getting
connected, and as a result, it was not making the buzzing sound as well


