#!/usr/bin/env python
#coding:utf-8

'''这是一个 echo 服务器的例子代码，服务器只能一次处理一个连接'''

import socket
import traceback
import sys

host, port = '', 8123
try:
	#创建一个 socket
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	#SO_REUSEADDR 是一个可以将释放掉的端口立即重新使用的一个选项，但实际上 TCP 原则是不建议这样，因为这样会影响 TCP 连接的释放中的2MSL
	sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	#将 socket 绑定到对应的 ip 和 端口上
	sock.bind((host, port))
except:
	traceback.print_exc()
	sock.close()
	sys.exit(1)
print 'bind in %s' % port
 
sock.listen(1)

while True:
	try:
		#阻塞等待客户端的连接
		client_sock, client_addr = sock.accept()
		#新连接到来，接受1024字节大小的数据
		data = client_sock.recv(1024)
		data = data.strip()
		while data and data != 'end':
			print "from client: ", data
			#将接受到的数据发回给客户端
			client_sock.sendall(data)
			#再接受直至遇到 end
			data = client_sock.recv(1024)
	except KeyboardInterrupt:
		raise
	except:
		traceback.print_exc()
	finally:
		client_sock.close()

sock.close()