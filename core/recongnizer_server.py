#/usr/bin/env  python2.7
from tegaki.recognizer import Recognizer
from ConfigParser import SafeConfigParser, NoSectionError, NoOptionError
import socket, traceback
import sys
import pprint

host = ''
port = 10001
def create_udp_server(port):
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind(('', port))
    return server
def select_recongnizer_models(name):
    pass
def get_all_availabke_models():
    all_models = Recognizer.get_all_available_models()
    
##    pprint.pprint(all_models)
    for r_name, model_name, meta in all_models :
        print(r_name)
        print(model_name)
        print(meta)
    return all_models
    
if __name__ == "__main__": 
##    print()
    get_all_availabke_models()
    sys.exit()
    while 1:
        try:
            message, address = server.recvfrom(10001)
            print "Got data from", address, ": ", message
            server.sendto(message, address)
        except (KeyboardInterrupt, SystemExit):
            raise
        except:
            traceback.print_exc()
