#/usr/bin/env  python2.7
from tegaki.recognizer import Recognizer
from ConfigParser import SafeConfigParser, NoSectionError, NoOptionError
import socket, traceback

host = ''
port = 10001

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server.bind((host, port))

while 1:
    try:
        message, address = server.recvfrom(10001)
        print "Got data from", address, ": ", message
        server.sendto(message, address)
    except (KeyboardInterrupt, SystemExit):
        raise
    except:
        traceback.print_exc()
