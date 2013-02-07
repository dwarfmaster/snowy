NAME=projector
OBJS=isn.o sound.o reveil.o screen.o music.o date.o
AVRP=/usr/lib/arduino/hardware/tools/avr/bin/
FLAGS=-g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=103 -I /usr/share/arduino/hardware/arduino/cores/arduino/ -I /usr/lib/arduino/libraries/LiquidCrystal/ -I /usr/lib/arduino/hardware/arduino/cores/arduino/ -I /usr/lib/arduino/hardware/arduino/variants/standard/
PORT=/dev/ttyACM0
BAUDRATE=115200

$(NAME).hex : $(OBJS)
	cd core && make
	avr-gcc -Os -Wl,--gc-sections -mmcu=atmega328p -o $(NAME).elf $^ ./core/core.a -L core -lm
	avr-objcopy -O ihex -R .eeprom $(NAME).elf $(NAME).hex

%.o : %.cpp
	avr-g++ $(FLAGS) -c $< -o $@

transmit : $(NAME).hex
	$(AVRP)/../../avrdude -C /usr/lib/arduino/hardware/tools/avrdude.conf -v -p m328p -P $(PORT) -b$(BAUDRATE) -c arduino -U flash:w:$(NAME).hex

connect : transmit
	screen $(PORT) 9600

clean :
	rm -vf $(OBJS)
	rm -vf $(NAME).{elf,hex}

mr-proper : clean
	cd core && touch tmp.o tmp.a
	cd core && make clean

rec : clean $(NAME).hex

.PHONY:clean connect transmit rec mr-proper


