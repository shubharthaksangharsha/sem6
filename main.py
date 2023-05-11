import poe 
import sys 
import logging 
token = 'Q1_dtpKhd35FMF-aS6lIow%3D%3D'
poe.logger.setLevel(logging.INFO)

client = poe.Client(token)

def say(msg):
  ans = '' 
  for chunk in client.send_message('chinchilla', msg, with_chat_break=False):
    print(chunk['text_new'], end = '', flush=True)
    
  
if __name__ == '__main__':
	while True:
		msg = input('> ')
		if 'bye' in msg or 'exit' in msg:
			break
		say(msg)
		print()
	print('Thank you for using me')
