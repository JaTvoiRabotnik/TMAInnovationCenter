# AQMPConsumer.py
import pika, os, time

queue_name = 'IoTprocess'

def iot_process_function(msg):
  print(" Received message %r from Publisher" % msg)
  time.sleep(5) # delays for 5 seconds
  return;

# Access the CLODUAMQP_URL environment variable and parse it
url = 'amqp://akghnaxh:7RUtHSfgHNrriXF7vvwONWJqVKL_SvVW@termite.rmq.cloudamqp.com/akghnaxh'
params = pika.URLParameters(url)
params.socket_timeout = 5

connection = pika.BlockingConnection(params)
channel = connection.channel() # start a channel
channel.queue_declare(queue=queue_name) # Declare a queue

# create a function which is called on incoming messages
def callback(ch, method, properties, body):
  iot_process_function(body)

# set up subscription on the queue
channel.basic_consume(callback,
  queue=queue_name,
  no_ack=True)

# start consuming (blocks)
print("Consumer is running.............")
channel.start_consuming()

connection.close()