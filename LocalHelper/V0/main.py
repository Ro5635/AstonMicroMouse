# This is the start of the local helper, this acts as the intermediary between the mouse and the server
# 
# This is nothing more than a quick MVP
# 


import serial
import time
import random

import AppServer

currentRunID = 0
logStartTime = 0


logKeys = dict.fromkeys(['redacted', 'wallClock' ,  'opto0' , 'opto1' , 'opto2' , 'opto3' , 'opto4' , 'opto5' , 'opto6' , 'opto7' , 'opto8'  , 'wheelLAngSpeed' , 'wheelRAngSpeed'  , 'motorRSetPoint' , 'motorLSetPoint'], 0)


currentRunID = AppServer.getNewRunID()

print 'New id: ' , currentRunID

logStartTime = time.time()

for x in xrange(1,145):

	time.sleep(0.05) 

	logKeys['wallClock'] = time.time() - logStartTime
	logKeys['wallClock'] =  logKeys['wallClock'] * 1000
	logKeys['opto0'] = random.randint(1, 255)
	logKeys['opto1'] = random.randint(1, 255)
	logKeys['opto2'] = random.randint(1, 255)
	logKeys['opto3'] = random.randint(1, 255)
	logKeys['opto4'] = random.randint(1, 255)
	logKeys['opto5'] = random.randint(1, 255)
	logKeys['opto6'] = random.randint(1, 255)
	logKeys['opto7'] = random.randint(1, 255)
	logKeys['opto8'] = random.randint(1, 255)


	AppServer.logNewDatum(currentRunID, logKeys)

	pass
