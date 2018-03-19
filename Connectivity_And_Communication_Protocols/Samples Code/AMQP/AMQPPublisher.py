# AQMPPublisher.py
import pika, os, time

count = 0
queue_name = 'IoTprocess'

# Parse CLODUAMQP_URL
url = 'amqp://akghnaxh:7RUtHSfgHNrriXF7vvwONWJqVKL_SvVW@termite.rmq.cloudamqp.com/akghnaxh'
params = pika.URLParameters(url)
params.socket_timeout = 5

connection = pika.BlockingConnection(params) # Connect to CloudAMQP
channel = connection.channel() # start a channel
channel.queue_declare(queue=queue_name) # Declare a queue

print ("Publisher is running.........")
while True:
	# send a message
	count = count + 1
	message = 'Package ID ' + str(count)
	channel.basic_publish(exchange='', routing_key=queue_name, body=message)
	print (' Sent message %r to Consumer' % message)
	time.sleep(5)
	
connection.close()