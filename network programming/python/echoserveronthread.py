#!/usr/bin/env python
#coding:utf-8

"""这是一个多线程的 echo 服务器，为每一个连接新建一个线程进行处理"""

import threading
import traceback
import socket
import sys

def echoServerBuild(host, port):
	try:
		sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
		sock.bind((host, port))
	except:
		traceback.print_exc()
		sys.exit(1)
	print 'bind in %s' % port
	sock.listen(1)
	return sock

#Version 1. use socket.recv()
def echohandler1(cli_sock):
	threadname = threading.currentThread().getName()
	try:
		data = cli_sock.recv(1024)
	except:
		print 'in ', threadname
		traceback.print_exc()
		sys.exit(1)
	
	while data:
		print 'in %s recv data %s' % (threadname, data)
		data = data.strip()
		if data == 'end':
			break
		cli_sock.sendall(data)
		data = cli_sock.recv(1024)
		
	cli_sock.close()
	print '%s is over' % threadname
	
	
#Version 2. use socket.makefile()
def echohandler2(cli_sock):
	threadname = threading.currentThread().getName()
	fd = cli_sock.makefile()
	data = fd.readline()
	while data:
		print 'in %s recv data %s' % (threadname, data)
		data = data.strip()
		if data == 'end':
			break
		fd.write(data)
		data = fd.readline()
	fd.close()
	cli_sock.close()
	print '%s is over' % threadname
	
if __name__ == '__main__':
	host = ''
	port = int(sys.argv[1])
	serv_sock = echoServerBuild(host, port)
	try:
		while True:
			cli_sock, cli_addr = serv_sock.accept()
			t = threading.Thread(target=echohandler, args=[cli_sock])
			t.start()
	except:
		traceback.print_exc()
	finally:
		serv_sock.close()