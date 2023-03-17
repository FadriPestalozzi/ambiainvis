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
    # serial input = concatenated byte_string
    line = str(ser.readline())   # line = b'1110 22.39 56.71 \r\n'
    print(line)
    
    # a = b'1 2 3'      # concatenated byte_string
    # a.split(b' ')     # split at empty space to get
    # [b'1', b'2', b'3']    # individual byte_strings
    # list(map(int, a.split(b' ')))  # combine int values of individual byte_strings into list
    # [1, 2, 3]         # values of individual byte_strings into list

    if (len(line)!=0):
    # if (line!=b''): # first ser.readline == empty
        # TypeError: must be str or None, not bytes
        # remove trailing " \r\n'" = last 5 chars (keep final ')
        # line = line[:-6]+"'"
        print(line)

        # convert byte_string into string
        # line=b'1 2 3'  # no error if this line is active
        line.split(b' ')  # 
        values = list(map(float, line))
        print(str(values))

    time.sleep(0.5) 
    # time.sleep(5)
    

    # for c in ser.read():
    #     line.append(c)
    #     count += 1
        
    #     # sensor reading co2, T, RH 
    #     # each reading has 2 data and 1 checksum byte
    #     # number of 8-bit values per line = 3*3 = 9
    #     # if c == '\n':
    #     if count == 9: 
    #         # goal = convert line into variables with correct datatype, e.g. t = 21.0 deg
    #         print(line)
            
    #         # # combine 2x serial byte input to float numbers
            
    #         # print("v0: " + str(line[0]))
    #         # print("v1: " + str(line[1]))
        
    #         # # // << 8 used to left-shift by 8 bits and apply "OR = |" on trailing zeros to copy next variable            
    #         # # co2 = int(str((line[0] << 8) | line[1]),16)  # convert from base 16 = hex
    #         # co2 = int((str(line[0]) + str(line[1])),16)  # convert from base 16 = hex
    #         # print("co2: " + str(co2))      

    #         time.sleep(5)

    #         line = []
    #         count=0

    #         break

ser.close()