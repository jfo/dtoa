require "serialport"

port_str = "/dev/tty.usbmodem1411"  #may be different for you
baud_rate = 115200

sp = SerialPort.new(port_str, baud_rate)

i = 440
while true do
    sp.write(i += 20)
    sleep 1
end
