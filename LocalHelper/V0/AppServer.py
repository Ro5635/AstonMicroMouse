"""
	App Server 

	This handles communication with the server, gets a log session from the server when required and
	appends new log points to the data set as required

	January 2017

"""

import requests
import json
import time
import random


"""
	Requests a new RunID from the server in order to start a new loggin run
"""
def getNewRunID():

	try:
		
		newRunIDReq = requests.post('https://app.astonmouse.com/ajax/newrun')

		# Interpret response as json and get 'RunID' parameter
		currentRunID = (json.loads( newRunIDReq.content ))['RunID']
		return  currentRunID
		
	except Exception, e:
		
		print "Unspecified Error"

		raise
	

"""
	Send new log item to the server
"""
def logNewDatum(currentRunID, logKeys):

	try:

		# Send the data to the server		
		requests.post('https://app.astonmouse.com/ajax/log', data={ 'RunID' : currentRunID , 'WallClock' : logKeys['wallClock'], 'Opto0' : logKeys['opto0'] , 'Opto1' : logKeys['opto1'] , 'Opto2' : logKeys['opto2'] , 'Opto3' : logKeys['opto3'] , 'Opto4' : logKeys['opto4'] , 'Opto5' : logKeys['opto5'] , 'Opto6' : logKeys['opto6'] , 'Opto7' : logKeys['opto7'] , 'Opto8' : logKeys['opto8'] , 'WheelLAngSpeed' : logKeys['wheelLAngSpeed'], 'WheelRAngSpeed' : logKeys['wheelRAngSpeed'], 'MotorRSetPoint' : logKeys['motorRSetPoint'] , 'MotorLSetPoint' : logKeys['motorLSetPoint'] })

		
	except Exception, e:
		
		print "Unspecified Error"

		raise



	