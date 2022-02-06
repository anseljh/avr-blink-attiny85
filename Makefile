###############################################################
# Makefile for AVR projects
###############################################################

# TARGET is the first part of the main source file, everything before .c
# If the main file is project.c, this should be `project`
TARGET=blink2

# Microprocessor type
# for avrdude -p (partno) option
MCU=attiny85

# Frequency; 1 Mhz default
F_CPU=1000000

###############################################################
# More options, but they probably don't need to change
###############################################################

# Compiler stuff, blah blah blah
#
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
SRCS=${TARGET}.c

# avrdude config
# avrdude options: https://www.nongnu.org/avrdude/user-manual/avrdude_3.html
#
# AVR programmer ID
# For avrdude -c (programmer-id) option
# SparkFun Tiny AVR Programmer uses `usbtiny`
PROGRAMMER=usbtiny

###############################################################
# Targets -- don't mess with this, either
###############################################################

all:
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
	avr-size ${TARGET}.hex
	@echo "\n\nIf that went well, to flash it, run: make flash\n"

flash:
	avrdude -p ${MCU} -c ${PROGRAMMER} -U flash:w:${TARGET}.hex:i -F -P usb

clean:
	rm -f *.bin *.hex
