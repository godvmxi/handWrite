#/usr/bin/env  python2.7
from tegaki.recognizer import Recognizer
from ConfigParser import SafeConfigParser, NoSectionError, NoOptionError
import socket, traceback
import sys
import pprint
import SocketServer
from SocketServer import TCPServer,ThreadingMixIn,StreamRequestHandler
class Server(ThreadingMixIn,TCPServer):
    pass
class Handler(StreamRequestHandler):
    def handle(self):
        addr=self.request.getpeername()
        data=self.request
        print "got connection from",addr
        self.wfile.write("connected")





host = ''
port = 20000
def create_udp_server(port):
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind(('', port))
    return server
def wait_udp_data(server):
    while 1:
        try:
            message, address = server.recvfrom(10001)
            print "Got data from", address, ": ", message
            server.sendto(message, address)
        except (KeyboardInterrupt, SystemExit):
            raise
        except:
            traceback.print_exc()
            
def create_tcp_server(port):
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server.bind(('', port))
    server.listen(1)
    return server

def wait_tcp_data(server):
    while 1:
        conn,addr=server.accept()
        print "got connection form ",conn.getpeername() ,addr
        data=conn.recv(1024)
        print "data -> %s  "%data
        if not data:
            break
        else:
            print data
        print("ack-->")
        conn.send("ack++++++++++++")

def get_all_availabke_models():
    all_models = Recognizer.get_all_available_models()
    
##    pprint.pprint(all_models)
    for r_name, model_name, meta in all_models :
        print(r_name)
        print(model_name)
        print(meta)
    return all_models

def select_recongnizer_models(name):
    pass
    
if __name__ == "__main__": 
    server=Server(('',port),Handler)
    server.serve_forever()
    sys.exit(1)
##    print()
    get_all_availabke_models()
##    sys.exit()
    server =  create_tcp_server(port)
    wait_tcp_data(server)
    
