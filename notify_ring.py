#!/usr/bin/python
#
# Tested with telegram-python-bot version 5
# For Arduino Yun

import telegram
import urllib

token = "YOUR_BOT_TOKEN"
local_file = "/tmp/image.jpg"
image_url = "YOUR CAMERA SNAPSHOT URL"
text_message = "YOUR MESSAGE"

user_id = 0 # YOUR USER ID
chat_id = 0 # YOUR CHAT ID

# send simple message
bot = telegram.Bot(token=token)
bot.sendMessage(chat_id=chat_id, text=text_message, parse_mode=telegram.ParseMode.HTML)

# retrieve the image from the camera
image = urllib.URLopener()
image.retrieve(image_url,local_file)

# send the image
bot.sendPhoto(chat_id=chat_id, photo=open(local_file, 'rb'))

# remove the temporary file
os.remove(local_file)
