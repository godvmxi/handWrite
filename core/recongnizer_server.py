#/usr/bin/env  python2.7
from tegaki.recognizer import Recognizer
from ConfigParser import SafeConfigParser, NoSectionError, NoOptionError
import socket, traceback
import sys
import pprint
import SocketServer






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




def select_recongnizer_models(name):
    pass



class RecognizerHandler() :
    def __init__(self):
        pass
    def get_selected_model(self):
        pass
    def set_selected_model(self,i):
        pass
    def recognize(self,writing,n=10):
        """
        
        """
        pass
    @staticmethod
    def get_all_availabke_models():
        all_models = Recognizer.get_all_available_models()
        for r_name, model_name, meta in all_models :
            print(r_name)
            print(model_name)
            print(meta)
        return all_models
        
class     QueryParser():
    def __init(self):
        pass

from SocketServer import TCPServer,ThreadingMixIn,StreamRequestHandler
class Server(ThreadingMixIn,TCPServer):
    pass
class Handler(StreamRequestHandler):
    def handle(self):
        addr=self.request.getpeername()
        data=self.request
        print "got connection from",addr
##        self.wfile.write("connected")
        while True:  
            data = self.request.recv(1024)  
            if not data:   
                break  
            print "RECV from ", self.client_address[0]  ,data
            self.request.send("ack")


import SocketServer
class RecognizerServer(SocketServer.BaseRequestHandler):
    """
    The RequestHandler class for our server.
 
    It is instantiated once per connection to the server, and must
    override the handle() method to implement communication to the
    client.
    """
 
    def handle(self):
        # self.request is the TCP socket connected to the client
        data = self.request[0].strip()
        socket = self.request[1]
        print socket,data

        socket.sendto("ack",self.client_address)
 

    
if __name__ == "__main__": 
    HOST, PORT = "localhost", 20000
        # Create the server, binding to localhost on port 9999
    server = SocketServer.UDPServer((HOST, PORT), RecognizerServer)

    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server.serve_forever()

    
