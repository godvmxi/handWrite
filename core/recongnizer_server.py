#/usr/bin/env  python2.7
from tegaki.recognizer import Recognizer
from tegaki.engine import Engine
from tegaki.dictutils import SortedDict
from ConfigParser import SafeConfigParser, NoSectionError, NoOptionError
import socket, traceback
import sys
import pprint
import SocketServer



def select_recongnizer_models(name):
    pass



class RecognizerCore(Recognizer) :

    def init_recognizer(self,recognizer='zinnia'):
        recognizers = Recognizer.get_available_recognizers()
        print "Available recognizers", recognizers,type(recognizers)
        
        for temp in recognizers :
            pprint.pprint(temp)
        recognizer_name = recognizer
        if not recognizer_name in recognizers:
            raise Exception, "Not an available recognizer"

        recognizer_klass = recognizers[recognizer_name]
        self.recognizer = recognizer_klass()

        models = recognizer_klass.get_available_models()
        for model  in models :
            print type(model),model
        
        for model  in models :
            print type(model),model
        print "++++"
        for r_name, model_name, meta  in Recognizer.get_all_available_models() :
            print r_name
            print model_name
            print meta

        
        print "\nAvailable models", models,type(models)
        print (models['Simplified Chinese']['shortname'])
        model = "Simplified Chinese"
        if not model in models:
            raise Exception, "Not an available model"

        print self.recognizer.set_model(model)

    def parse_xml(xml_file) :
        char = Character()
        char.read(xml_file)
        writing = char.get_writing()
        print "\n".join(["%s %f" % (c,s) for c,s in recognizer.recognize(writing)])


    def  executeCmd(self,cmd):
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
    reg =  RecognizerCore()
    reg.init_recognizer()
    print(sys.argv[0])
    reg.parse_xml(sys.argv[0])
    sys.exit(1)
    HOST, PORT = "localhost", 20000
        # Create the server, binding to localhost on port 9999
    server = SocketServer.UDPServer((HOST, PORT), RecognizerServer)
   
    

    # Activate the server; this will keep running until you
    # interrupt the program with Ctrl-C
    server.serve_forever()

    
