import serial
# import logging  # ToDo, create logfile of relevant events

ser = serial.Serial(
    port='/dev/ttyACM0',
    baudrate=115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=30)  # ser.*  blocked for a max of timeout seconds until complete

print("connected to: " + ser.portstr)

while True:
    line = ser.readline()   # line = b'1110 22.39 56.71 \r\n'
    # print(type(line))     # <class 'bytes'>

    # error if timeout reached
    if (len(line) == 0):  # check if ser.readline == empty
        print("timeout error")

    # convert byte_string into string
    line = line.strip()          # remove non-readable chars, /r/n
    line_splitted = line.split(b' ')  # split at spaces
    # print(line_splitted)       # [b'1419', b'23.48', b'57.34']
    # print(type(line_splitted)) # <class 'list'>

    # convert each element of bytes_list into type float
    # list comprehension
    values = [float(i) for i in line_splitted]
    # alternative method
    # values = list(map(float, line_splitted))
    print(values)

ser.close()
