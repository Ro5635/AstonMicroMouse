
MicroMouse Communications Look Up

ID Name

first two digits select the domain and the final two the actual 'function'


01 : System Control
	
	Allows for the changing of the current run mode

	01 : STOP : Stops The Robot
	02 : Manual Control Mode
	03 : LineFolloingMode
	04 : RaceMode
	05 : MazeMode

02 : ManualControl

	When the device is in the manual control mode it will poll for the current command every 90 milliseconds and it will switch to the response command.

	01 : Stop 			Parameters:  Power 3 digits 000 -> 100
	02 : Forward		Parameters:  Power 3 digits 000 -> 100
	03 : Backward		Parameters:  Power 3 digits 000 -> 100
	04 : Right			Parameters:  Power 3 digits 000 -> 100
	05 : Left			Parameters:  Power 3 digits 000 -> 100


03 : LineFollowingMode

	This is the line following mode, when switched to this mode it will start in the hold state.

	01 : Hold 			Holds the robot in its current position
	02 : SeekAndGo		Seeks for the line and goes

04 : RaceMode

	Will find the line and then proceed as fast as possible to the end zone whilst looking out for the end markings, when switched to this mode its starts in hold mode

	01 : Hold			Holds the robot in the current position
	02 : SeekAndGo		Seeks For the line and goes

05 : MazeMode
	
	Will attempt to navigate the maze using the time of flight sensors.

	01 : Hold			Holds the robot in the current position
	02 : SeekAndGo		Seeks the wall and goes; Assumes that it is at the start of the course

06 : LogRequest

	Allows the user to request the logging of specified data points by supplying a list of all the data IDs to log, the log runs on a timer and logs each specified point back to the PC on each trigger of the timer.  

	01 : SuspendLog		Suspends the active logging process, shut down the timer
	02 : EnableLog		Enables the logging, sets up timer to call logging process
	03 : SetLogPoints	Allows the user to set the data points to be logged, supply a list of the logging IDs with no
						separation. For example  to log 2033 and 2044 supply: 060320332044 . The previous list is completely replaced on call of a new set log points.
