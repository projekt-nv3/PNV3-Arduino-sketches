import serial
import time

# Configure the serial port
serial_port = '/dev/ttyACM0'  # Modify with your Arduino's serial port
baud_rate = 9600

# Initialize the serial connection
ser = serial.Serial(serial_port, baud_rate)
time.sleep(2)  # Allow time for the Arduino to reset

def send_command(command):
    # Send the command to the Arduino
    ser.write(command.encode())

# Example usage
send_command('F')  # Forward
time.sleep(3)  # Run forward for 2 seconds
send_command('B')  # Brake
time.sleep(1)  # Apply brake for 1 second
send_command('R')  # Reverse
time.sleep(3)  # Run in reverse for 2 seconds
send_command('B')  # Brake
time.sleep(1)  # Apply brake for 1 second

# Close the serial connection
ser.close()

