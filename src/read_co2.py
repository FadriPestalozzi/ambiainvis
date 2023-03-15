import serial
import time

ser = serial.Serial(
    port='/dev/ttyACM0',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=0)

print("connected to: " + ser.portstr)

# container to store the line
line = []

# count serial read values to start new line
count = 0

while True:
    # line = str(ser.readline())
    # print(line)

    for c in ser.read():
        line.append(c)
        count += 1
        
        # sensor reading co2, T, RH 
        # each reading has 2 data and 1 checksum byte
        # number of 8-bit values per line = 3*3 = 9
        # if c == '\n':
        if count == 9: 
            # goal = get variables in correct datatype
            # t = 21.0
            # combine 2x hex serial input to float numbers
            
            print("v0: " + str(line[0]))
            print("v1: " + str(line[1]))
        
            # // << 8 used to left-shift by 8 bits and apply "OR = |" on trailing zeros to copy next variable            
            # co2 = int(str((line[0] << 8) | line[1]),16)  # convert from base 16 = hex
            co2 = int((str(line[0]) + str(line[1])),16)  # convert from base 16 = hex
            print("co2: " + str(co2))      

            time.sleep(5)

            line = []
            count=0

            break

ser.close()