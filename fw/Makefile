MCU	  = atmega8
F_CPU = 1000000

AVRDUDE_MCU      = m8
AVRDUDE_PRG	     = avrisp2
AVRDUDE_PRG_PORT = usb
AVRDUDE_BITCLOCK = 3

SIM_GDB_PORT = 1234

CC = avr-gcc

CFLAGS = -W -Wall -Wextra -pedantic -std=c11
CFLAGS += -ffreestanding -fwhole-program -funsigned-char -fpack-struct -fshort-enums

# Together with -Wl,-gc-sections this will remove unused functions and data sections.
CFLAGS += -fdata-sections -ffunction-sections

# optimizations
CFLAGS += -Os -flto -fno-tree-scev-cprop

CFLAGS += -mmcu=$(MCU) -DF_CPU=$(F_CPU)

DBG_CFLAGS = -DEBUG -g3 -gdwarf-2 -O0

LDFLAGS = -lm -Wl,-gc-sections -Wl,--relax

SRCS = $(shell find . -name '*.c')
HDRS = $(shell find . -name '*.h')

default: main.hex main.eep

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

%.eep: %.elf
	avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex $< $@

main.elf: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRCS) -o main.elf
	avr-size --format=avr --mcu=$(MCU) main.elf

main-dbg.elf: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) $(DBG_CFLAGS) $(LDFLAGS) $(SRCS) -o main-dbg.elf


.PHONY: sim chip_erase chip_write_flash chip_write_eeprom chip_write open_terminal print_size clean me_cry

# TODO killall in a makefile is a very, very, very bad idea: find a way to fix!
sim: main-dbg.hex main-dbg.elf
	simulavr -g -d $(MCU) -p $(SIM_GDB_PORT) main-dbg.hex &
	avr-gdb --tui -ex "target remote localhost:$(SIM_GDB_PORT)" -ex "load" -ex "focus CMD" -ex "b main" ./main-dbg.elf
	killall simulavr

chip_erase:
	avrdude -p $(AVRDUDE_MCU) -c $(AVRDUDE_PRG) -P $(AVRDUDE_PRG_PORT) -B $(AVRDUDE_BITCLOCK) -e

chip_write_flash: main.hex
	avrdude -p $(AVRDUDE_MCU) -c $(AVRDUDE_PRG) -P $(AVRDUDE_PRG_PORT) -B $(AVRDUDE_BITCLOCK) -U flash:w:main.hex:a

chip_write_eeprom: main.eep
	avrdude -p $(AVRDUDE_MCU) -c $(AVRDUDE_PRG) -P $(AVRDUDE_PRG_PORT) -B $(AVRDUDE_BITCLOCK) -U eeprom:w:main.eep

chip_write: chip_write_flash chip_write_eeprom

open_terminal:
	avrdude -p $(AVRDUDE_MCU) -c $(AVRDUDE_PRG) -P $(AVRDUDE_PRG_PORT) -t

print_size: main.elf
	avr-nm -S --size-sort -r main.elf
	avr-size --format=avr --mcu=$(MCU) main.elf

clean:
	rm -f *.elf *.hex *.eep

me_cry:
	@grep -r -E '(TO)(DO)' | wc -l
